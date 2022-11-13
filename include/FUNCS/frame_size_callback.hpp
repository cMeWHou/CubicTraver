#ifndef FRAME_SIZE_CALLBACK_FUNCTIONS_H
#define FRAME_SIZE_CALLBACK_FUNCTIONS_H

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

#endif