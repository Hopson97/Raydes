#pragma once

#include <SFML/Graphics.hpp>

#include "StateBase.h"

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
    };
}
