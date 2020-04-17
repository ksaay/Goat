#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include "deppers.h"

#define width 1600
#define height 400

#define posXobj1 800 
#define posYobj1 200



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




void deplacement_objet(SDL_Event event,SDL_Surface *screen,Objet *objet1,Objet *objet2)
{
   SDL_BlitSurface(objet2->img,NULL,screen, &objet2->pos);
    SDL_BlitSurface(objet1->img,NULL,screen, &objet1->pos);

    SDL_Flip(screen);
    if(SDL_PollEvent(&event))
    {
     switch(event.type)
     {
        case SDL_KEYDOWN:
          if((event.key.keysym.sym == SDLK_LEFT )|| (event.key.keysym.sym ==SDLK_a))
          {
           objet1->pos.x-= 5;
           SDL_BlitSurface(objet1->img,NULL,screen, &objet1->pos);
         }
          if((event.key.keysym.sym == SDLK_RIGHT)|| (event.key.keysym.sym ==SDLK_d))
          {
            objet1->pos.x+=5;
           SDL_BlitSurface(objet1->img,NULL,screen, &objet1->pos);
         }
         if((event.key.keysym.sym == SDLK_UP)|| (event.key.keysym.sym ==SDLK_w))
          {
           
          objet1->pos.y-= 5;
            SDL_BlitSurface(objet1->img,NULL,screen, &objet1->pos);
         }
          if((event.key.keysym.sym == SDLK_DOWN)|| (event.key.keysym.sym ==SDLK_s))
          {
          objet1->pos.y+=5;
            //affichage d image
            SDL_BlitSurface(objet1->img,NULL,screen, &objet1->pos);
         }
        break; 
        /*case SDL_QUIT:

        break;*/
      }
    }
}

void liberate_memory (Objet *objet1,Objet *objet2)
{
  SDL_FreeSurface (objet1->img) ;
  SDL_FreeSurface (objet2->img) ;
  SDL_Quit () ;
}
