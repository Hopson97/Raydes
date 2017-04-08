#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

#include "StateBase.h"
#include "../Level/Floor.h"
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
            Level::Floor m_floor;

            Entity::Player  m_player;
    };
}
