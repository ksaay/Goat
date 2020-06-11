#ifndef FONCTION2_H_
#define FONCTION2_H_


#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
//#include "mini.h"

typedef struct 
{
SDL_Surface *map;
SDL_Rect posmap;
}ma;
typedef struct 
{
SDL_Surface *mini;
SDL_Rect posmini;
}mi;
mi minimappre(perso p1,mi m2);
mi minimapdeu(perso p2,mi m3);
void affichemap(SDL_Surface * screen,ma m1,mi m2,mi m3);
#endif
