#include "Floor.h"

namespace Level
{
    Floor::Floor()
    {
        for (float x = 0; x < 4; x++)
        {
            for (float y = 0; y < 4; y++)
            {
                m_rooms.insert(std::make_pair(sf::Vector2f{x, y},
                                              sf::Vector2f{x, y}));
            }
        }

    }

    void Floor::update(float dt, const Entity::Player& player)
    {

    }

    void Floor::drawFloor(Camera& camera)
    {
        for (auto& room : m_rooms)
        {
            room.second.drawFloor(camera);
        }
    }

    void Floor::drawWalls(Camera& camera)
    {
		for (auto& room : m_rooms)
		{
			room.second.drawWalls(camera);
		}
    }
}
