#include "TileMap.h"

#include "../LevelConstants.h"
#include "TileDatabase.h"
#include "../../Util/Random.h"
#include "../../Resources/ResourceHolder.h"

namespace Level
{
namespace Tile
{
    std::vector<uint8_t> tilesd()
    {
        std::vector<uint8_t> res;
        for (int i = 0; i < 20 * 20; i++)
        {
            res.push_back(0);
        }
        return res;
    }


    Map::Map()
    :   m_tileData  (tilesd())
    ,   m_width     (20)
    ,   m_height    (20)
    {
        m_tileTextures = &ResourceHolder::get().textures.get("atlas");
        generateVertexArray();
    }

    Map::Map(const std::vector<uint8_t>& tileData,
                     uint32_t width,
                     uint32_t height)
    :   m_tileData  (tileData)
    ,   m_width     (width)
    ,   m_height    (height)
    {
        m_tileTextures = &ResourceHolder::get().textures.get("atlas");
        generateVertexArray();
    }

    void Map::draw(sf::RenderWindow& window)
    {
		generateVertexArray();

        sf::RenderStates states;
        states.texture = m_tileTextures;

        window.draw(m_vertexArray.data(), m_vertexArray.size(), sf::Quads, states);
    }

    uint8_t Map::getTile(uint32_t x, uint32_t y)
    {
        return m_tileData.at(y * m_width + x);
    }

    void Map::generateVertexArray()
    {
        m_vertexArray.reserve(m_width * m_height * 4);
        for (uint32_t y = 0; y < m_height; ++y)
        {
            for (uint32_t x = 0; x < m_width; ++x)
            {
                addTile(x * TILE_SIZE, y * TILE_SIZE, getTile(x, y));
            }
        }
    }

    void Map::addTile(float x, float y, int8_t tileType)
    {
        Quad quad;

        //Set the positions of the 4 verticies of the quad
        setQuadVertexCoords (quad, x, y);
        setQuadTextureCoords(quad, tileType);

        //Add them into the array (in anti-clockwise order)
        m_vertexArray.push_back(quad.topLeft);
        m_vertexArray.push_back(quad.topRight);
        m_vertexArray.push_back(quad.bottomRight);
        m_vertexArray.push_back(quad.bottomLeft);
    }

    void Map::setQuadVertexCoords(Quad& quad, float x, float y)
    {
        //Set the vertex positions, anti-clockwise order
        quad.topLeft     .position = {x,              y};
        quad.topRight    .position = {x + TILE_SIZE,  y};
        quad.bottomRight .position = {x + TILE_SIZE,  y + TILE_SIZE};
        quad.bottomLeft  .position = {x,              y + TILE_SIZE};
    }

    void Map::setQuadTextureCoords(Quad& quad, int8_t tileType)
    {
        //Get the place inside of the texture atlas where the texture can be found
        auto texCoords = Database::get().getTileData(tileType).textureCoords;

        //Get the number of texture variations
        auto texVaritations = Tile::Database::get().getTileData(tileType).variations;
        //Choose a random variation

        int32_t varitation = 0;
        if (varitation > texVaritations)
            varitation = Random::intInRange(0, texVaritations - 1);

        //Get the x and y positions inside of the texture atlas of that variation of the texture
        auto tx = texCoords.x + varitation * TILE_TEXTURE_SIZE;
        auto ty = texCoords.y * TILE_TEXTURE_SIZE;

        //Set texture coords of the 4 vertex points, anti-clockwise order
        quad.topLeft     .texCoords = {tx,                      ty};
        quad.topRight    .texCoords = {tx + TILE_TEXTURE_SIZE,  ty};
        quad.bottomRight .texCoords = {tx + TILE_TEXTURE_SIZE,  ty + TILE_TEXTURE_SIZE};
        quad.bottomLeft  .texCoords = {tx,                      ty + TILE_TEXTURE_SIZE};
    }


}
}
