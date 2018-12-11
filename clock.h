#include <SDL.h>
#include <math.h>

typedef struct data{
    int originX;
    int originY;
    int *posX;
    int *posY;
    double alpha;
}data_t;

void Rotate(int originX, int originY, int *posX, int *posY,double alpha);

