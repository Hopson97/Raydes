#pragma once

#include <SFML/Graphics.hpp>

namespace Level
{
	class Room;
}

namespace Entity 
{
	class Mob
	{
		public:
			sf::Vector2f position;
			sf::Vector2f velocity;
			void update(float dt);
			void setRoom(const Level::Room& room);

		private:
			virtual void onUpdate(float dt) = 0;
			const Level::Room* m_pRoom = nullptr;
	};
}