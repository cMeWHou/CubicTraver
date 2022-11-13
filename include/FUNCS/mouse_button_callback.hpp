#ifndef MOUSE_BUTTON_CALLBACK_FUNCTIONS_H
#define MOUSE_BUTTON_CALLBACK_FUNCTIONS_H

void mouse_button_callback(GLFWwindow *window, int button, int action, int mods) {
    if (button >= 0 && button < 16) {
        if (action == GLFW_PRESS)
            buttons[button] = true;
        else if (action == GLFW_RELEASE)
            buttons[button] = false;
    }
}

#endif