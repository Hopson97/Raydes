#include "Application.h"

#include "States/StatePlaying.h"

Application::Application()
:   m_window    ({1280, 720}, "Raydes")
{
    m_states.push_back(std::make_unique<State::SPlaying>(this));
}

void Application::runMainLoop()
{
    while (m_window.isOpen())
    {
        handleEvents();
        m_window.clear();

        m_states.back()->input();
        m_states.back()->update();
        m_states.back()->render();

        m_window.display();
        checkStateChange();
    }
}

void Application::handleEvents()
{
    sf::Event e;
    while (m_window.pollEvent(e))
    {
        m_states.back()->event(e);

        switch (e.type)
        {
            case sf::Event::Closed:
                m_window.close();
                break;

            default:
                break;
        }
    }
}

void Application::pushState(std::unique_ptr<State::SBase> state)
{
    m_nextState = std::move(state);
}

void Application::popState()
{
    m_stateSwitch = StateSwitch::Pop;
}


void Application::checkStateChange()
{
    switch(m_stateSwitch)
    {
        case StateSwitch::None:
            break;

        case StateSwitch::Pop:
            m_states.pop_back();
            break;

        case StateSwitch::Push:
            m_states.push_back(std::move(m_nextState));
            break;

    }
    m_stateSwitch = StateSwitch::None;
}


