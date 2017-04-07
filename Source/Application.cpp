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

