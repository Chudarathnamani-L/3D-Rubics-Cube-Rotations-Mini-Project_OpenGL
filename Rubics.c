// Rubik's Cube Visualization (Connected and Centered)
#include <GL/glut.h>

float cubeSize = 0.33f;   // Half the size of mini-cube
float spacing = 0.01f;    // Very small spacing so they appear connected
float angle = 0.0f;       // For rotation

void drawMiniCube() {
    glBegin(GL_QUADS);

    // Front face - White
    glColor3f(1, 1, 1);
    glVertex3f(-cubeSize, -cubeSize, cubeSize);
    glVertex3f(cubeSize, -cubeSize, cubeSize);
    glVertex3f(cubeSize, cubeSize, cubeSize);
    glVertex3f(-cubeSize, cubeSize, cubeSize);

    // Back face - Yellow
    glColor3f(1, 1, 0);
    glVertex3f(-cubeSize, -cubeSize, -cubeSize);
    glVertex3f(-cubeSize, cubeSize, -cubeSize);
    glVertex3f(cubeSize, cubeSize, -cubeSize);
    glVertex3f(cubeSize, -cubeSize, -cubeSize);

    // Top face - Red
    glColor3f(1, 0, 0);
    glVertex3f(-cubeSize, cubeSize, -cubeSize);
    glVertex3f(-cubeSize, cubeSize, cubeSize);
    glVertex3f(cubeSize, cubeSize, cubeSize);
    glVertex3f(cubeSize, cubeSize, -cubeSize);

    // Bottom face - Orange
    glColor3f(1, 0.5, 0);
    glVertex3f(-cubeSize, -cubeSize, -cubeSize);
    glVertex3f(cubeSize, -cubeSize, -cubeSize);
    glVertex3f(cubeSize, -cubeSize, cubeSize);
    glVertex3f(-cubeSize, -cubeSize, cubeSize);

    // Left face - Blue
    glColor3f(0, 0, 1);
    glVertex3f(-cubeSize, -cubeSize, -cubeSize);
    glVertex3f(-cubeSize, -cubeSize, cubeSize);
    glVertex3f(-cubeSize, cubeSize, cubeSize);
    glVertex3f(-cubeSize, cubeSize, -cubeSize);

    // Right face - Green
    glColor3f(0, 1, 0);
    glVertex3f(cubeSize, -cubeSize, -cubeSize);
    glVertex3f(cubeSize, cubeSize, -cubeSize);
    glVertex3f(cubeSize, cubeSize, cubeSize);
    glVertex3f(cubeSize, -cubeSize, cubeSize);

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Camera position
    gluLookAt(3, 3, 7,  0, 0, 0,  0, 1, 0);

    // Rotate whole cube
    glRotatef(angle, 1.0, 1.0, 0.0);

    // Draw 3x3x3 Rubik's Cube
    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            for (int z = -1; z <= 1; z++) {
                glPushMatrix();
                glTranslatef(x * (2 * cubeSize + spacing),
                             y * (2 * cubeSize + spacing),
                             z * (2 * cubeSize + spacing));
                drawMiniCube();
                glPopMatrix();
            }
        }
    }

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (double)w / (double)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int value) {
    angle += 5.5f;
    if (angle > 360) angle -= 360;
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void initOpenGL() {
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_MULTISAMPLE);
    glClearColor(0.05, 0.05, 0.05, 1.0);  // Slightly off-black
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);
    glutInitWindowSize(900, 700);
    glutCreateWindow("Rubik's Cube - Connected & Beautiful");
    initOpenGL();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
