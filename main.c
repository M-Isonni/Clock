#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "clock.h"
#include <time.h>

#define WIDTH 800
#define HEIGHT 600

//will wait for the specified seconds before executing the code after this function
static void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;   
    while (time(0) < retTime);               
}

int main(int argc,char **argv){
    
int ret=0;
int is_running=1;
//initializing video
if(SDL_Init(SDL_INIT_VIDEO)){
		SDL_Log("init error %s",SDL_GetError());
		ret = -1;
		goto cleanup;
}

//creating window
SDL_Window *window=SDL_CreateWindow("window",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WIDTH,HEIGHT,0);
if(!window){
		SDL_Log("window error %s",SDL_GetError());
		ret=-1;
		goto cleanup2;
}

//creating renderer
SDL_Renderer *renderer = SDL_CreateRenderer(window,0,SDL_RENDERER_PRESENTVSYNC|SDL_RENDERER_ACCELERATED);
if(!renderer){
		SDL_Log("renderer error %s",SDL_GetError());
		SDL_DestroyWindow(window);
		ret=-1;
		goto cleanup3;
}
//declaring final line posizion
int posX=WIDTH/2;
int posY=0;
//rotation angle for each second
int alpha=-360/60;

while(is_running)
{
	SDL_Event event;
    while(SDL_PollEvent(&event))
	{
		if(event.type==SDL_QUIT)
		{
			goto cleanup4;
		}	
	}
	//at each loop it waits 1 second
    waitFor(1);  
	//rotate the lancet  
    Rotate(WIDTH/2,HEIGHT/2,&posX,&posY,alpha);
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_RenderDrawLine(renderer,WIDTH/2,HEIGHT/2,posX,posY);
	SDL_RenderPresent(renderer);
}

    cleanup4:
	SDL_DestroyRenderer(renderer);
cleanup3:
	SDL_DestroyWindow(window);
cleanup2:
	SDL_Quit();
cleanup:
	return ret;
  
}