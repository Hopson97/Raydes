#include "Player.h"

#include "../Camera.h"

#include <SFML/Graphics.hpp>

namespace Entity
{
    void Mob::update(float dt)
    {
        onUpdate(dt);
    }

    Player::Player()
    {
        sprite.setSize({32, 32});
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
