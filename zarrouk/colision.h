#ifndef FONCTION_H_
#define FONCTION_H_


#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

int colision_perfectp(perso p,SDL_Surface *background);
SDL_Color GetPixel(SDL_Surface *surface,int x,int y);
int deplacement_sourie(perso p,int click);


#endif
