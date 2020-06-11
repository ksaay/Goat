#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "multijoueur.h"
#include "scrolling.h"
#include "min2.h"
int main()
{
perso p1,p2;
SDL_Event event;
SDL_Surface * screen=NULL;
SDL_Init(SDL_INIT_VIDEO);
screen = SDL_SetVideoMode(1600, 800, 32, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
gestion_evenement( event,&p1,&p2,screen);
SDL_Quit();
return 0;
}

