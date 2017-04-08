#pragma once

#include <SFML/Graphics.hpp>

#include "StateBase.h"
#include "../Level/Room.h"
#include "../Entity/Player.h"

namespace State
{
    class SPlaying : public SBase
    {
        public:
            SPlaying(Application* app, Camera& camera);

            void event  (sf::Event& event)  override;
            void input  ()                  override;
            void update (float dt)          override;
            void render (Camera& camera)    override;

        private:
            Entity::Player  m_player;
            Level::Room     m_room;


    };
}
