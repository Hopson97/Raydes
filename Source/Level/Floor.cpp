#include "Floor.h"

namespace Level
{
    Floor::Floor()
    {
        for (float x = 0; x < 10; x++)
        {
            for (float y = 0; y < 10; y++)
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
            room.second.draw(camera);
        }
    }

    void Floor::drawWalls(Camera& camera)
    {

    }
}
