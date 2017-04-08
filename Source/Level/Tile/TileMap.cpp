#include "TileMap.h"

#include <iostream>

#include "../LevelConstants.h"
#include "TileDatabase.h"
#include "../../Util/Random.h"
#include "../../Resources/ResourceHolder.h"
#include "../../Camera.h"

namespace Level
{
namespace Tile
{
    Map::Map(const std::vector<MapNode>& tileData,
             uint32_t width,
             uint32_t height,
             const sf::Vector2f& origin)
    :   m_tileData  {std::move(tileData)}
    ,   m_origin    {origin}
    ,   m_width     {width}
    ,   m_height    {height}
    {
        m_tileTextures = &ResourceHolder::get().textures.get("atlas");
        generateVertexArray();
    }

    void Map::init(const std::vector<MapNode>& tileData, uint32_t width, uint32_t height, const sf::Vector2f& origin)
    {
        m_tileData = std::move(tileData);
        m_origin   = origin;
        m_width    = width;
        m_height   = height;

        m_tileTextures = &ResourceHolder::get().textures.get("atlas");
        generateVertexArray();
    }



    void Map::draw(Camera& camera)
    {
        sf::RenderStates states;
        states.texture = m_tileTextures;

        camera.getWindow().draw(m_vertexArray.data(), m_vertexArray.size(), sf::Quads, states);
    }

    uint8_t Map::getTile(uint32_t x, uint32_t y)
    {
        return m_tileData.at(y * m_width + x).getID();
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
        setQuadVertexCoords (quad, x, y, tileType);
        setQuadTextureCoords(quad, tileType);

        //Add them into the array (in anti-clockwise order)
        m_vertexArray.push_back(quad.topLeft);
        m_vertexArray.push_back(quad.topRight);
        m_vertexArray.push_back(quad.bottomRight);
        m_vertexArray.push_back(quad.bottomLeft);
    }

    void Map::setQuadVertexCoords(Quad& quad, float x, float y, int8_t tileType)
    {
        auto dim = Database::get().getTileData(tileType).dimensions;
        auto xMod = dim.x * TILE_SIZE;
        auto yMod = dim.y * TILE_SIZE;

        //Set the vertex positions, anti-clockwise order
        quad.topLeft     .position = {x + m_origin.x + xMod,    y + m_origin.y - yMod};
        quad.topRight    .position = {x + m_origin.x,           y + m_origin.y - yMod};
        quad.bottomRight .position = {x + m_origin.x,           y + m_origin.y};
        quad.bottomLeft  .position = {x + m_origin.x + xMod,    y + m_origin.y};
    }

    void Map::setQuadTextureCoords(Quad& quad, int8_t tileType)
    {
        //Get the place inside of the texture atlas where the texture can be found
        auto texCoords = Database::get().getTileData(tileType).textureCoords;

        //Get the number of texture variations
        auto texVaritations = Tile::Database::get().getTileData(tileType).variations;
        //Choose a random variation

        int32_t varitation = 0;
        if (texVaritations > 1)
            varitation = Random::intInRange(0, texVaritations - 1);

        //Get the x and y positions inside of the texture atlas of that variation of the texture
        auto tx = texCoords.x + varitation  * TILE_TEXTURE_SIZE;
        auto ty = texCoords.y               * TILE_TEXTURE_SIZE;

        auto dim = Database::get().getTileData(tileType).dimensions;
        auto xMod = dim.x * TILE_TEXTURE_SIZE;
        auto yMod = dim.y * TILE_TEXTURE_SIZE;

        //Set texture coords of the 4 vertex points, anti-clockwise order
        quad.topLeft     .texCoords = {tx,          ty};
        quad.topRight    .texCoords = {tx + xMod,   ty};
        quad.bottomRight .texCoords = {tx + xMod,   ty + yMod};
        quad.bottomLeft  .texCoords = {tx,          ty + yMod};
    }


}
}
