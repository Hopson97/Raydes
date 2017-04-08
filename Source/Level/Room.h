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

			void drawWalls(Camera& camera);
			void drawFloor(Camera& camera);


        private:
            Tile::Map m_floorTiles;
            Tile::Map m_wallTiles;

            RoomInfo m_info;
    };
}
