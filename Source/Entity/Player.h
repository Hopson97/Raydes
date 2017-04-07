#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"

class Camera;

namespace Entity
{
    struct Mob
    {
        sf::Vector2f position;
        virtual void update(){}
    };

    struct Player : public Mob
    {
        Player();
        void update();
        void draw(Camera& camera);

        sf::RectangleShape sprite;
    };
}
