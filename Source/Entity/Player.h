#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"


class Camera;

namespace Entity
{
    struct Mob
    {
        sf::Vector2f position;
        sf::Vector2f velocity;
        void update(float dt);

        private:
            virtual void onUpdate(float dt) = 0;
    };

    struct Player : public Mob
    {
        Player();
        void input();
        void onUpdate(float dt);
        void draw(Camera& camera);

        sf::RectangleShape sprite;
    };
}
