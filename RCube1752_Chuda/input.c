#include <GL/glut.h>
#include "input.h"
#include "display.h"

extern GLfloat theta[];


void specialKeys(int key, int x, int y)
{
    switch (key) {
        case GLUT_KEY_UP:
            theta[0] += 5;
            break;
        case GLUT_KEY_DOWN:
            theta[0] -= 5;
            break;
        case GLUT_KEY_LEFT:
            theta[1] -= 5;
            break;
        case GLUT_KEY_RIGHT:
            theta[1] += 5;
            break;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    // You can extend this
}

void motion(int x, int y)
{
    // You can extend this
}
