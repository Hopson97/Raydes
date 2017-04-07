#pragma once

namespace Level
{
    enum class RoomType
    {
        Start,
        Boss,
        Puzze,
        Guardian,
        None,
    };

    struct RoomInfo
    {
        RoomType type;
        bool cleared;
    };

    class Room
    {
        public:


        private:
            RoomInfo m_info;
    };
}
