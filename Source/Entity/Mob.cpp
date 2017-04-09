#include "Mob.h"

namespace Entity
{
	void Mob::update(float dt)
	{
		position += velocity * dt;
		onUpdate(dt);
		velocity *= 0.95f;
	}
	void Mob::setRoom(const Level::Room & room)
	{
		m_pRoom = &room;
	}
}