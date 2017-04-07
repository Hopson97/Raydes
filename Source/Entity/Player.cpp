#include "Player.h"

#include "../Camera.h"

#include <SFML/Graphics.hpp>

namespace Entity
{
    Player::Player()
    {
        sprite.setSize({200, 200});
    }

    void Player::update()
    {
        sprite.setPosition(position);
    }

    void Player::draw(Camera& camera)
    {
        camera.draw(sprite);
    }

}
