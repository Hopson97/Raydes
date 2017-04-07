#pragma once

#include <vector>

namespace Level
{
    enum class DungeonSize
    {
        Small = 4,
        Medium = 6,
        Large = 8
    };

    class Room
    {

    };

    class Floor
    {
        public:
            Floor();

        private:
            std::vector<Room> m_rooms;

    };
}
