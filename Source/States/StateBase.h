#pragma once

#include <SFML/System/NonCopyable.hpp>

class Application;
class Camera;

namespace sf
{
    //Forward delcare SFML stuff
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
            virtual void update (float dt)          = 0;
            virtual void render (Camera& camera)    = 0;

        protected:
            Application* m_pApplication;
    };
}


