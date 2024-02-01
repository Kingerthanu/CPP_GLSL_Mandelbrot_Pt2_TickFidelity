#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <chrono>
#include <thread>

#include "shader.h"


int main()
{
    
    // Call up openGL context window
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(1800, 1800, "EpicSauceWindow", NULL, NULL);
	// Bank on it working



	glfwMakeContextCurrent(window);
	gladLoadGL();


    // Create view of user cam and craft our shader with files.
	glViewport(0, 0, 1800, 1800);

	Shader _shader = Shader("default.vert", "default.frag");
    

    // Set up vertex buffer and array for a quad
    GLfloat vertices[] = {
        -1.0f, -1.0f,
        -1.0f,  1.0f,
         1.0f,  1.0f,
         1.0f, -1.0f
         
    };

    // Light VBOs and VAOs.
    GLuint VBO, VAO;

    // Grab mem from opengl for vbo and vao.
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // Connect VBO with VAO.
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    // Give context for VBO.
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    // Don't need to unbind as only have one context.

    
    // Set program outside as will stay same program throughout runtime
    glUseProgram(_shader.ID);
        
    // Only setting once so dont need to hold int.
    glUniform2f(glGetUniformLocation(_shader.ID, "centerOffset"), -1200.5f, -1000.5f);
    glUniform1f(glGetUniformLocation(_shader.ID, "bloatScale"), 22000.f);
    

    // Positions in memory of uniforms will stay (hopefully) constant throughout runtime so can get once.
    GLuint timeLoc = glGetUniformLocation(_shader.ID, "time");
    GLuint tickLoc = glGetUniformLocation(_shader.ID, "tick");

    std::chrono::duration<double> frameDuration(1.0 / 144), sleepTime;

    std::chrono::steady_clock::time_point frameStart, frameEnd;
    std::chrono::milliseconds frameTime;

    // Use tick for zoom
    float _tickTimer = 0.9f;
    int _tick = 0;

    while (!glfwWindowShouldClose(window)) {

        frameStart = std::chrono::high_resolution_clock::now();

        glClear(GL_COLOR_BUFFER_BIT);

        glUniform1f(timeLoc, _tickTimer);
        glUniform1i(tickLoc, _tick);

        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

        _tickTimer += 0.4f;
        _tick += 500;

        glfwSwapBuffers(window);
        glfwPollEvents();

        frameEnd = std::chrono::high_resolution_clock::now();
        frameTime = std::chrono::duration_cast<std::chrono::milliseconds>(frameEnd - frameStart);

        if (frameTime < frameDuration) {

            sleepTime = frameDuration - frameTime;
            std::this_thread::sleep_for(sleepTime);
        }

    }

    // Cleanup

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    _shader.Delete();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;


}
