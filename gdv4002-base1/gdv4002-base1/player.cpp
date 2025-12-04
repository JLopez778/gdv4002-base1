#include "player.h"
#include "Keys.h"
#include <bitset>

extern std::bitset<5> keys;


player:: player(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float initialPlayerSpeed) : GameObject2D(initPosition, initOrientation, initSize, initTextureID) {

	playerSpeed = initialPlayerSpeed;
}

void player::update(double tDelta) {


if (keys.test(key::W) == true) {

	position.y += playerSpeed * (float)tDelta;
}
if (keys.test(key::S) == true) {

	position.y -= playerSpeed * (float)tDelta;
}
if (keys.test(key::A) == true) {

	position.x -= playerSpeed * (float)tDelta;
}
if (keys.test(key::D) == true) {

	position.x += playerSpeed * (float)tDelta;
}
}


