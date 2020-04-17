#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include "deplacement.h"

#define width 1600 
#define height 400

#define posXobj1 500 
#define posYobj1 300



void init (SDL_Surface *screen,Objet *objet1,Objet *objet2)
{
 objet1->img=IMG_Load("pokemon.png");
 objet1->pos.x=posXobj1 ;
 objet1->pos.y=posYobj1 ;

 objet2->img=SDL_LoadBMP("background.bmp") ;
 objet2->pos.x=0 ;
 objet2->pos.y=0 ;
 SDL_BlitSurface(objet2->img,NULL,screen, &objet2->pos);
 SDL_BlitSurface(objet1->img,NULL,screen, &objet1->pos);
 SDL_Flip(screen);

}




void deplacement_objet(SDL_Surface *screen,Objet *objet1,Objet *objet2)
{
  int a=0;
  int b=1;
 if((objet1->pos.x!=1050)&&(a==0)&&(b==1))
{
  objet1->pos.x+=5;

SDL_BlitSurface(objet2->img,NULL,screen, &objet2->pos);
SDL_BlitSurface(objet1->img,NULL,screen, &objet1->pos);
SDL_Flip(screen);
}
else
{ 
a=1;
b=0;
}

  if((objet1->pos.x!=400)&&(a==1)&&(b==0))
{
  objet1->pos.x-=5;


SDL_BlitSurface(objet2->img,NULL,screen, &objet2->pos);
SDL_BlitSurface(objet1->img,NULL,screen, &objet1->pos);
SDL_Flip(screen);
}
else
{
a=0;
b=1;
}
}

void liberate_memory (Objet *objet1,Objet *objet2)
{
  SDL_FreeSurface (objet1->img) ;
  SDL_FreeSurface (objet2->img) ;
  SDL_Quit () ;
}
