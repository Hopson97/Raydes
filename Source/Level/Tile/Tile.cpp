#include "Tile.h"

#include <fstream>

namespace Level
{
namespace Tile
{
    //using json = nlohmann::json;

    Type::Type(std::string&& name)
    {
        auto fileName = "Res/Tiles/" + std::move(name) + ".tile";

        /*
        json file = json::parse(fileName);

        m_data.id           = (ID)  file["ID"]  .get<int32_t>();
        m_data.variations   =       file["Var"] .get<int32_t>();

        auto texCoords = file["Texture"].get<std::vector<uint32_t>>();
        m_data.textureCoords.x = texCoords[0];
        m_data.textureCoords.y = texCoords[1];
        */

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
        }
    }

    const Data& Type::getData() const
    {
        return m_data;
    }
}
}
