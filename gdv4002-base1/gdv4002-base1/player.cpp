#include "player.h"
#include "Keys.h"
#include <bitset>
#include "engine.h"

extern std::bitset<5> keys;
extern glm::vec2 gravity;


player::player(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float mass) : GameObject2D(initPosition, initOrientation, initSize, initTextureID) {

	this->mass = mass;
	velocity = glm::vec2(0.0f, 0.0f);
}

void player::update(double tDelta) {
	glm::vec2 F = glm::vec2(0.0f, 0.0f);
	const float thrust = 2.0f;

	//accumaltive forces

	if (keys.test(key::W) == true) {

		F += glm::vec2(0.0f, thrust);
	}

	if (keys.test(key::S) == true) {

		F += glm::vec2(0.0f, -thrust);
	}
	if (keys.test(key::A) == true) {

		F += glm::vec2(-thrust, 0.0f);
	}
	if (keys.test(key::D) == true) {

		F += glm::vec2(thrust, 0.0f);
	}
	F += gravity;

	//add impulse force
	if (position.y < -getViewplaneHeight() / 2.0f) {
		F += glm::vec2(0.0f, 10.0f);
	}



	glm::vec2 a = F * (1.0f / mass);

	velocity = velocity + (a * (float)tDelta);

	position = position + (velocity * (float)tDelta);


	float vw = getViewplaneWidth() / 2.0f;
	float vh = getViewplaneHeight() / 2.0f;

	if (position.x < -vw) {

		position.x = vw;
		
	}

	else if (position.x > vw) {
		position.x = -vw;
		
	}

	if (position.y < -vh) {
		position.y = vh;
		
	}

	else if (position.y > vh) {
		position.y = -vh;
		
	}

}
	/*if Player.position < vw; {
	Player.position = vw * 4);
}
	else if Player.position < vh{
		Player.position = vw * 4);
		}*/







