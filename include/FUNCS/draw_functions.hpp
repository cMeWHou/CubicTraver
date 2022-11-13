#ifndef DRAW_FUNCTIONS_H
#define DRAW_FUNCTIONS_H

void drawCursor(Shader shader, VAO VAO) {
    shader.bind();

    shader.setMat4("projection", projection);
    shader.setMat4("view", view);

    glBindVertexArray(VAO.ID);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);

    shader.unbind();
}

void drawEnvironment(Shader shader, VAO VAO) {
    shader.bind();

    shader.setInt("ourTexture1", 0);

    shader.setMat4("projection", projection);
    shader.setMat4("view", view);

    glBindVertexArray(VAO.ID);
    for (int i = 0; i < cubeAmount; i++) {
        shader.setVec3("shapeColor", cubeColors[i]);

        model = glm::mat4(1.0f);
        model = glm::translate(model, cubePositions[i]);

        shader.setMat4("model", model);

        glDrawArrays(GL_TRIANGLES, 0, 36);
    }
    glBindVertexArray(0);

    shader.unbind();
}

void drawMask(Shader shader, VAO VAO, int *cube_index) {
    if (buttons[GLFW_MOUSE_BUTTON_LEFT] || buttons[GLFW_MOUSE_BUTTON_RIGHT]) {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        setSelectGradient();
        drawEnvironment(shader, VAO);

        (*cube_index) = getIDByColor();

        glClearColor(0.9f, 0.8f, 0.5f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
}

#endif