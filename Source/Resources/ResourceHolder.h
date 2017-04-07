#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ResourceManager.h"

struct ResourceHolder
{
    static ResourceHolder& get()
    {
        static ResourceHolder holder;
        return holder;
    }

    ResourceHolder()
    :   textures        ("Res/Textures/",   ".png")
    ,   fonts           ("Res/Fonts/",      ".ttf")
    ,   soundBuffers    ("Res/Sound/",      ".ogg")
    {}

    ResourceManager<sf::Texture>       textures;
    ResourceManager<sf::Font>          fonts;
    ResourceManager<sf::SoundBuffer>   soundBuffers;
};


