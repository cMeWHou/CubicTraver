#ifndef MOUSE_SCROLL_CALLBACK_FUNCTIONS_H
#define MOUSE_SCROLL_CALLBACK_FUNCTIONS_H

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
    camera.ProcessMouseScroll(yoffset);
}

#endif