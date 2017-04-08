#include "Camera.h"

#include "Entity/Player.h"


Camera::Camera(sf::RenderWindow& window)
:   m_view      ({0, 0, 1280, 720})
,   m_pWindow   (&window)
{
    m_view.zoom(1.1f);
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

	m_bounds.left	= m_view.getCenter().x - m_pWindow->getSize().x / 2;
	m_bounds.top	= m_view.getCenter().y - m_pWindow->getSize().y / 2;
	m_bounds.width	= m_pWindow->getSize().x / 2;
	m_bounds.height = m_pWindow->getSize().y / 2;

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

bool Camera::inBounds(sf::FloatRect& rect)
{
	return rect.intersects(m_bounds);
}
