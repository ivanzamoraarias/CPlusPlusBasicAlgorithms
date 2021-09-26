#include <vector>
#include <math.h> 
#include <algorithm>

class RandomNoiseIv
{
public:
    int RESERVE_SEQUENCE_MEMORY_SIZE = 200;
private:
    /* data */
public:
    RandomNoiseIv(/* args */);
    ~RandomNoiseIv();

private:
    int GetMortonInterval(std::vector<int>& Sequence, int EffectiveBits);
    int GetBitsRequired(int n);
};

RandomNoiseIv::RandomNoiseIv(/* args */)
{
}

RandomNoiseIv::~RandomNoiseIv()
{
}

int RandomNoiseIv::GetMortonInterval(
    std::vector<int>& Sequence, 
    int EffectiveBits
)
{
    int b = EffectiveBits;
    int m = 1;
    std::vector<int> BitSequence(
        RESERVE_SEQUENCE_MEMORY_SIZE
    );

    for (
        int i = 0; 
        i < RESERVE_SEQUENCE_MEMORY_SIZE; 
        i++
    )
    {
        BitSequence.push_back(i);
    }
     if(b == 0)
     {
         int MaxInZ = *std::max_element(
                Sequence.begin(), 
                Sequence.end()
            ); 

        int MinInZ = *std::min_element(
                Sequence.begin(), 
                Sequence.end()
            );
         b = std::max(
                MinInZ, 
                MaxInZ
            );

     }

}

int RandomNoiseIv::GetBitsRequired(int n)
{
    int ResultingN;

    if(n == 0)
        return 1;
    if(n < 0)
        ResultingN = -n;

    return 1 + log(ResultingN-1);
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

