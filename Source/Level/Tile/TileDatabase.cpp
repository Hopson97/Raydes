#include "TileDatabase.h"

namespace Level
{
namespace Tile
{
    Database& Database::get()
    {
        static Database database;
        return database;
    }

    Database::Database()
    :   m_tiles ((uint16_t)ID::COUNT)
    {
        registerTile(ID::GreyStone,     "GreyStone");
        registerTile(ID::GreyStoneWall, "GreyStoneWall");
    }

    void Database::registerTile(ID id, std::string&& name)
    {
        m_tiles[(int)id] = Type(std::move(name));
    }

    const Data& Database::getTileData(ID id) const
    {
        return m_tiles[uint16_t(id)].getData();
    }

    const Data& Database::getTileData(uint8_t id) const
    {
        return m_tiles[id].getData();
    }
}
}
