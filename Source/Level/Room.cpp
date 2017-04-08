#include "Room.h"

#include "LevelConstants.h"

namespace Level
{
    std::vector<uint8_t> makeRoom()
    {
        std::vector<uint8_t> tiles;
        for (int i = 0; i < ROOM_SIZE * ROOM_SIZE; i++)
        {
            tiles.push_back(0);
        }
        return tiles;
    }

    Room::Room()
    :   m_tileMap (makeRoom(), ROOM_SIZE, ROOM_SIZE)
    {

    }

    void Room::draw(Camera& camera)
    {
        m_tileMap.draw(camera);
    }


}
