#ifndef MOUSE_CALLBACK_FUNCTIONS_H
#define MOUSE_CALLBACK_FUNCTIONS_H

#include <FUNCS/cursor_pos_callback.hpp>
#include <FUNCS/mouse_button_callback.hpp>
#include <FUNCS/scroll_callback.hpp>

glm::vec3 getCameraDir() {
    glm::vec4 tmpMatrix = glm::vec4(2.0f * ((float)WND_WIDTH / 2 / WND_WIDTH) - 1.0f,
                                    -2.0f * ((float)WND_HEIGHT / 2 / WND_HEIGHT) + 1.0f,
                                    -1.0f,
                                    1.0f);

    glm::vec4 projectionTmp = glm::inverse(projection) * tmpMatrix;
    projectionTmp = glm::vec4(projectionTmp.x, projectionTmp.y, -1.0f, 0.0f);

    glm::vec4 camDirectionTmp = glm::inverse(view) * projectionTmp;
    glm::vec3 camDirection = glm::vec3(camDirectionTmp.x, camDirectionTmp.y, camDirectionTmp.z);
    camDirection = glm::normalize(camDirection);

    return camDirection;
}

glm::vec3 getCameraPos() {
    glm::vec4 camPositionTmp = glm::inverse(view) * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
    glm::vec3 camPosition = glm::vec3(camPositionTmp.x, camPositionTmp.y, camPositionTmp.z);

    return camPosition;
}

void translateScreenCoordsToWorld(glm::vec3 *cursor_pos) {
    glm::vec3 camDirection = getCameraDir();
    glm::vec3 camPosition = getCameraPos();

    glm::vec3 normal = camera.WorldUp;
    float t = -glm::dot(camPosition, normal) / glm::dot(camDirection, normal);
    (*cursor_pos) = camPosition + camDirection * t;
}

#endif