#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "enemi.h"

int main(void){
SDL_Surface *screen = NULL;
SDL_Event event;
enemi e;
int t=1,z;
char pause;
SDL_Init(SDL_INIT_VIDEO);
screen = SDL_SetVideoMode(680, 480, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
if (!screen){
printf("Unable to set 600x400 video: %s\n",SDL_GetError());
return(-1);
}
SDL_FillRect(screen, 0,SDL_MapRGB(screen->format,255 ,255, 0));
SDL_Flip(screen);
init_enemi(&e);
z=charger_enemi(&e);
affiche_enemi(&e,screen);
while(t==1)
{
SDL_WaitEvent(&event);
switch(event.type)
{case SDL_QUIT:
t=0;
break;
case SDL_KEYDOWN:
switch (event.key.keysym.sym)
{
case SDLK_ESCAPE:
t=0;
break;
}
break;
}
affiche_enemi(&e,screen);
}
SDL_Quit();
return 0;
}
