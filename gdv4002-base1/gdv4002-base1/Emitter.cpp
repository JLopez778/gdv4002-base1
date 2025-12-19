#include "Emitter.h"
#include "GameObject2D.h"
#include <random>
#include "engine.h"
#include "Particles.h"
using namespace std;

Emitter::Emitter(glm::vec2 initPosition, glm::vec2 initSize, float emitTimeInterval) : GameObject2D(initPosition, 0.0f, initSize, 0) {


	this->emitTimeInterval = emitTimeInterval;
	emitCounter = emitTimeInterval;
	particleNumber = 0;

	for (int i = 0; i < 8; i++) {
		string path = "Resources\\Textures\\asteroid" + to_string(i + 1) + string(".jpeg");
		particleTexture[i] = loadTexture(path.c_str());

		if (particleTexture[i] > 0)
			cout << "successfully loaded texture " << path << endl;
		else
			cout << "failed to load texture " << path << endl;


	}

	//int random_device;
	random_device rd;
	gen = mt19937(rd());
	spriteDist = uniform_int_distribution<int>(0, 7);
	normDist = uniform_real_distribution<float>(-1.0f, 1.0f);
	massDist = uniform_real_distribution<float>(0.005f, 0.08f);
	scaleDist = uniform_real_distribution<float>(0.1f, 0.5f);

}


void Emitter::update(double tDelta) {
	emitCounter += (float)tDelta;

	while (emitCounter >= emitTimeInterval) {

		// decrease emitCounter by emitTimeInterval - don't set to 0 as this would ignore the case where multiple particles are needed.
		emitCounter -= emitTimeInterval;

		// Create new particle
		float x = position.x + normDist(gen) * size.x;
		float y = position.y + normDist(gen) * size.y;
		float scale = scaleDist(gen);
		float mass = massDist(gen);
		float rotationSpeed = glm::radians(normDist(gen) * 45.0f);
		int spriteIndex = spriteDist(gen);

		particles* s1 = new particles(glm::vec2(x, y), 0.0f, glm::vec2(scale, scale), particleTexture[spriteIndex], mass, rotationSpeed);
		
		string key = string("particles");

		if (particleNumber > 0) {
			key += to_string(particleNumber);
		}
		particleNumber++;

		addObject(key.c_str(), s1);
		}
	}


void Emitter::render() {
	
	



}


