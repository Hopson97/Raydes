#include "Player.h"

#include "../Camera.h"

#include <SFML/Graphics.hpp>

#include "../Maths/VectorMath.h"

namespace Entity
{
    void Mob::update(float dt)
    {
        position += velocity * dt;
        onUpdate(dt);
        velocity *= 0.98f * (dt * 60);
    }

    Player::Player()
    {
        sprite.setSize({32, 32});
    }

    void Player::input()
    {
        float speed = 125;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            velocity.y -= speed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            velocity.x -= speed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            velocity.y += speed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            velocity.x += speed;
        }
    }


    void Player::onUpdate(float dt)
    {
        sprite.setPosition(position);
    }

    void Player::draw(Camera& camera)
    {
        camera.draw(sprite);
    }

}
