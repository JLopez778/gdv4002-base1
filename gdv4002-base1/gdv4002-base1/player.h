#pragma once
#include "GameObject2D.h"

class player : public GameObject2D {

private:
	float playerSpeed;
	
	


public:
	player(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float initialPlayerSpeed);
	void update(double tDelta) override;

	float mass;
	glm::vec2 velocity;




};