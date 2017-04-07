#pragma once

#include <SFML/Graphics.hpp>

#include "StateBase.h"

#include "../Level/Floor.h"

namespace State
{
    class SPlaying : public SBase
    {
        public:
            SPlaying(Application* app);

            void event  (sf::Event& event)  override;
            void input  ()                  override;
            void update ()                  override;
            void render ()                  override;

        private:
            Level::Floor m_floor;
    };
}
