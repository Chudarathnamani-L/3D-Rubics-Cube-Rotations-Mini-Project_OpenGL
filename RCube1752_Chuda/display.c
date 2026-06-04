#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include "display.h"

// Rotation & animation state
int rotateaxis = 0;
int angle = 0;
int rotation = 0;
int inverse = 0;
int rotationcomplete = 1;
int count = -1;
int solve[100];

// Face color state
int cubeface[6][3][3];

// Initial camera rotation
GLfloat theta[] = {0.0, 0.0, 0.0};

void drawFace(int faceColor)
{
    switch(faceColor) {
        case 0: glColor3f(1, 1, 1); break;   // White
        case 1: glColor3f(1, 1, 0); break;   // Yellow
        case 2: glColor3f(0, 1, 0); break;   // Green
        case 3: glColor3f(0, 0, 1); break;   // Blue
        case 4: glColor3f(1, 0, 0); break;   // Red
        case 5: glColor3f(1, 0.5, 0); break; // Orange
    }
    glutSolidCube(1.0);
}

void drawCube()
{
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {
                glPushMatrix();
                glTranslatef(i * 1.1, j * 1.1, k * 1.1);
                drawFace((i + j + k + 6) % 6);  // ensure non-negative index
                glPopMatrix();
            }
        }
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(theta[0], 1.0, 0.0, 0.0);
    glRotatef(theta[1], 0.0, 1.0, 0.0);
    glRotatef(theta[2], 0.0, 0.0, 1.0);

    drawCube();

    glutSwapBuffers();
}

void spincube()
{
    if (rotationcomplete) {
        glutIdleFunc(NULL);
        return;
    }

    angle += 5;
    if (angle >= 90) {
        angle = 0;
        rotationcomplete = 1;
        glutIdleFunc(NULL);
    }

    display();
}
