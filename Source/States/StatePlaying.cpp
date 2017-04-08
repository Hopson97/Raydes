#include "StatePlaying.h"

#include "../Camera.h"

namespace State
{
    SPlaying::SPlaying(Application* app, Camera& camera)
    :   SBase{app}
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
        m_floor.update(dt, m_player);
    }

    void SPlaying::render(Camera& camera)
    {
        m_floor     .drawFloor(camera);
        m_player    .draw(camera);
        m_floor     .drawWalls(camera);
    }
}
