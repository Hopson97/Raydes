#pragma once

#include <vector>

#include "Tile.h"

namespace Level
{
namespace Tile
{
    class Database
    {
        public:
            static Database& get();

            Database();

            const Data& getTileData(ID id) const;

            const Data& getTileData(uint8_t id) const;

        private:
            void registerTile(ID id, std::string&& name);

            std::vector<Type> m_tiles;
    };


}
}
