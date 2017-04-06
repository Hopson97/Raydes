#pragma once

class Application;

namespace sf
{
    //Forward delcare SFML stuff
    class RenderWindow;
    class Event;
}

namespace State
{
    class SBase
    {
        public:
            SBase(Application* app)
            :   m_pApplication  (app)
            { }

            virtual ~SBase() = default;

            SBase(SBase& other) = delete;
            SBase& operator= (SBase& other) = delete;

            virtual void event  (sf::Event& event)  = 0;
            virtual void input  ()                  = 0;
            virtual void update ()                  = 0;
            virtual void render ()                  = 0;

        protected:
            Application* m_pApplication;
    };
}


