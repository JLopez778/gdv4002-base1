#include "Engine.h"
#include <numbers>
#include "keys.h"
#include "player.h"

// Function prototypes
void myUpdate(GLFWwindow* window, double tDelta);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);


using namespace std;
GameObject2D* player1;

bitset<5> keys{ 0x0 };

int main(void) {

	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 1024, 1024);

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		printf("Cannot setup game window!!!\n");
		return initResult; // exit if setup failed
	}

	//
	// Setup game scene objects here
	//

	const float pi = 3.141593;
	
	addObject("asteroid");
	addObject("asteroid");
	addObject("asteroid");
	float playerVelocity = 2.0f;
	GLuint playerTexture = loadTexture("Resources\\Textures\\player1_ship.png");

	player* mainPlayer = new player(glm::vec2(-1.5f, 0.0f), 0.0f, glm::vec2(0.5f, 0.5f), playerTexture, 1.0f);

	addObject("player", mainPlayer);


	GLuint asteroidTexture = loadTexture("Resources\\Textures\\alien01.png");


	player1 = getObject("player1");
	GameObject2D* asteroid1Object = getObject("asteroid1");

	
	

	setUpdateFunction(myUpdate);
	setKeyboardHandler(key_callback);
	listGameObjectKeys();
	listObjectCounts();



	// Enter main loop - this handles update and render calls
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}


float asteroidPhase[] = { 0.0f, 0.0f, 0.0f };
float asteroidPhaseVelocity[] = { glm::radians(90.0f), glm::radians(90.0f), glm::radians(90.0f) };

void myUpdate(GLFWwindow* window, double tDelta) {

	static float playerSpeed = 1.0f; // distance per second

	GameObject2D* player = getObject("player1");

	if (keys.test(key::W) == true) {

		player->position.y += playerSpeed * (float)tDelta;
	}

	if (keys.test(key::A) == true) {

		player->position.x -= playerSpeed * (float)tDelta;
	}

	if (keys.test(key::S) == true) {

		player->position.x += playerSpeed * (float)tDelta;
	}

	if (keys.test(key::D) == true) {

		player->position.y -= playerSpeed * (float)tDelta;
	}





	GameObjectCollection asteroids = getObjectCollection("asteroid");

	GameObject2D* objectToProcess = asteroids.objectArray[0];
	asteroids.objectArray[0]->position.y = sinf(asteroidPhase[0]);
	asteroidPhase[0] += asteroidPhaseVelocity[0] * tDelta;



}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {

	if (action == GLFW_PRESS) {
		switch (key) {
		case GLFW_KEY_ESCAPE:
			glfwSetWindowShouldClose(window, true);
			break;

		case GLFW_KEY_W:
			keys[key::W] = true;
			break;

		case GLFW_KEY_A:
			keys[key::A] = true;
			break;

		case GLFW_KEY_S:
			keys[key::S] = true;
			break;

		case GLFW_KEY_D:
			keys[key::D] = true;
		}
	}

	else if (action == GLFW_RELEASE){
			switch (key) {
			case GLFW_KEY_A:
				keys[key::A] = false;
			case GLFW_KEY_W:
				keys[key::W] = false;
				break;

			case GLFW_KEY_S:
				keys[key::S] = false;
				break;

			case GLFW_KEY_D:
				keys[key::D] = false;
				break;

			}

		
			}
		
		

		}

	




//void myUpdate(GLFWwindow * window, double tDelta) {
//
//	float player1RotationSpeed = glm::radians(90.0f);
//	GameObject2D* player1 = getObject("player1");
//	player1->orientation += player1RotationSpeed * tDelta;
//	player1->orientation = player1->orientation + glm::radians(1.5);
//
//	float anglesPerSecond = glm::radians(45.0f);
//
//
//	float playerVelocity = 2.0f;
//
//
//};

