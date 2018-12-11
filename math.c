#include "clock.h"

void Rotate(int originX, int originY, int *posX, int *posY,double alpha){
    
    double alpha_radiant=alpha*M_PI/180;
    int x=*posX-originX;
    int y = *posY-originY;
    y*=-1;
    int new_coord_x=(int)(round(x*cos(alpha_radiant)-y*sin(alpha_radiant)));
    int new_coord_y=(int)(round(x*sin(alpha_radiant)+y*cos(alpha_radiant)));
    new_coord_y*=-1;
    new_coord_x+=originX;
    new_coord_y+=originY;        
    *posX= new_coord_x;
    *posY=new_coord_y;
    
}
