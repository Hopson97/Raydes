#include "Tile.h"

#include <fstream>
#include <iostream>

namespace Level
{
namespace Tile
{
    Type::Type(std::string&& name)
    {
        auto fileName = "Res/Tiles/" + std::move(name) + ".tile";

        std::ifstream inFile (fileName);
        if (!inFile.is_open())
        {
            //error
        }

        std::string line;
        while (std::getline(inFile, line))
        {
            if (line == "ID")
            {
                int32_t i;
                inFile >> i;
                m_data.id = (ID)i;
            }
            else if (line == "Var")
            {
                inFile >> m_data.variations;
            }
            else if (line == "Texture")
            {
                inFile >> m_data.textureCoords.x >> m_data.textureCoords.y;
            }
            else if (line == "Dim")
            {
                inFile >> m_data.dimensions.x >> m_data.dimensions.y;
            }
            else if (line == "type")
            {
                int32_t i;
                inFile >> i;
                m_data.type = (Data::Type)i;
            }
        }
    }

    const Data& Type::getData() const
    {
        return m_data;
    }
}
}
