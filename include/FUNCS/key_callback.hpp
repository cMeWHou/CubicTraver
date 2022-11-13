#ifndef KEY_CALLBACK_FUNCTIONS_H
#define KEY_CALLBACK_FUNCTIONS_H

#include <FUNCS/key_button_callback.hpp>

void doMovement() {
    if (keys[GLFW_KEY_W])
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (keys[GLFW_KEY_S])
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (keys[GLFW_KEY_A])
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (keys[GLFW_KEY_D])
        camera.ProcessKeyboard(RIGHT, deltaTime);
}

#endif