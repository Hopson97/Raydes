#pragma once

#include <vector>

#include "Room.h"

namespace Level
{
    enum class DungeonSize
    {
        Small = 4,
        Medium = 6,
        Large = 8
    };

    class Floor
    {
        public:
            Floor();

        private:
            std::vector<Room> m_rooms;

    };
}
