#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../common/shader.h"

using namespace std;

const GLuint WIDTH = 1280, HEIGHT = 800;

void update(float* val, float x) {
	* val += x;
}

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow * window = glfwCreateWindow(WIDTH, HEIGHT, "Modern Car", NULL, NULL);

	int _width = 1000, _height = 500;
	glfwGetFramebufferSize(window, &_width, &_height);

	if (window == NULL) {
		cout << "Failed to make window." << endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		cout << "Failed to start GLEW" << endl;
		glfwTerminate();
		return -1;
	}

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	glClearColor(0.55, 0.40, 1.0, 0);
	glViewport(0, 0, _width, _height);

	// GLuint shaders = LoadShaders("../shaders/vertex.glsl", "../shaders/fragment.glsl");

	GLfloat vertices[] =  {
		-0.20f, 0.45f, 0.0f,   1.0f, 0.0f, 0.0f,
		0.20f, 0.45f, 0.0f,   1.0f, 0.0f, 0.0f,
		0.20f, 0.05f, 0.0f,   1.0f, 0.0f, 0.0f,

		0.20f, 0.05f, 0.0f,   1.0f, 0.0f, 0.0f,
		-0.20f, 0.05f, 0.0f,   1.0f, 0.0f, 0.0f,
		-0.20f, 0.45f, 0.0f,   1.0f, 0.0f, 0.0f,

		0.20f, 0.45f, 0.0f,   1.0f, 0.0f, 0.0f,
		0.20f, 0.05f, 0.0f,   1.0f, 0.0f, 0.0f,
		0.45f,  0.05f, 0.0f,   1.0f, 0.0f, 0.0f,

		-0.20f, 0.45f, 0.0f,   1.0f, 0.0f, 0.0f,
		-0.20f, 0.05f, 0.0f,   1.0f, 0.0f, 0.0f,
		-0.45f, 0.05f, 0.0f,   1.0f, 0.0f, 0.0f,

		// window
		-0.19f, 0.40f, 0.0f,   1.0f, 1.0f, 0.0f,
		0.19f, 0.40f, 0.0f,   1.0f, 1.0f, 0.0f,
		0.18f, 0.10f, 0.0f,   1.0f, 1.0f, 0.0f,

		0.18f, 0.10f, 0.0f,   1.0f, 1.0f, 0.0f,
		-0.18f, 0.10f, 0.0f,   1.0f, 1.0f, 0.0f,
		-0.19f, 0.40f, 0.0f,   1.0f, 1.0f, 0.0f,

		0.19f, 0.40f, 0.0f,   1.0f, 1.0f, 0.0f,
		0.18f, 0.10f, 0.0f,   1.0f, 1.0f, 0.0f,
		0.38f, 0.10f, 0.0f,   1.0f, 1.0f, 0.0f,

		-0.19f, 0.40f, 0.0f,   1.0f, 1.0f, 0.0f,
		-0.18f, 0.10f, 0.0f,   1.0f, 1.0f, 0.0f,
		-0.38f, 0.10f, 0.0f,   1.0f, 1.0f, 0.0f,

		// window separator
		-0.02f, 0.45f, 0.0f,   1.0f, 0.0f, 0.0f,
		-0.02f, 0.05f, 0.0f,   1.0f, 0.0f, 0.0f,
		0.02f, 0.05f, 0.0f,   1.0f, 0.0f, 0.0f,

		-0.02f, 0.45f, 0.0f,   1.0f, 0.0f, 0.0f,
		0.02f, 0.45f, 0.0f,   1.0f, 0.0f, 0.0f,
		0.02f, 0.05f, 0.0f,   1.0f, 0.0f, 0.0f,

		// lower body
		-0.20f, 0.05f, 0.0f,   0.0f, 0.0f, 1.0f,
		0.20f, 0.05f, 0.0f,   0.0f, 0.0f, 1.0f,
		0.20f, -0.35f, 0.0f,   0.0f, 0.0f, 1.0f,

		0.20f, -0.35f, 0.0f,   0.0f, 0.0f, 1.0f,
		-0.20f, -0.35f, 0.0f,   0.0f, 0.0f, 1.0f,
		-0.20f, 0.05f, 0.0f,   0.0f, 0.0f, 1.0f,

		0.20f, 0.05f, 0.0f,   0.0f, 0.0f, 1.0f,
		0.60f, 0.05f, 0.0f,   0.0f, 0.0f, 1.0f,
		0.60f, -0.35f, 0.0f,   0.0f, 0.0f, 1.0f,

		0.60f, -0.35f, 0.0f,   0.0f, 0.0f, 1.0f,
		0.20f, -0.35f, 0.0f,   0.0f, 0.0f, 1.0f,
		0.20f, 0.05f, 0.0f,   0.0f, 0.0f, 1.0f,

		-0.60f, 0.05f, 0.0f,   0.0f, 0.0f, 1.0f,
		-0.20f, 0.05f, 0.0f,   0.0f, 0.0f, 1.0f,
		-0.20f, -0.35f, 0.0f,   0.0f, 0.0f, 1.0f,

		-0.20f, -0.35f, 0.0f,   0.0f, 0.0f, 1.0f,
		-0.60f, -0.35f, 0.0f,   0.0f, 0.0f, 1.0f,
		-0.60f, 0.05f, 0.0f,   0.0f, 0.0f, 1.0f,
	};

	for (int i = 0; i < sizeof(vertices)/sizeof(vertices[0]); i++) {
		if (i % 6 == 0) {
			update(&(vertices[i]), 2.0f);
		}
	}

	//---------------------------------------------------------------------------------//
	GLuint VERTEX_ARRAY_OBJECT, VERTEX_BUFFER_OBJECT;

	glGenVertexArrays(1, &VERTEX_ARRAY_OBJECT);
	glGenBuffers(1, &VERTEX_BUFFER_OBJECT);

	glBindVertexArray(VERTEX_ARRAY_OBJECT);
	glBindBuffer(GL_ARRAY_BUFFER, VERTEX_BUFFER_OBJECT);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//---------------------------------------------------------------------------------//
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *) 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	//---------------------------------------------------------------------------------//

	do {
		glClear(GL_COLOR_BUFFER_BIT);
		glBindVertexArray(VERTEX_ARRAY_OBJECT);
		glDrawArrays(GL_TRIANGLES, 0, 48);
		glBindVertexArray(0);

		glfwSwapBuffers(window);

		for (int i = 0; i < sizeof(vertices) / sizeof(vertices[0]); i++) {
			if (i % 6 == 0) {
				update(&(vertices[i]), -0.05f);
			}
		}
		int offset = 0;
		for (int i = 0; i < 7; i++) {
			int vertices_count = sizeof(car_body_vertices[i]) / (5 * sizeof(float));
			glDrawArrays(GL_TRIANGLE_FAN, offset, vertices_count);
			offset += vertices_count;
		}
		glBindVertexArray(0);
		glfwPollEvents();		
	} while (glfwWindowShouldClose(window) == 0);

	glDeleteBuffers(1, &VERTEX_BUFFER_OBJECT);
	glDeleteVertexArrays(1, &VERTEX_ARRAY_OBJECT);
	glfwTerminate();

	return 0;
}