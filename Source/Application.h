#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "States/StateBase.h"
#include "Camera.h"

class Application
{
    struct Push
    {
        std::unique_ptr<State::SBase> state;
    };

    enum class StateSwitch
    {
        None,
        Pop,
        Push
    };

    public:
        Application();

        void runMainLoop();

        void pushState(std::unique_ptr<State::SBase> state);
        void popState();

    private:
        void handleEvents();
        void checkStateChange();

        std::vector<std::unique_ptr<State::SBase>> m_states;
        std::unique_ptr<State::SBase> m_nextState;

        sf::RenderWindow m_window;
        StateSwitch m_stateSwitch = StateSwitch::None;

        Camera m_camera;


};
