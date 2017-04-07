#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "States/StateBase.h"

class Application
{
    public:
        Application();

        void runMainLoop();


    private:
        void handleEvents();

        std::vector<std::unique_ptr<State::SBase>> m_states;

        sf::RenderWindow m_window;
};
