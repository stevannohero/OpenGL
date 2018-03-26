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
		cout << "WINDOW'S FAILED" << endl;
		glfwTerminate();
	} else {
		cout << "WINDOW'S OK" << endl;
	}

	glfwMakeContextCurrent(window);
	glViewport(0, 0, _width, _height);

	GLfloat vertices[] =  {
		
	};

	while (!glfwWindowShouldClose(window)) {
		
	}


	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}