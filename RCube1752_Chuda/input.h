#ifndef INPUT_H
#define INPUT_H

void keyboard(unsigned char key, int x, int y);
void specialKeys(int key, int x, int y);
void mouse(int button, int state, int x, int y);   // 👈 ADD THIS
void motion(int x, int y);                         // 👈 AND THIS

#endif
