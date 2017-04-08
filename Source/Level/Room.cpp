#include "Room.h"

#include <iostream>

#include "LevelConstants.h"
#include "Tile/TileMap.h"

#include "../Util/Random.h"
#include "../Util/FileUtil.h"

namespace Level
{
    namespace
    {
        std::vector<Tile::MapNode> makeRoom()
        {
            std::vector<Tile::MapNode> tiles(ROOM_SIZE * ROOM_SIZE);
            auto str = getFileContents("Res/Rooms/Test.ryroom");
            str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());

            for (int x = 0; x < ROOM_SIZE; x++)
            {
                for (int y = 0; y < ROOM_SIZE; y++)
                {
                    unsigned char c = str[y * ROOM_SIZE + x];
                    tiles[y * ROOM_SIZE + x] = c - '0';
                }
            }

            return tiles;
        }

        sf::Vector2f getPosition(const sf::Vector2f& position)
        {
            return {position.x * ROOM_SIZE * TILE_SIZE + TILE_SIZE * position.x * 3,
                    position.y * ROOM_SIZE * TILE_SIZE + TILE_SIZE * position.y * 3};

        }

    }

    Room::Room(const sf::Vector2f& position)
    :   m_floorTiles (makeRoom(), ROOM_SIZE, ROOM_SIZE, getPosition(position))
    {
        auto tiles = makeRoom();

    }

    void Room::draw(Camera& camera)
    {
        m_floorTiles.draw(camera);
    }


}
