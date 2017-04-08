#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Tile.h"

class Camera;

namespace Level
{
namespace Tile
{
    class Map
    {
        //Each tile of the tile map = one quad
        //A quad has four vertex points, as marked by the vertex names
        struct Quad
        {
            sf::Vertex topLeft;
            sf::Vertex topRight;
            sf::Vertex bottomLeft;
            sf::Vertex bottomRight;
        };

        public:
            Map() = default;
            Map(const std::vector<uint8_t>& tileData, uint32_t width, uint32_t height);
            void draw(Camera& camera);

        private:
            uint8_t getTile(uint32_t x, uint32_t y);

            void generateVertexArray();

            void addTile                (float x, float y, int8_t tileType);
            void setQuadVertexCoords    (Quad& quad, float x, float y);
            void setQuadTextureCoords   (Quad& quad, int8_t tileType);

            std::vector<uint8_t>      m_tileData; //1 byte per tile
            std::vector<sf::Vertex> m_vertexArray;

            uint32_t m_width  = 0;
            uint32_t m_height = 0;

            const sf::Texture* m_tileTextures;
};
}
}
