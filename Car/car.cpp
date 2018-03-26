#include <iostream>
#include <GL/glew.h>
#include <math.h>
#include <GLFW/glfw3.h>

using namespace std;

const GLuint WIDTH = 1280, HEIGHT = 800;
void drawCircle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLint numberOfSides);
int main() {
	glfwInit();

	// glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	// glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

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
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, _width, 0, _height, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	GLfloat vertices[] =  {
		
	};

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		drawCircle( _width / 2, _height / 2, 0, 120, 100);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	//glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

void drawCircle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLint numberOfSides){
	GLint numberOfVertices = numberOfSides + 1;

	GLfloat doublePi = 2.0f * M_PI;

	GLfloat circleVerticesX[numberOfVertices];
	GLfloat circleVerticesY[numberOfVertices];
	GLfloat circleVerticesZ[numberOfVertices];

	for ( int i = 0; i < numberOfVertices; i++){
		circleVerticesX[i] = x + ( radius * cos( i * doublePi / numberOfSides));
		circleVerticesY[i] = y + ( radius * sin( i * doublePi / numberOfSides));
		circleVerticesZ[i] = z;
	}
	
	GLfloat allCircleVertices[numberOfVertices * 3];

	for ( int i = 0; i < numberOfVertices; i++){
		allCircleVertices[i * 3] = circleVerticesX[i];
		allCircleVertices[( i * 3) + 1] = circleVerticesY[i];
		allCircleVertices[( i * 3) + 2] = circleVerticesZ[i];
	}

	glEnableClientState( GL_VERTEX_ARRAY);
	glVertexPointer( 3, GL_FLOAT, 0, allCircleVertices);
	glDrawArrays( GL_LINE_STRIP, 0, numberOfVertices);
	glDisableClientState(GL_VERTEX_ARRAY);
}