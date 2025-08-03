#include <GL/glut.h>
#include <math.h>

void bresenhanLine(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0), dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1, sy = y0 < y1 ? 1 : -1;
    int err = dx - dy, e2;

    glBegin(GL_POINTS);
    while (1) {
        glVertex2i(x0, y0);
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
    glEnd();
}



void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    bresenhanLine(200, 200, 225, 200);
    bresenhanLine(225, 200, 225, 215);
    bresenhanLine(225, 215, 250, 200);
    bresenhanLine(250, 200, 265, 200);
    bresenhanLine(265, 200, 265, 230);
    bresenhanLine(265, 230, 255, 230);
    bresenhanLine(255, 230, 255, 245);
    bresenhanLine(255, 245, 240, 245);
    bresenhanLine(240, 245, 240, 260);
    bresenhanLine(240, 260, 230, 260);
    bresenhanLine(230, 260, 230, 245);
    bresenhanLine(230, 245, 215, 260);
    bresenhanLine(215, 260, 200, 260);
    bresenhanLine(200, 260, 200, 245);
    bresenhanLine(200, 245, 210, 245);
    bresenhanLine(210, 245, 210, 225);
    bresenhanLine(210, 225, 200, 225);
    bresenhanLine(200, 225, 200, 200);

    // glutFullScreen();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(1280, 720);
    glutCreateWindow("Atividade Computação Gráfica e Processamento de Imagens");
    glColor3f(0, 0, 0);
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0, 1280, 0, 720);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
