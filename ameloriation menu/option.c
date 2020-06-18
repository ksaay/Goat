#include "SDL/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "function.h"


void option(SDL_Surface* screen){
//The images
    SDL_Surface *image = NULL;
    SDL_Surface *image2 = NULL,*v0=NULL,*v1=NULL,*v2=NULL,*v3=NULL,*v4=NULL;
    SDL_Rect positionecran;
    SDL_Rect position2ecran;
  SDL_Rect position;
int a=0;
int b=0;

//Start SDL
    if(SDL_Init( SDL_INIT_VIDEO )!=0)
      {
        printf("Unable to initialize SDL: %s\n",SDL_GetError());
      }
//Set up screen
    screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
     if(screen == NULL)
      {
        printf("Unable to set video mode: %s",SDL_GetError());
      }

   image = IMG_Load("s.jpg");
   v0= IMG_Load("vol0.png");

     if(image == NULL)
       {
         printf("Unable to load bitmap: %s\n",SDL_GetError());
       }
   positionecran.x=0;
   positionecran.y=0;
   positionecran.w=image->w;
   positionecran.h=image->h;
position.x=190;
position.y=100;
   

   SDL_BlitSurface(image,NULL,screen,&positionecran);


     
//SDL_SetColorKey(v0,SDL_RLEACCEL | SDL_SRCCOLORKEY, SDL_MapRGB(v0->format,255,255,255));
  position2ecran.x=190;
   position2ecran.y=0;



SDL_Event event;
int continuer=1;
int i=0,j=0;
int p=3;

while(continuer){
   SDL_BlitSurface(image,&positionecran,screen,NULL);



if(p==1){
v0= IMG_Load("vol0.png");
      SDL_BlitSurface(v0,&positionecran,screen,&position2ecran);
Mix_VolumeMusic(0);
 }
if(p==2){
   v0 = IMG_Load("vol1.png");
      SDL_BlitSurface(v0,&positionecran,screen,&position2ecran);
Mix_VolumeMusic(30);
 }
if(p==3){
   v0 = IMG_Load("vol2.png");
      SDL_BlitSurface(v0,&positionecran,screen,&position2ecran);
Mix_VolumeMusic(60);
 }
if(p==4){
   v0 = IMG_Load("vol3.png");
      SDL_BlitSurface(v0,&positionecran,screen,&position2ecran);
Mix_VolumeMusic(90);
 }
if(p==5){
   v0 = IMG_Load("vol4.png");
      SDL_BlitSurface(v0,&positionecran,screen,&position2ecran);
Mix_VolumeMusic(130);
 }







SDL_WaitEvent(&event);
switch(event.type){

case SDL_QUIT:
continuer = 0;
break;

case SDL_KEYDOWN:
            {
               if(event.key.keysym.sym == SDLK_ESCAPE) 
               {
               continuer = 0;
               break;
               }
 if((event.key.keysym.sym == SDLK_a)&&(p<=4))
               { p++;

               }
 if((event.key.keysym.sym == SDLK_z)&&(p>=2))
               {
               p--;
               }     
if(event.key.keysym.sym == SDLK_f)
               {

if(a==0)
{
    screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_FULLSCREEN);
   a=1;
}
else if (a==1)
{
screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE );
a=0;
}
case SDL_MOUSEBUTTONDOWN:
b=1;
if((event.button.button==SDL_BUTTON_LEFT)&&(b==1))
    {
case SDL_MOUSEMOTION:
if((((position.x+200)<=event.motion.x)&&((position.x+300)>=event.motion.x))&&(((position.y+10)<=event.motion.y)&&((position.y+80)>=event.motion.y))&&(b==1))
{
p=1;
}
else if((((position.x+250)<=event.motion.x)&&((position.x+370)>=event.motion.x))&&(((position.y+10)<=event.motion.y)&&((position.y+80)>=event.motion.y))&&(b==1))
{ 
p=2;
}
else if((((position.x+300)<=event.motion.x)&&((position.x+450)>=event.motion.x))&&(((position.y+10)<=event.motion.y)&&((position.y+80)>=event.motion.y))&&(b==1))
{ 
p=3;
}
else if((((position.x+350)<=event.motion.x)&&((position.x+570)>=event.motion.x))&&(((position.y+10)<=event.motion.y)&&((position.y+80)>=event.motion.y))&&(b==1))
{ 
p=4;
}
else if((((position.x+400)<=event.motion.x)&&((position.x+630)>=event.motion.x))&&(((position.y+10)<=event.motion.y)&&((position.y+80)>=event.motion.y))&&(b==1))
{ 
p=5;
}

break;

}
case SDL_MOUSEBUTTONUP:
b=0;
break;
b=0;
break;

               }                  

             }
             
 }
    


SDL_Flip(screen);

}
  /* SDL_FillRect(screen,0,SDL_MapRGB(screen->format,255,255,0));*/
    
    // pause=getchar();

    SDL_FreeSurface(screen);    
    SDL_FreeSurface(image);
        SDL_FreeSurface(v0);
        SDL_FreeSurface(v1);
        SDL_FreeSurface(v2);
        SDL_FreeSurface(v3);
        SDL_FreeSurface(v4);
  //  pause=getchar();

}
