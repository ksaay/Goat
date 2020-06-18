#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "collision.h"

#define width 1360
#define height 760

#define posXobj1 50 
#define posYobj1 50

#define posXobj2 600
#define posYobj2 80


void init (Objet *objet1,Objet *objet2)
{
 objet1->img=IMG_Load("detective.png");
 objet1->pos.x=posXobj1 ;
 objet1->pos.y=posYobj1 ;
 objet1->w=72;
 objet1->h=144;

 objet2->img=IMG_Load("detective.png") ;
 objet2->pos.x=posXobj2 ;
 objet2->pos.y=posYobj2 ;
 objet2->w=72;
 objet2->h=144; 
 objet2->xg=objet2->pos.x-200;
objet2->xd=objet2->pos.x+200;
}
int distance (Objet *objet1,Objet *objet2)
{
  if((objet1->pos.x>=objet2->xg)&&(objet1->pos.x<=objet2->xd))
    return 1;
  return 0;

}
void setup (SDL_Surface *screen,Objet *objet1,Objet *objet2)
{
 SDL_WM_SetCaption("collision trigo", NULL);
 SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255)) ;
 SDL_BlitSurface(objet1->img,NULL,screen,&(objet1->pos)) ;
 SDL_BlitSurface(objet2->img,NULL,screen,&(objet2->pos)) ;
 SDL_Flip(screen) ;

}
int verif_collision ( Objet *objet1,Objet *objet2 )
{
  int collision=0 ;

  if((objet1->pos.x+objet1->w<objet2->pos.x)||(objet1->pos.x>objet2->pos.x+objet2->w)||(objet1->pos.y+objet1->h<objet2->pos.y)||(objet1->pos.y>objet2->pos.y+objet2->h))
    collision= 1 ;
  
  return collision ;
}

void deplacement_objet(Objet *objet,int *running)
{
  SDL_Event event ;


 
 SDL_PollEvent(&event);
     switch(event.type)
      {
         case SDL_QUIT:
              *running=0;
         break;
         case SDL_KEYDOWN:
              switch(event.key.keysym.sym)
               {
                case SDLK_DOWN:
                    objet->pos.y+=2;
                break;
                case SDLK_UP:
                    objet->pos.y-=2;
                break;
                case SDLK_RIGHT:
                    objet->pos.x+=2;
                break;
                case SDLK_LEFT:
                    objet->pos.x-=2;
                break;
               }
      }
}

void update (SDL_Surface *screen,Objet *objet1,Objet *objet2)
{
  SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255)) ;
  SDL_BlitSurface(objet1->img,NULL,screen,&(objet1->pos)) ;
  SDL_BlitSurface(objet2->img,NULL,screen,&(objet2->pos)) ;
  SDL_Flip(screen) ;
  
}

void liberate_memory (Objet *objet1,Objet *objet2)
{
  SDL_FreeSurface (objet1->img) ;
  SDL_FreeSurface (objet2->img) ;
  SDL_Quit () ;
}
