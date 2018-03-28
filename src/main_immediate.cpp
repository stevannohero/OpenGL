#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GLUT/GLUT.h>
#include <math.h>
#include <iostream>
#include <unistd.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define radius 0.175
int steps = 0;

GLenum doubleBuffer;
GLint upperPartCar, bottomPartCar, frontWheelCar;

void increaseStep() {
    usleep(100000);
    steps++;
    glutPostRedisplay();
}

static void Init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClearAccum(0.0, 0.0, 0.0, 0.0);
    
    upperPartCar = glGenLists(1);
    glNewList(upperPartCar, GL_COMPILE);
    glColor3f(1.0, 0.0, 0.0);
    glRectf(-0.4, 0.3, 0.4, 0.0);
    glEndList();
    
    bottomPartCar = glGenLists(1);
    glNewList(bottomPartCar, GL_COMPILE);
    glColor3f(1.0, 0.0, 0.0);
    glRectf(-0.75, 0.0, 0.75, -0.3);
    glEndList();
    
    frontWheelCar = glGenLists(1);
    glNewList(frontWheelCar, GL_COMPILE);
    glEndList();
}

static void Key(unsigned char key, int x, int y)
{
    switch (key) {
        case 27:
            exit(0);
    }
}

static void Draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glCallList(upperPartCar);
    glCallList(bottomPartCar);
    glCallList(frontWheelCar);
    glPopMatrix();
    
    glPushMatrix();
    
    double starting_point;
    if (steps % 2 == 0) {
        starting_point = 0;
    } else {
        starting_point = PI / 10;
    }
    
    //Left Wheel
    glBegin(GL_POLYGON);
    int j = 0;
    for(double i = starting_point; i <= 2 * PI; i += PI / 10, j++) {
        if (j % 2 == 0) {
            glColor3f(0, 0, 0);
        } else {
            glColor3f(1, 1, 1);
        }
        glVertex2f(-0.4, -0.3);
        glVertex2f(-0.4 + cos(i) * radius, -0.3 + sin(i) * radius);
        glVertex2f(-0.4 + cos(i + PI / 10) * radius, -0.3 + sin(i + PI / 10) * radius);
    }
    glEnd();
    
    //Right Wheel
    glBegin(GL_POLYGON);
    j = 0;
    for(double i = starting_point; i <= 2 * PI; i += PI / 10, j++) {
        if (j % 2 == 0) {
            glColor3f(0, 0, 0);
        } else {
            glColor3f(1, 1, 1);
        }
        glVertex2f(0.4, -0.3);
        glVertex2f(0.4 + cos(i) * radius, -0.3 + sin(i) * radius);
        glVertex2f(0.4 + cos(i + PI / 10) * radius, -0.3 + sin(i + PI / 10) * radius);
    }
    glEnd();
    
    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    GLenum type;

    glutInit(&argc, argv);
    glutInitWindowSize(750, 750);
    glutCreateWindow("opengl_task_moving_car_immediate");

    Init();
    
    glutKeyboardFunc(Key);
    glutDisplayFunc(Draw);
    glutIdleFunc(increaseStep);
    glutMainLoop();
}

