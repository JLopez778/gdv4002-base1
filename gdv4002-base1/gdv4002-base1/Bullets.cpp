#include "Bullets.h"
//the constructor

Bullet::Bullet(glm::vec2 pos, float orientation, glm::vec2 size, unsigned int texture, float speed) {

}

void Bullet::shoot(float startX, float startY, float targetX, float targetY) {
	m_Shot = true;
	position.x = startX;
	position.y = startY;

	float gradient = (startX - targetX) / (startY - targetY);

	if (gradient < 0) {
		gradient *= -1;
	}

	float ratioXY = m_BulletSpeed / (1 + gradient);

	m_BulletDistanceY = ratioXY;
	m_BulletDistanceX = ratioXY * gradient;

	//point bullet in right direction

	if (targetY < startY) {
		m_BulletDistanceY *= -1;
	}

	float range = 1000;
	m_MinX = startX - range;
	m_MaxX = startX + range;
	m_MinY = startY - range;
	m_MaxY = startY + range;
}

void::Bullet::stop() {
	m_Shot = false;
}

bool Bullet::shot() {
	return m_Shot;
}





	


