#pragma once

#include "Tile/TileMap.h"

class Camera;

namespace Level
{
    enum class RoomType
    {
        Start,
        Boss,
        Puzze,
        Guardian,
        None,
    };

    struct RoomInfo
    {
        RoomType type;
        bool cleared;
    };

    class Room
    {
        public:
            Room(const sf::Vector2f& position);

            void draw(Camera& camera);


        private:
            Tile::Map m_tileMap;

            RoomInfo m_info;
    };
}
