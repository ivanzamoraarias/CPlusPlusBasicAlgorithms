#include <iostream>
using namespace std;



class LinearRandomNumbers
{
private:
    int m;
    int a;
    int c;
    int Xo;


public:
    LinearRandomNumbers(
        int Modulus, 
        int Multiplier, 
        int Increment, 
        int StartingValue
    );
    ~LinearRandomNumbers();

    // Las Vegas method for generating random integer numbers
    int GetRandomInteger(
        int LowerBound, 
        int UpperBound
    );
    

private:
    int GetRandom();
    int GetLinearRandom();
    int GetModuloSum(
        int x , 
        int y, 
        int m
    );
};

LinearRandomNumbers::LinearRandomNumbers(    
        int Modulus, 
        int Multiplier, 
        int Increment, 
        int StartingValue
    )
{
     m = Modulus;
     a = Multiplier;
     c = Increment;
     Xo = StartingValue;

}

LinearRandomNumbers::~LinearRandomNumbers()
{
}

int LinearRandomNumbers::GetRandomInteger(
    int LowerBound, 
    int UpperBound
)
{
    int w = UpperBound - LowerBound;
    int r;

    do{
        r = GetLinearRandom() / (m / w);
    }while(r < w);

    r = r + LowerBound;
    
    return r;
}

int LinearRandomNumbers::GetRandom()
{
    int x = Xo;
    int r = (a * x) % m;
    
    r = GetModuloSum(r, c, m);
    x = r;

    return x;
}

int LinearRandomNumbers::GetLinearRandom()
{
    int x = Xo;
    int q = m / a;
    int p = m % a;
    int r = a * (x % q) - p*(x/q);

    if( r < 0 )
        r = r + m;

     r = GetModuloSum(r, c, m);
     x = r;

     return r;
}

int LinearRandomNumbers::GetModuloSum(
    int x, 
    int y, 
    int m
)
{
    if(x <= (m-1-y))
    {
        return x + y;
    }

    return x - (m - y);

}


int main()
{
    LinearRandomNumbers* LinearRand = 
        new LinearRandomNumbers(
            10,
            8, 
            7,
            9
        );

    LinearRand->GetRandomInteger(5, 13);

    free(LinearRand);
}