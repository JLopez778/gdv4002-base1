#pragma once
using namespace std;
#include "Engine.h"
#include "GameObject2D.h"
class Bullet : public GameObject2D
{

private:
	//bullet location
	//glm::vec2 m_position;

	
	
	//Has the bullet been shot?
	bool m_Shot = false;

	float m_BulletSpeed = 1000;

	float m_BulletDistanceX;
	float m_BulletDistanceY;


	float m_MaxX;
	float m_MinX;
	float m_MaxY;
	float m_MinY;

	GLuint bulletTexture = loadTexture("Resources\\Textures\\bullet.png");

	

public:
	Bullet(glm::vec2 pos, float orientation, glm::vec2 size, unsigned int texture, float speed);

	void stop();

	void shoot(float startX, float startY, float xTarget, float yTarget);

	bool shot();

	//GameObject2D getPosition();

	void update(float elapsedTime) {
		position.x += m_BulletDistanceX * elapsedTime;
		position.y += m_BulletDistanceY  * elapsedTime;

		if (position.x < m_MinX || position.x > m_MaxX ||
			position.y < m_MinY || position.y > m_MaxY)
		{
			m_Shot= false;
			}
	}


};

