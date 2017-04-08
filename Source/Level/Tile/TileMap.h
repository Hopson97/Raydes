#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Tile.h"
#include "TileDatabase.h"

class Camera;

namespace Level
{
namespace Tile
{
    class MapNode
    {
        public:
            MapNode() = default;

            MapNode(Tile::ID id)
            :   m_id    ((int8_t) id)
            { }

            MapNode(uint8_t id)
            :   m_id    (id)
            { }

            uint8_t getID()
            {
                return m_id;
            }

            MapNode& operator =(uint8_t id)
            {
                m_id = id;
                return *this;
            }

			const Data& getData() const 
			{
				return Database::get().getTileData(m_id);
			}

        private:
            uint8_t m_id;
    };

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
            Map(const std::vector<MapNode>& tileData,
                uint32_t width,
                uint32_t height,
                const sf::Vector2f& origin);

            void init(const std::vector<MapNode>& tileData,
                      uint32_t width,
                      uint32_t height,
                      const sf::Vector2f& origin);

            void draw(Camera& camera);

        private:
            uint8_t getTile(uint32_t x, uint32_t y);

            void generateVertexArray();

            void addTile                (float x, float y, int8_t tileType);
            void setQuadVertexCoords    (Quad& quad, float x, float y, int8_t tileType);
            void setQuadTextureCoords   (Quad& quad, int8_t tileType);

            std::vector<MapNode>      m_tileData; //1 byte per tile
            std::vector<sf::Vertex> m_vertexArray;

            sf::Vector2f m_origin;

            uint32_t m_width  = 0;
            uint32_t m_height = 0;

            const sf::Texture* m_tileTextures;
};
}
}
