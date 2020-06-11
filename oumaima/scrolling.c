#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "scrolling.h"

void initialiser (Objet *map ,Objet *d ) 
{
  SDL_WM_SetCaption("scrolling", NULL);

  map->img=IMG_Load("back.png") ;
  map->pos.x=0 ;
  map->pos.y=0 ;

  d->img=IMG_Load("detective.png") ;
  d->pos.x=xd ;
  d->pos.y=yd ;
  d->w1=wd;
  d->h1=hd;
  SDL_SetColorKey(d->img,SDL_SRCCOLORKEY,SDL_MapRGB(d->img->format,255,255,255));
 
}
void setup (SDL_Surface *screen, Objet *map , Objet *d)
{
  SDL_BlitSurface(map->img,NULL,screen, &(map->pos));
  SDL_BlitSurface(d->img,NULL, screen, &(d->pos)) ;
  SDL_Flip(screen) ;
}

void scrolling_droit (SDL_Surface *screen , Objet *map, Objet *d)
{
 if (map->pos.x<=mapw)
  {
   map->pos.x+=20 ; 
  }
   SDL_BlitSurface(map->img,&(map->pos),screen, NULL);
}
void scrolling_gauche (SDL_Surface*screen , Objet *map, Objet *d) 
{
 if (map->pos.x>=0)
  {
   map->pos.x-=20 ;
  }
 SDL_BlitSurface(map->img,&(map->pos),screen, NULL);  
}
void deplacement_objet( Objet *map,SDL_Surface *screen ,Objet *d,int *running,int *test)
{
  SDL_Event event ;

 SDL_WaitEvent(&event);
     switch(event.type)
      {
         case SDL_QUIT:
              *running=0;
         break;
         case SDL_KEYDOWN:
              switch(event.key.keysym.sym)
               {
                case SDLK_DOWN:
                    d->pos.y+=5;
                    SDL_BlitSurface(map->img,&(map->pos),screen, NULL);
                    SDL_BlitSurface(d->img,NULL, screen, &(d->pos)) ;
                    SDL_Flip(screen) ;
                break;
                case SDLK_UP:
                    d->pos.y-=5;
                    SDL_BlitSurface(map->img,&(map->pos),screen, NULL);
                    SDL_BlitSurface(d->img,NULL, screen, &(d->pos)) ;
                    SDL_Flip(screen) ;
                break;
                case SDLK_RIGHT:
                    d->pos.x++;
                    SDL_BlitSurface(map->img,&(map->pos),screen, NULL);
                    SDL_BlitSurface(d->img,NULL, screen, &(d->pos)) ;
                    SDL_Flip(screen) ;
                break;
                case SDLK_LEFT:
                    d->pos.x--;
                    SDL_BlitSurface(map->img,&(map->pos),screen, NULL);
                    SDL_BlitSurface(d->img,NULL, screen, &(d->pos)) ;
                    SDL_Flip(screen) ;
                break;
               }
      }
  if (d->pos.x==200)
  {
    *test=1;
  }
}

void evenement (SDL_Surface *screen ,Objet *map,int *running , Objet *d)
{
 SDL_Event event;

 SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                *running = 0;
            break;
            case SDL_KEYDOWN:

               switch(event.key.keysym.sym)

                  {

                     case SDLK_RIGHT: // Flèche droite 
      	         
                          scrolling_droit (screen ,map,d) ;
                          SDL_BlitSurface(d->img,NULL, screen, &(d->pos)) ;
                            SDL_Flip(screen) ;
                     break;

                     case SDLK_LEFT: // Flèche gauche
                       
                          scrolling_gauche (screen ,map,d) ;
                          SDL_BlitSurface(d->img,NULL, screen, &(d->pos)) ;
                            SDL_Flip(screen) ;
                     break;
              

                  }

            break;    
        }

}

void free_memory (Objet *map, Objet *d)
{
 SDL_FreeSurface (map->img) ;
 SDL_FreeSurface (d->img) ;
 SDL_Quit () ;

}
