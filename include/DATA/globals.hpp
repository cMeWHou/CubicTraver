#ifndef GLOBALS_H
#define GLOBALS_H

// Constants for window
const char *WND_NAME = "GL_PROJECT";
const int WND_HEIGHT = 600;
const int WND_WIDTH = 800;

// Camera settings
Camera camera(glm::vec3(0.0f, 0.0f, 0.0f));
float lastX = WND_WIDTH / 2.0f;
float lastY = WND_HEIGHT / 2.0f;
bool firstMouse = true;

// Matrix
glm::mat4 projection;
glm::mat4 view;
glm::mat4 model;

// Keys click flags
bool keys[256];
bool buttons[16];

// Time sync
float deltaTime = 0.0f;
float lastTime = 0.0f;
float waitingTime = 0.0f;

// Area settings
glm::vec3 *cubePositions;
glm::vec3 *cubeColors;
const int AREA_MAX_CUBES = 65536;
int cubeAmount = 0;

// Selection settings
const int COLOR_MAX_SIZE = 255;

#endif