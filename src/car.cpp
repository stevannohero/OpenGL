#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

const GLuint WIDTH = 1280, HEIGHT = 800;

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow * window = glfwCreateWindow(WIDTH, HEIGHT, "main", NULL, NULL);

	int _width, _height;
	glfwGetFramebufferSize(window, &_width, &_height);

	if (!window) {
		cout << "Failed to make window." << endl;
		glfwTerminate();
		return 1;
	} else {
		cout << "Window's successfully made." << endl;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		cout << "Failed to start GLEW" << endl;
		glfwTerminate();
		return 1;
	}

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	GLfloat vertices[] =  {
		
	};

	glViewport(0, 0, _width, _height);
	glClearColor(0, 0, 0, 0);

	//---------------------------------------------------------------------------------//
	GLuint VERTEX_ARRAY_OBJECT, VERTEX_BUFFER_OBJECT;

	glGenVertexArrays(1, &VERTEX_ARRAY_OBJECT);
	glBindVertexArray(VERTEX_ARRAY_OBJECT);

	glGenBuffers(1, &VERTEX_BUFFER_OBJECT);
	glBindBuffer(GL_ARRAY_BUFFER, VERTEX_BUFFER_OBJECT);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//---------------------------------------------------------------------------------//
	// GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer
	glVertexAttribPointer();
	glEnableVertexAttribArray(0);
	
	glVertexAttribPointer();
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(VERTEX_ARRAY_OBJECT);

		glBindVertexArray(0);

		glfwSwapBuffers(window);
		glfwPollEvents();		
	}

	glDeleteBuffers(1, &VERTEX_BUFFER_OBJECT);
	glDeleteVertexArrays(1, &VERTEX_ARRAY_OBJECT);
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}