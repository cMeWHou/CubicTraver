# CMake configuration
cmake_minimum_required(VERSION 3.0.0)

project(GL_GAME VERSION 0.1.0)

# Script variables
set(SOURSE_FILES "main.cpp" "glad.c")

# Script properties
add_executable(${PROJECT_NAME} ${SOURSE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC
                            "${PROJECT_SOURCE_DIR}/include/")
target_link_directories(${PROJECT_NAME} PUBLIC
                            "${PROJECT_SOURCE_DIR}/lib/")
                            
target_link_libraries(${PROJECT_NAME} "glfw3" "opengl32" "gdi32")
