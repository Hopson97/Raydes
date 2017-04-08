#include "Room.h"

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

		std::vector<Tile::MapNode> extractWalls(const std::vector<Tile::MapNode>& original)
		{
			std::vector<Tile::MapNode> tiles;
			for (auto& tile : original)
			{
				if (tile.getData().type == Tile::Data::Type::Wall)
					tiles.push_back(tile);
				else
					tiles.push_back(-1);
			}
			return tiles;
		}

		std::vector<Tile::MapNode> extractFloors(const std::vector<Tile::MapNode>& original)
		{
			std::vector<Tile::MapNode> tiles;
			for (auto& tile : original)
			{
				if (tile.getData().type == Tile::Data::Type::Floor)
					tiles.push_back(tile);
				else
					tiles.push_back(-1);
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
    {	
        auto tiles = makeRoom();

		m_floorTiles.init(extractFloors(tiles), ROOM_SIZE, ROOM_SIZE, getPosition(position));
		m_wallTiles	.init(extractWalls (tiles), ROOM_SIZE, ROOM_SIZE, getPosition(position));
    }

	void Room::drawWalls(Camera & camera)
	{
		m_wallTiles.draw(camera);
	}

    void Room::drawFloor(Camera& camera)
    {
        m_floorTiles.draw(camera);
    }




}
