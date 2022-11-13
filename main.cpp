// Headers
#include <iostream>

#include <gl_headers.hpp>
#include <user_headers.hpp>

#include <DATA/globals.hpp>
#include <DATA/paths.hpp>
#include <DATA/vertices.hpp>

#include <functions.hpp>

int main(int argc, char *argv[]) {
    // GLFW, GLAD init and window creation
    Widget widget(GL_MAJOR_V, GL_MINOR_V, GL_PROFILE,
                  WND_WIDTH, WND_HEIGHT, WND_NAME);

    // Set callback functions
    glfwSetKeyCallback(widget.window, key_button_callback);
    glfwSetFramebufferSizeCallback(widget.window, framebuffer_size_callback);
    glfwSetMouseButtonCallback(widget.window, mouse_button_callback);
    glfwSetCursorPosCallback(widget.window, cursor_pos_callback);
    glfwSetScrollCallback(widget.window, scroll_callback);

    // Shaders
    Shader cursorShader(pathToCursorVertexShader, pathToCursorFragmentShader);
    Shader cubeShader(pathToCubeVertexShader, pathToCubeFragmentShader);
    Shader cubeTransparentShader(pathToTransparentCubeVertexShader, pathToTransparentCubeFragmentShader);

    // VAO config
    int layouts, size[4], maxSize, offset[4];
    layouts = 1, arraySet(size, 1, 3), maxSize = 3, arraySet(offset, 1, 0);
    VAO cursorVAO(cursorVerticesSize, cursorVertices, layouts, size, maxSize, offset);

    layouts = 2, arraySet(size, 2, 3, 2), maxSize = 5, arraySet(offset, 2, 0, 3);
    VAO cubeVAO(cubeVerticesSize, cubeVertices, layouts, size, maxSize, offset);

    layouts = 1, arraySet(size, 1, 3), maxSize = 5, arraySet(offset, 1, 0);
    VAO cubeTransparentVAO(cubeVerticesSize, cubeVertices, layouts, size, maxSize, offset);

    // Textures
    Texture textureStone(pathToTextureStone);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureStone.ID);

    // Cubes positions
    cubePositions = new glm::vec3[AREA_MAX_CUBES]{};
    cubeColors = new glm::vec3[AREA_MAX_CUBES]{};

    // Input mode
    glfwSetInputMode(widget.window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // Render mode
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_DEPTH_TEST);

    // Main loop
    while (!glfwWindowShouldClose(widget.window)) {
        GLfloat currentTime = glfwGetTime();
        deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        // Scene
        glClearColor(0.9f, 0.8f, 0.5f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        projection = glm::perspective(glm::radians(camera.Zoom), (float)WND_WIDTH / (float)WND_HEIGHT, 0.1f, 100.0f);
        view = camera.GetViewMatrix();

        // Get events
        glfwPollEvents();

        // Movement
        doMovement();

        // Delete cube
        int ID;
        drawMask(cubeTransparentShader, cubeTransparentVAO, &ID);
        remCube(ID);

        // Add cube
        glm::vec3 worldCursorPos;
        translateScreenCoordsToWorld(&worldCursorPos);
        drawMask(cubeTransparentShader, cubeTransparentVAO, &ID);
        addCube(worldCursorPos, ID);

        // Environment
        drawEnvironment(cubeShader, cubeVAO);

        // Cursor
        drawCursor(cursorShader, cursorVAO);

        glfwSwapBuffers(widget.window);
    }

    cubeVAO.remove();
    cubeTransparentVAO.remove();
    cursorVAO.remove();

    cubeShader.remove();
    cubeTransparentShader.remove();
    cursorShader.remove();

    delete[] cubePositions;
    delete[] cubeColors;

    return 0;
}
