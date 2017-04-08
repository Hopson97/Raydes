#pragma once

#include <SFML/Graphics/View.hpp>

namespace Entity
{
    struct Mob;
}

namespace sf
{
    class Drawable;
    class RenderWindow;
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
