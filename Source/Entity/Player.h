#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"

namespace Entity
{
    struct Player
    {
        Player();

        sf::RectangleShape sprite;
    };
}
