#ifndef WIDGET_H
#define WIDGET_H

// Constants for GLFW
const int GL_MAJOR_V = 3;
const int GL_MINOR_V = 3;
const int GL_PROFILE = GLFW_OPENGL_CORE_PROFILE;

// Provides GLFW-, window and GL-functions
class Widget {
  public:
    GLFWwindow *window;

    Widget(int major_version, int minor_version, int profile, const int width, const int height, const char *name) {
        initGLFW(major_version, minor_version, profile);
        createWindow(width, height, name);

        initGLAD();
    };

    ~Widget() {
        glfwTerminate();
    };

  private:
    void initGLFW(int major_version, int minor_version, int profile) {
        if (!glfwInit())
            std::cout << "GLFW::INIT::ERROR" << std::endl;
        else
            std::cout << "GLFW::INIT::OK" << std::endl;

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major_version);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor_version);
        glfwWindowHint(GLFW_OPENGL_PROFILE, profile);
    }

    void initGLAD() {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            std::cout << "GLAD::INIT::ERROR" << std::endl;
        else
            std::cout << "GLAD::INIT::OK" << std::endl;
    }

    void createWindow(const int width, const int height, const char *name) {
        window = glfwCreateWindow(width, height, name, NULL, NULL);
        if (window == NULL) {
            std::cout << "GLFW::WINDOW::ERROR" << std::endl;
            glfwTerminate();
        } else {
            std::cout << "GLFW::WINDOW::OK" << std::endl;
        }
        glfwMakeContextCurrent(window);
    }
};

#endif