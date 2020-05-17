#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enemi.h"
void init_enemi(enemi *e)
{
e->posanime.x=0;
e->posanime.y=0;
e->posanime.w=100;
e->posanime.h=100;
e->pose.x=500;
e->pose.y=500;
e->pose.w=100;
e->pose.h=100;
}
int charger_enemi(enemi *e)
{
e->sprite=IMG_Load("enemi.png");
if(e->sprite==0)
{
printf("unable to load enemi%s\n",SDL_GetError());
return -1 ;
}
return 0;
}
void affiche_enemi(enemi *e,SDL_Surface *screen)
{
SDL_BlitSurface(e->sprite,&e->posanime,screen,&e->pose);
SDL_Flip(screen);
}

