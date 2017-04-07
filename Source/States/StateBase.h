#pragma once

#include <SFML/System/NonCopyable.hpp>

class Application;

namespace sf
{
    //Forward delcare SFML stuff
    class RenderWindow;
    class Event;
}

namespace State
{
    class SBase : public sf::NonCopyable
    {
        public:
            SBase(Application* app)
            :   m_pApplication  (app)
            { }

            virtual ~SBase() = default;

            virtual void event  (sf::Event& event)  = 0;
            virtual void input  ()                  = 0;
            virtual void update ()                  = 0;
            virtual void render (sf::RenderWindow&) = 0;

        protected:
            Application* m_pApplication;
    };
}


