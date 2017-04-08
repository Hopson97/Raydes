#pragma once

#include <unordered_map>

#include "Room.h"
#include "../Camera.h"

namespace Entity
{
    class Player;
}

namespace std
{
    template<>
    struct hash<sf::Vector2f>
    {
        size_t operator()(const sf::Vector2f& vect) const
        {
            std::hash<float> hasher;
            auto h1 = hasher(vect.x);
            auto h2 = hasher(vect.y);
            return hasher(h1 ^ h2 >> 1);
        }
    };
}

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

            void update(float dt, const Entity::Player& player);

            void drawFloor(Camera& camera);
            void drawWalls(Camera& camera);

        private:
            std::unordered_map<sf::Vector2f, Room> m_rooms;

    };
}
