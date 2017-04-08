#include "StatePlaying.h"

#include "../Camera.h"

namespace State
{
    SPlaying::SPlaying(Application* app, Camera& camera)
    :   SBase(app)
    {
        camera.hookMob(m_player);
    }

    void SPlaying::event(sf::Event& event)
    {
    }

    void SPlaying::input()
    {
        m_player.input();
    }

    void SPlaying::update(float dt)
    {
        m_player.update(dt);
    }

    void SPlaying::render(Camera& camera)
    {
        m_room.draw(camera);

        m_player.draw(camera);
    }
}
