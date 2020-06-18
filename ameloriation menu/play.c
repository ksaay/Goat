#include "SDL/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "function.h"


void play(SDL_Surface* screen){
//The images
    SDL_Surface *image = NULL;
    SDL_Surface *image2 = NULL;
    SDL_Rect positionecran;
    SDL_Rect position2ecran;

//Start SDL
    if(SDL_Init( SDL_INIT_VIDEO )!=0)
      {
        printf("Unable to initialize SDL: %s\n",SDL_GetError());
      };
//Set up screen
    screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
     if(screen == NULL)
      {
        printf("Unable to set video mode: %s",SDL_GetError());
      }

   image = IMG_Load("blood.jpg");
     if(image == NULL)
       {
         printf("Unable to load bitmap: %s\n",SDL_GetError());
       }
   positionecran.x=0;
   positionecran.y=0;
   positionecran.w=image->w;
   positionecran.h=image->h;
   

   SDL_BlitSurface(image,NULL,screen,&positionecran);

        image2 = IMG_Load("ball.png");
     if(image2 == NULL)
       {
         printf("Unable to load png: %s\n",SDL_GetError());
       }
SDL_SetColorKey(image2,SDL_RLEACCEL | SDL_SRCCOLORKEY, SDL_MapRGB(image2->format,255,255,255));
  position2ecran.x=300;
   position2ecran.y=150;
   position2ecran.w=image2->w;
   position2ecran.h=image2->h;

SDL_Event event;
int continuer=1;
int i=0,j=0;


while(continuer){
   SDL_BlitSurface(image,&positionecran,screen,NULL);
      SDL_BlitSurface(image2,&positionecran,screen,&position2ecran);

SDL_WaitEvent(&event);
switch(event.type){

case SDL_QUIT:
continuer = 0;
break;

case SDL_KEYDOWN:
            {
               if(event.key.keysym.sym == SDLK_ESCAPE)
               continuer = 0;
                else if (event.key.keysym.sym == SDLK_LEFT)
                   position2ecran.x -=6;
  else if (event.key.keysym.sym == SDLK_RIGHT)
                   position2ecran.x +=6;
 else if (event.key.keysym.sym == SDLK_UP)
                   position2ecran.y -=6;
 else if (event.key.keysym.sym == SDLK_DOWN)
                   position2ecran.y +=6;
               break;
            }
             
        }
    


SDL_Flip(screen);

}
  /* SDL_FillRect(screen,0,SDL_MapRGB(screen->format,255,255,0));*/
    
    // pause=getchar();

    SDL_FreeSurface(screen);    
    SDL_FreeSurface(image);
    SDL_FreeSurface(screen);
    SDL_FreeSurface(image2);
    
  //  pause=getchar();

}
