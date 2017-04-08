#pragma once

#include <SFML/Graphics.hpp>

namespace Entity
{
    class Mob;
}

namespace sf
{
    class Drawable;
}

class Camera
{
    public:
        Camera(sf::RenderWindow& window);

        void hookMob(Entity::Mob& mob);

        void update();

        void draw(sf::Drawable& drawable);

        sf::RenderWindow& getWindow();

    private:
        sf::View m_view;

        Entity::Mob* m_pMob = nullptr;
        sf::RenderWindow* m_pWindow = nullptr;
};
