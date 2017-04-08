#pragma once

#include <SFML/Graphics.hpp>
#include <cstdint>

namespace Level
{
namespace Tile
{
    enum class ID
    {
        GreyStone   = 0,

        COUNT
    };

    struct Data
    {
        enum Type
        {
            Wall,
            Floor
        };

        ID id;
        Type type;
        sf::Vector2f textureCoords;
        sf::Vector2f dimensions;
        uint32_t variations;

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
