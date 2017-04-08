#include "Camera.h"

#include "Entity/Player.h"


Camera::Camera(sf::RenderWindow& window)
:   m_view      ({0, 0, 1280, 720})
,   m_pWindow   (&window)
{
}

void Camera::hookMob(Entity::Mob& mob)
{
    m_pMob = &mob;
}

void Camera::update()
{
    if (m_pMob)
    {
        m_view.setCenter(m_pMob->position);
    }
    m_pWindow->setView(m_view);
}

void Camera::draw(sf::Drawable& drawable)
{
    m_pWindow->draw(drawable);
}

sf::RenderWindow& Camera::getWindow()
{
    return *m_pWindow;
}
