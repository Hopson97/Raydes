#pragma once

#include <random>
#include <ctime>

namespace Random
{
    void init();
    int32_t intInRange (int32_t lowBound, int32_t highBound);

    template<typename RandomEngine = std::minstd_rand>
    class Generator
    {
        public:
            Generator(int64_t seed = std::time(nullptr))
            {
                m_device.seed(seed);
            }

            void setSeed(int64_t seed)
            {
                m_device.seed(seed);
            }

            int32_t intInRange (int32_t lowBound, int32_t highBound)
            {
                std::uniform_int_distribution<int32_t> dist(lowBound, highBound);
                return dist (m_device);
            }

        private:
            RandomEngine m_device;
    };
}
