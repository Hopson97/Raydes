#include "Room.h"

#include "LevelConstants.h"
#include "Tile/TileMap.h"

namespace Level
{
    namespace
    {
        std::vector<Tile::MapNode> makeRoom()
        {
            std::vector<Tile::MapNode> tiles;
            for (int i = 0; i < ROOM_SIZE * ROOM_SIZE; i++)
            {
                tiles.push_back(0);
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
    :   m_tileMap (makeRoom(), ROOM_SIZE, ROOM_SIZE, getPosition(position))
    {

    }

    void Room::draw(Camera& camera)
    {
        m_tileMap.draw(camera);
    }


}
