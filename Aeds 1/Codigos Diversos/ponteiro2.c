#include <stdio.h>

int main() {
    int x = 5;
    int y = 6;
    int *px;
    int *py;

    px = &x;
    py = &y;
    px = py;

    (*px) = (*px)*(*px);
    (*py) = (*py) + 4;

    printf("x=%d y=%d", x, y);
}
