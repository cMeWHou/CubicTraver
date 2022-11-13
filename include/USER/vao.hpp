#ifndef VAO_H
#define VAO_H

// Provides methods for work with Vertex Array Objects (VAO)
class VAO {
  public:
    GLuint ID;

    VAO(int vertices_amount, GLfloat *vertices,
        int layouts, int *size, int max_size, int *offset) {
        glGenVertexArrays(1, &ID);
        glBindVertexArray(ID);

        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, ID);
        glBufferData(GL_ARRAY_BUFFER, vertices_amount * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

        for (int i = 0; i < layouts; i++) {
            glVertexAttribPointer(i, size[i], GL_FLOAT, GL_FALSE, max_size * sizeof(GLfloat), (GLvoid *)(sizeof(GLfloat) * offset[i]));
            glEnableVertexAttribArray(i);
        }

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    ~VAO() {
        glDeleteBuffers(1, &VBO);
    }

    void bind() {
        glBindVertexArray(ID);
    }

    void unbind() {
        glBindVertexArray(0);
    }

    void remove() {
        glDeleteVertexArrays(1, &ID);
    }

  private:
    GLuint VBO;
};

#endif