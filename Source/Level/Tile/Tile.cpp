#include "Tile.h"

#include "../../Lib/json.hpp"

namespace Level
{
namespace Tile
{
    using Json = nlohmann::json;

    Type::Type(std::string&& name)
    {
        auto fileName = "Res/Tiles/" + std::move(name) + ".json";
        Json file = Json::parse(std::move(fileName));

        m_data.id           = (ID)  file["ID"]  .get<int32_t>();
        m_data.variations   =       file["Var"] .get<int32_t>();

        auto texCoords = file["Texture"].get<std::vector<uint32_t>>();
        m_data.textureCoords.x = texCoords[0];
        m_data.textureCoords.y = texCoords[1];
    }

    const Data& Type::getData() const
    {
        return m_data;
    }
}
}
