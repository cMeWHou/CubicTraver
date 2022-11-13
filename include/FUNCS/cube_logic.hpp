#ifndef CUBE_LOGIC_FUNCTIONS_H
#define CUBE_LOGIC_FUNCTIONS_H

int getIDByColor() {
    GLubyte colors[3];
    glReadPixels(WND_WIDTH / 2.0f, WND_HEIGHT / 2.0f, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &colors);
    return colors[2] * COLOR_MAX_SIZE + colors[1] * COLOR_MAX_SIZE + colors[0];
}

void checkMaxCube() {
    if (cubeAmount == AREA_MAX_CUBES) {
        for (int i = 1; i < cubeAmount; i++)
            cubePositions[i - 1] = cubePositions[i];
        cubeAmount -= 1;
    }
}

bool checkEmptyPos(glm::vec3 cube_position) {
    for (int i = 0; i < cubeAmount + 1; i++)
        if (cube_position == cubePositions[i])
            return false;
    return true;
}

bool checkValidPos(glm::vec3 cube_position) {
    checkMaxCube();

    if (checkEmptyPos(cube_position))
        return true;
    return false;
}

glm::vec3 changePos(glm::vec3 cube_position) {
    glm::vec3 cameraPos = getCameraPos();
    glm::vec3 diff = cube_position - cameraPos;
    diff = cube_position - glm::normalize(diff);

    return diff;
}

void roundPos(glm::vec3 *cube_position) {
    if (abs((*cube_position).x - (int)(*cube_position).x) < 0.5f)
        (*cube_position).x -= (abs((*cube_position).x - (int)(*cube_position).x)) / (abs((*cube_position).x) / (*cube_position).x);
    else
        (*cube_position).x += (1.0f - (abs((*cube_position).x - (int)(*cube_position).x))) / (abs((*cube_position).x) / (*cube_position).x);

    if (abs((*cube_position).z - (int)(*cube_position).z) < 0.5f)
        (*cube_position).z -= (abs((*cube_position).z - (int)(*cube_position).z)) / (abs((*cube_position).z) / (*cube_position).z);
    else
        (*cube_position).z += (1.0f - (abs((*cube_position).z - (int)(*cube_position).z))) / (abs((*cube_position).z) / (*cube_position).z);
}

void setSelectGradient() {
    for (int i = 0, j = 0, k = 1; i < cubeAmount; i++, k++) {
        if ((i % COLOR_MAX_SIZE) == 0 && (i != 0)) {
            k = 0;
            j++;
        }

        cubeColors[i] = glm::vec3((GLfloat)k / COLOR_MAX_SIZE, (GLfloat)j / COLOR_MAX_SIZE, 0);
    }
}

void addCube(glm::vec3 worldCursorPos, int ID) {
    if (((GLfloat)glfwGetTime()) - waitingTime > 0.1f) {
        waitingTime = glfwGetTime();
        roundPos(&worldCursorPos);

        if (buttons[GLFW_MOUSE_BUTTON_RIGHT]) {
            if (checkValidPos(worldCursorPos)) {
                cubePositions[cubeAmount] = worldCursorPos;
                cubeAmount += 1;
            } else if (!checkEmptyPos(cubePositions[ID])) {
                cubePositions[cubeAmount] = changePos(cubePositions[ID]);
                roundPos(&cubePositions[cubeAmount]);
                cubeAmount += 1;
            }
        }

        if (keys[GLFW_KEY_Z])
            if (cubeAmount)
                cubeAmount -= 1;
    }
}

void remCube(int cubeID) {
    if (buttons[GLFW_MOUSE_BUTTON_LEFT])
        if (cubeID != 0)
            for (int i = cubeID - 1; i < cubeAmount; i++) {
                if (i == cubeAmount - 1)
                    cubeAmount -= 1;
                cubePositions[i] = cubePositions[i + 1];
            }
}

#endif