#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

typedef struct {
    int x0;
    int y0;
    int x1;
    int y1;
} Line;

typedef struct {
    int xPosition;
    int yPosition;
    Line left;
    // Line left;

} RectangleMmgu;

void bresenhanLine(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0), dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1, sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    glBegin(GL_POINTS);
    while (1) {
        glVertex2i(x0, y0);
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
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

Line createLine(const int x0, const int x1, const int y0, const int y1) {
    Line line;
    line.x0 = x0;
    line.x1 = x1;
    line.y0 = y0;
    line.y1 = y1;
    return line;
}


void drawRectangle(int width, int height, int startingX, int startingY) {

    Line line = createLine(startingX, startingX + width, startingY, startingY);
    //Bottom
    bresenhanLine(line.x0, line.y0, line.x1, line.y1);

    //Top
    bresenhanLine(line.x0, line.y0 + height, line.x1, line.y0 + height);

    //Left
    bresenhanLine(line.x0, line.y0, line.x0, line.y0 + height);

    //Right
    bresenhanLine(line.x1, line.y1, line.x1, line.y1 + height);

}



int increment = 0;
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(250, 0, 0);

    // drawRectangle(200, 200, 200, 200);
    int y = 200;
    int x = 200;
    glBegin(GL_POINTS);
    while (y <= (400)) {
        glVertex2i(x, y);
        x++;
        if (x > 400) {
            x = 200;
            y++;
        }
    }
    increment++;
    printf("Oi");
    glEnd();

    // glutFullScreen();
    glFlush();
    // glutTimerFunc(1000/60, display, 0);
}

void display2() {
    glClear(GL_COLOR_BUFFER_BIT);
    // drawRectangle(200, 200, 200, 200);
    // display();
    // printf("Oi");
    // glutFullScreen();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(1280, 720);
    glutCreateWindow("Graphics");
    glColor3f(0, 0, 0);
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0, 1280, 0, 720);
    glutDisplayFunc(display);
    // glutTimerFunc(1000/60, display, 0);
    glutMainLoop();
    return 0;
}
