#pragma once

#include <SFML/Graphics.hpp>
#include <cstdint>

namespace Level
{
namespace Tile
{
    enum class ID
    {
        GreyStone = 0,

        COUNT
    };

    struct Data
    {
        ID id;
        sf::Vector2f textureCoords;
        uint8_t variations;
    };

    struct Type
    {
        public:
            Type() = default;
            Type(std::string&& name);

            const Data& getData() const;

        private:
            Data m_data;
    };
}
}
