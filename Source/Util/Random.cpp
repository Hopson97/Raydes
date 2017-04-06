#include "Random.h"

namespace Random
{
    namespace
    {
        std::minstd_rand rd;
    }

    void init()
    {
        rd.seed(std::time(nullptr));
    }

    int32_t intInRange(int32_t lowBound, int32_t highBound)
    {
        std::uniform_int_distribution<int32_t> dist(lowBound, highBound);
        return dist (rd);
    }

    float floatInRange(float lowBound, float highBound)
    {
        std::uniform_real_distribution<float> dist(lowBound, highBound);
        return dist (rd);
    }

}
