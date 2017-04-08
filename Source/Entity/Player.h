#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"


class Camera;

namespace Entity
{
	class Mob
    {
		public:
			sf::Vector2f position;
			sf::Vector2f velocity;
			void update(float dt);

        private:
            virtual void onUpdate(float dt) = 0;
    };

    class Player : public Mob
    {
		public:
			Player();
			void input();
			void onUpdate(float dt);
			void draw(Camera& camera);

			sf::RectangleShape sprite;
    };
}
