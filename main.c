#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"enigme2.h"
int main (void)
{
int continuer=1;
SDL_Surface *screen = NULL;
SDL_Surface *image,*background, *image1,*image2= NULL;
screen = SDL_SetVideoMode(700, 400, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
afficheenigme(screen);
reponsenigme(screen);

SDL_FreeSurface(background);
SDL_FreeSurface(image);
SDL_FreeSurface(image1);
SDL_FreeSurface(image2);

SDL_QuitSubSystem(SDL_INIT_VIDEO);
return 0;
}
