#pragma once

#include <SFML/Graphics.hpp>

#include "Mob.h"

class Camera;

namespace Entity
{
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
