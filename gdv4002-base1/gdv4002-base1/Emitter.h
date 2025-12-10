#pragma once

#include "GameObject2D.h"
#include <random>
using namespace std;
class Emitter
{
private:
	float emitTimeInterval;
	float emitCounter;

	unsigned long long particleNumber;

	GLuint particles[8];

	mt19937 gen;

	std::uniform_int_distribution<int> spriteDist; // random integer for particle sprite selection
	std::uniform_real_distribution<float> normDist; // -1 to 1
	std::uniform_real_distribution<float> massDist, scaleDist;

public:

	Emitter(glm::vec2 initPosition, glm::vec2 initSize, float emitTimeInterval);



};





