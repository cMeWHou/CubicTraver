#ifndef TEXTURE_H
#define TEXTURE_H

#include <TXTR/stb_image.hpp>

// Provides methods for work with textures
class Texture {
  public:
    GLuint ID;

    Texture(const char *texturePath) {
        glGenTextures(1, &ID);
        glBindTexture(GL_TEXTURE_2D, ID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        int width, height, nrChannels;
        stbi_set_flip_vertically_on_load(true);

        unsigned char *data = stbi_load(texturePath, &width, &height, &nrChannels, 0);
        if (data) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
            std::cout << "TEXTURE(" << texturePath << ")::LOAD::OK" << std::endl;
        } else {
            std::cout << "TEXTURE(" << texturePath << ")::LOAD::ERROR" << std::endl;
        }
        stbi_image_free(data);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    ~Texture() {
        glDeleteTextures(1, &ID);
    }

    void bind() {
        glBindTexture(GL_TEXTURE_2D, ID);
    }

    void unbind() {
        glBindTexture(GL_TEXTURE_2D, 0);
    }
};

#endif