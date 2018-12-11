#define SDL_MAIN_HANDLED
#include "aiv_unit_test.h"
#include "clock.h"
#include <stdlib.h>

TEST(rotate)
{
    int originX=0;
    int originY=1;
    int *posX= malloc(sizeof(int));
    int *posY= malloc(sizeof(int));
    *posY=0;
    *posX=0;
    double alpha=-90;
	Rotate(originX,originY,posX,posY,alpha);
	ASSERT_THAT(*posX==1);
}

int main(int argc, char **argv)
{	
	RUN_TEST(rotate);
	PRINT_TEST_RESULTS();
	return 0;
}