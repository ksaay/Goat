#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL/SDL_ttf.h"
int main (void)
{
int aa=0;
SDL_Rect sposcadre;
SDL_Surface *cadre;
SDL_Rect poscadre;
SDL_Rect poscadre1;
SDL_Rect poscadre2;
SDL_Rect poscadre3;
SDL_Surface *screen;
  SDL_Surface *image1;
  SDL_Surface *image2;
  SDL_Surface *image3;
  SDL_Rect positionecran;
  char pause;
  int done=1;
int i=0;
int k;
int b=0;
int o=0;
  SDL_Event event;
  SDL_Rect posbg;
 SDL_Surface *stexte = NULL;
 SDL_Surface *texte = NULL;
 SDL_Surface *texte2 = NULL;
SDL_Surface *atexte = NULL;
 SDL_Surface *atexte2 = NULL;
SDL_Surface *btexte = NULL;
 SDL_Surface *btexte2 = NULL;
SDL_Surface *ctexte = NULL;
 SDL_Surface *ctexte2 = NULL;
 TTF_Font *police=NULL;
 SDL_Color couleurNoire ={255,255,255};
SDL_Color new ={0,0,0};
  SDL_Rect s1position;
  SDL_Rect position;
  SDL_Rect aposition;
  SDL_Rect bposition;
  SDL_Rect cposition;
  Mix_Music *music;
      Mix_Chunk *son;
      Mix_Chunk *son2;
void animation();
SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
TTF_Init();


  screen = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
  if(!screen)
  {
      printf("Error 2: %s\n",SDL_GetError());

  }

  if(SDL_Init(SDL_INIT_VIDEO)!=0)
  {
      printf("Error: %s\n",SDL_GetError());

  }
SDL_WM_SetCaption("Corona",NULL);
 Mix_AllocateChannels(10);
  image1 = IMG_Load("background1.bmp");
  image2 = IMG_Load("background2.bmp");
  image3 = IMG_Load("backround3.bmp");
cadre=IMG_Load("bottom1.bmp");
police = TTF_OpenFont("Oswald-Medium.ttf",50);
stexte = TTF_RenderText_Blended(police,"back",couleurNoire);
texte = TTF_RenderText_Blended(police,"Play",couleurNoire);
texte2 = TTF_RenderText_Blended(police,"Play",new);
atexte = TTF_RenderText_Blended(police,"Settings",couleurNoire);
atexte2 = TTF_RenderText_Blended(police,"Settings",new);
btexte = TTF_RenderText_Blended(police,"Credits",couleurNoire);
btexte2 = TTF_RenderText_Blended(police,"Credits",new);
ctexte = TTF_RenderText_Blended(police,"Exit",couleurNoire);
ctexte2 = TTF_RenderText_Blended(police,"Exit",new);
music = Mix_LoadMUS("music.mp3");


  //Mix_PlayMusic(music,-1);
 
  if(!image1)
  {
     printf("Error: %s\n",SDL_GetError());

  }
 sposcadre.x=260;
 sposcadre.y=100;
   s1position.x = 330;
   s1position.y = 90;
  positionecran.x = 0;    
  positionecran.y = 0;    
 // positionecran.h = image->h; 
poscadre.x=40;
poscadre.y=110;
poscadre1.x=40;
poscadre1.y=210;
poscadre2.x=40;
poscadre2.y=310;
poscadre3.x=40;
poscadre3.y=410;
 // positionecran.w = image->w; 
position.x=117;
position.y=100; 
aposition.x=75;
aposition.y=200;
bposition.x=85;
bposition.y=300;
cposition.x=118;
cposition.y=400;
SDL_BlitSurface(image1,NULL,screen,&positionecran);

SDL_BlitSurface(cadre,NULL,screen,&poscadre);
SDL_BlitSurface(cadre,NULL,screen,&poscadre1);
SDL_BlitSurface(cadre,NULL,screen,&poscadre2);
SDL_BlitSurface(cadre,NULL,screen,&poscadre3);
SDL_BlitSurface(texte,NULL,screen,&position);
SDL_BlitSurface(atexte,NULL,screen,&aposition);
SDL_BlitSurface(btexte,NULL,screen,&bposition);
SDL_BlitSurface(ctexte,NULL,screen,&cposition); 

 if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    printf("Error : %s",Mix_GetError());
  music = Mix_LoadMUS("music.mp3");
 Mix_PlayMusic(music,-1);
Mix_AllocateChannels(1);
      Mix_Volume(1, MIX_MAX_VOLUME);
      son = Mix_LoadWAV("bang_1.wav");   
   son2= Mix_LoadWAV("pop1.wav");
      Mix_VolumeChunk(son, MIX_MAX_VOLUME);
      Mix_VolumeChunk(son2, MIX_MAX_VOLUME);
//SDL_BlitSurface(texte2,NULL,screen,&position);
    SDL_Flip(screen);
 /*if (o==0){
while(1)
{
SDL_BlitSurface(image1,NULL,screen,&positionecran);SDL_BlitSurface(cadre,NULL,screen,&poscadre);
SDL_BlitSurface(cadre,NULL,screen,&poscadre1);
SDL_BlitSurface(cadre,NULL,screen,&poscadre2);
SDL_BlitSurface(cadre,NULL,screen,&poscadre3);
SDL_BlitSurface(texte,NULL,screen,&position);
SDL_BlitSurface(atexte,NULL,screen,&aposition);
SDL_BlitSurface(btexte,NULL,screen,&bposition);
SDL_BlitSurface(ctexte,NULL,screen,&cposition);
SDL_Flip(screen);
//SDL_Delay(150);

SDL_BlitSurface(image2,NULL,screen,&positionecran);
SDL_BlitSurface(cadre,NULL,screen,&poscadre);
SDL_BlitSurface(cadre,NULL,screen,&poscadre1);
SDL_BlitSurface(cadre,NULL,screen,&poscadre2);
SDL_BlitSurface(cadre,NULL,screen,&poscadre3);
SDL_BlitSurface(texte,NULL,screen,&position);
SDL_BlitSurface(atexte,NULL,screen,&aposition);
SDL_BlitSurface(btexte,NULL,screen,&bposition);
SDL_BlitSurface(ctexte,NULL,screen,&cposition);
SDL_Flip(screen);
//SDL_Delay(140);

SDL_BlitSurface(image3,NULL,screen,&positionecran);
SDL_BlitSurface(cadre,NULL,screen,&poscadre);
SDL_BlitSurface(cadre,NULL,screen,&poscadre1);
SDL_BlitSurface(cadre,NULL,screen,&poscadre2);
SDL_BlitSurface(cadre,NULL,screen,&poscadre3);
SDL_BlitSurface(texte,NULL,screen,&position);
SDL_BlitSurface(atexte,NULL,screen,&aposition);
SDL_BlitSurface(btexte,NULL,screen,&bposition);
SDL_BlitSurface(ctexte,NULL,screen,&cposition);
SDL_Flip(screen);
}
}*/

  while(done==1)
  {
o=0;

//SDL_Delay(140);

SDL_WaitEvent(&event);
switch(event.type)
{
case SDL_QUIT:
done=0;
break;
case SDL_MOUSEMOTION:
if((((position.x-80)<=event.motion.x)&&((position.x+140)>=event.motion.x))&&(((position.y+10)<=event.motion.y)&&((position.y+80)>=event.motion.y)))
{
i=1;
/*o=1;
SDL_BlitSurface(image1,NULL,screen,&positionecran);SDL_BlitSurface(cadre,NULL,screen,&poscadre);
SDL_BlitSurface(cadre,NULL,screen,&poscadre1);
SDL_BlitSurface(cadre,NULL,screen,&poscadre2);
SDL_BlitSurface(cadre,NULL,screen,&poscadre3);
SDL_BlitSurface(texte2,NULL,screen,&position);
SDL_BlitSurface(atexte,NULL,screen,&aposition);
SDL_BlitSurface(btexte,NULL,screen,&bposition);
SDL_BlitSurface(ctexte,NULL,screen,&cposition);
SDL_Flip(screen);
//SDL_Delay(150);

SDL_BlitSurface(image2,NULL,screen,&positionecran);
SDL_BlitSurface(cadre,NULL,screen,&poscadre);
SDL_BlitSurface(cadre,NULL,screen,&poscadre1);
SDL_BlitSurface(cadre,NULL,screen,&poscadre2);
SDL_BlitSurface(cadre,NULL,screen,&poscadre3);
SDL_BlitSurface(texte2,NULL,screen,&position);
SDL_BlitSurface(atexte,NULL,screen,&aposition);
SDL_BlitSurface(btexte,NULL,screen,&bposition);
SDL_BlitSurface(ctexte,NULL,screen,&cposition);
SDL_Flip(screen);
//SDL_Delay(140);*/

SDL_BlitSurface(image1,NULL,screen,&positionecran);
SDL_BlitSurface(cadre,NULL,screen,&poscadre);
SDL_BlitSurface(cadre,NULL,screen,&poscadre1);
SDL_BlitSurface(cadre,NULL,screen,&poscadre2);
SDL_BlitSurface(cadre,NULL,screen,&poscadre3);
SDL_BlitSurface(texte2,NULL,screen,&position);
SDL_BlitSurface(atexte,NULL,screen,&aposition);
SDL_BlitSurface(btexte,NULL,screen,&bposition);
SDL_BlitSurface(ctexte,NULL,screen,&cposition);
SDL_Flip(screen);
//SDL_Delay(140);

b=0;
                       Mix_PlayChannel(0, son, 0);
}
else if((((position.x-80)<=event.motion.x)&&((position.x+140)>=event.motion.x))&&(((position.y+10)<=event.motion.y)&&((position.y+177)>=event.motion.y)))
{i=2;
SDL_BlitSurface(image1,NULL,screen,&positionecran);
SDL_BlitSurface(cadre,NULL,screen,&poscadre);
SDL_BlitSurface(cadre,NULL,screen,&poscadre1);
SDL_BlitSurface(cadre,NULL,screen,&poscadre2);
SDL_BlitSurface(cadre,NULL,screen,&poscadre3);
SDL_BlitSurface(texte,NULL,screen,&position);
SDL_BlitSurface(atexte2,NULL,screen,&aposition);
SDL_BlitSurface(btexte,NULL,screen,&bposition);
SDL_BlitSurface(ctexte,NULL,screen,&cposition);
SDL_Flip(screen);
b=1;
                       Mix_PlayChannel(0, son, 0);
}
else if((((position.x-80)<=event.motion.x)&&((position.x+140)>=event.motion.x))&&(((position.y+10)<=event.motion.y)&&((position.y+274)>=event.motion.y)))
{
i=3;
SDL_BlitSurface(image1,NULL,screen,&positionecran);
SDL_BlitSurface(cadre,NULL,screen,&poscadre);
SDL_BlitSurface(cadre,NULL,screen,&poscadre1);
SDL_BlitSurface(cadre,NULL,screen,&poscadre2);
SDL_BlitSurface(cadre,NULL,screen,&poscadre3);
SDL_BlitSurface(texte,NULL,screen,&position);
SDL_BlitSurface(atexte,NULL,screen,&aposition);
SDL_BlitSurface(btexte2,NULL,screen,&bposition);
SDL_BlitSurface(ctexte,NULL,screen,&cposition);
SDL_Flip(screen);
b=2;
                       Mix_PlayChannel(0, son, 0);
}
else if((((position.x-80)<=event.motion.x)&&((position.x+140)>=event.motion.x))&&(((position.y+10)<=event.motion.y)&&((position.y+371)>=event.motion.y)))
{
i=4;
SDL_BlitSurface(image1,NULL,screen,&positionecran);
SDL_BlitSurface(cadre,NULL,screen,&poscadre);
SDL_BlitSurface(cadre,NULL,screen,&poscadre1);
SDL_BlitSurface(cadre,NULL,screen,&poscadre2);
SDL_BlitSurface(cadre,NULL,screen,&poscadre3);
SDL_BlitSurface(texte,NULL,screen,&position);
SDL_BlitSurface(atexte,NULL,screen,&aposition);
SDL_BlitSurface(btexte,NULL,screen,&bposition);
SDL_BlitSurface(ctexte2,NULL,screen,&cposition);
SDL_Flip(screen);
b=3;
                       Mix_PlayChannel(0, son, 0);
}
else
{
//SDL_ShowCursor(SDL_ENABLE);
SDL_BlitSurface(image1,NULL,screen,&positionecran);
SDL_BlitSurface(cadre,NULL,screen,&poscadre);
SDL_BlitSurface(cadre,NULL,screen,&poscadre1);
SDL_BlitSurface(cadre,NULL,screen,&poscadre2);
SDL_BlitSurface(cadre,NULL,screen,&poscadre3);
SDL_BlitSurface(texte,NULL,screen,&position);
SDL_BlitSurface(atexte,NULL,screen,&aposition);
SDL_BlitSurface(btexte,NULL,screen,&bposition);
SDL_BlitSurface(ctexte,NULL,screen,&cposition);
    SDL_Flip(screen);
b=4;
}

break;
case SDL_MOUSEBUTTONDOWN:
if((event.button.button==SDL_BUTTON_LEFT)&&b==0)
{
while(aa==0)

 {                       Mix_PlayChannel(0, son2, 0);
SDL_BlitSurface(image1,NULL,screen,&positionecran);
SDL_BlitSurface(cadre,NULL,screen,&sposcadre);
SDL_BlitSurface(stexte,NULL,screen,&s1position);
SDL_Flip(screen);
SDL_WaitEvent(&event);
switch(event.type)
   {
case SDL_MOUSEBUTTONDOWN:
if(event.button.button==SDL_BUTTON_LEFT)
    {
 aa=1;
    }

break;
  }
 }
aa=0;
}
else if((event.button.button==SDL_BUTTON_LEFT)&&b==1)
{  while(aa==0)

 {                       Mix_PlayChannel(0, son2, 0);
SDL_BlitSurface(image1,NULL,screen,&positionecran);
SDL_BlitSurface(cadre,NULL,screen,&sposcadre);
SDL_BlitSurface(stexte,NULL,screen,&s1position);
SDL_Flip(screen);
SDL_WaitEvent(&event);
switch(event.type)
   {
case SDL_MOUSEBUTTONDOWN:
if(event.button.button==SDL_BUTTON_LEFT)
    {
 aa=1;
    }

break;
  }
 }
aa=0;
}

else if((event.button.button==SDL_BUTTON_LEFT)&&b==2)
{
                       while(aa==0)

 {                       Mix_PlayChannel(0, son2, 0);
SDL_BlitSurface(image1,NULL,screen,&positionecran);
SDL_BlitSurface(cadre,NULL,screen,&sposcadre);
SDL_BlitSurface(stexte,NULL,screen,&s1position);
SDL_Flip(screen);
SDL_WaitEvent(&event);
switch(event.type)
   {
case SDL_MOUSEBUTTONDOWN:
if(event.button.button==SDL_BUTTON_LEFT)
    {
 aa=1;
    }

break;
  }
 }
aa=0;

}else if((event.button.button==SDL_BUTTON_LEFT)&&b==3)
{
                       Mix_PlayChannel(0, son2, 0);
done=0;
}
break;
//case SDL_KEYDOWN:
//switch(event.key.keysym.sym)
case SDL_KEYDOWN:
switch (event.key.keysym.sym)
{
 case SDLK_DOWN:
if( i==0)
{
SDL_BlitSurface(image1,NULL,screen,&positionecran);
SDL_BlitSurface(cadre,NULL,screen,&poscadre);
SDL_BlitSurface(cadre,NULL,screen,&poscadre1);
SDL_BlitSurface(cadre,NULL,screen,&poscadre2);
SDL_BlitSurface(cadre,NULL,screen,&poscadre3);
SDL_BlitSurface(texte2,NULL,screen,&position);
SDL_BlitSurface(atexte,NULL,screen,&aposition);
SDL_BlitSurface(btexte,NULL,screen,&bposition);
SDL_BlitSurface(ctexte,NULL,screen,&cposition);
SDL_Flip(screen);
i++;
k=0;
                       Mix_PlayChannel(0, son, 0);
}
else if(i== 1)
{
SDL_BlitSurface(image1,NULL,screen,&positionecran);
SDL_BlitSurface(cadre,NULL,screen,&poscadre);
SDL_BlitSurface(cadre,NULL,screen,&poscadre1);
SDL_BlitSurface(cadre,NULL,screen,&poscadre2);
SDL_BlitSurface(cadre,NULL,screen,&poscadre3);
SDL_BlitSurface(texte,NULL,screen,&position);
SDL_BlitSurface(atexte2,NULL,screen,&aposition);
SDL_BlitSurface(btexte,NULL,screen,&bposition);
SDL_BlitSurface(ctexte,NULL,screen,&cposition);
SDL_Flip(screen);
i++;
k=1;
                       Mix_PlayChannel(0, son, 0);
}
else if(i== 2 )
{
SDL_BlitSurface(image1,NULL,screen,&positionecran);
SDL_BlitSurface(cadre,NULL,screen,&poscadre);
SDL_BlitSurface(cadre,NULL,screen,&poscadre1);
SDL_BlitSurface(cadre,NULL,screen,&poscadre2);
SDL_BlitSurface(cadre,NULL,screen,&poscadre3);
SDL_BlitSurface(texte,NULL,screen,&position);
SDL_BlitSurface(atexte,NULL,screen,&aposition);
SDL_BlitSurface(btexte2,NULL,screen,&bposition);
SDL_BlitSurface(ctexte,NULL,screen,&cposition);
SDL_Flip(screen);
i++;
k=2;
                       Mix_PlayChannel(0, son, 0);
}
else if(i== 3 )
{
SDL_BlitSurface(image1,NULL,screen,&positionecran);
SDL_BlitSurface(cadre,NULL,screen,&poscadre);
SDL_BlitSurface(cadre,NULL,screen,&poscadre1);
SDL_BlitSurface(cadre,NULL,screen,&poscadre2);
SDL_BlitSurface(cadre,NULL,screen,&poscadre3);
SDL_BlitSurface(texte,NULL,screen,&position);
SDL_BlitSurface(atexte,NULL,screen,&aposition);
SDL_BlitSurface(btexte,NULL,screen,&bposition);
SDL_BlitSurface(ctexte2,NULL,screen,&cposition);
SDL_Flip(screen);
k=3;
i=0;
                       Mix_PlayChannel(0, son, 0);
}

break;
case SDLK_RETURN:
if(k==0)
{
while(aa==0)

 {                       Mix_PlayChannel(0, son2, 0);
SDL_BlitSurface(image1,NULL,screen,&positionecran);
SDL_BlitSurface(cadre,NULL,screen,&sposcadre);
SDL_BlitSurface(stexte,NULL,screen,&s1position);
SDL_Flip(screen);
SDL_WaitEvent(&event);
switch(event.type)
   {
case SDL_MOUSEBUTTONDOWN:
if(event.button.button==SDL_BUTTON_LEFT)
    {
 aa=1;
    }

break;
  }
 }
aa=0;
}

else if(k==1)
{   
     while(aa==0)

 {                       Mix_PlayChannel(0, son2, 0);
SDL_BlitSurface(image1,NULL,screen,&positionecran);
SDL_BlitSurface(cadre,NULL,screen,&sposcadre);
SDL_BlitSurface(stexte,NULL,screen,&s1position);
SDL_Flip(screen);
SDL_WaitEvent(&event);
switch(event.type)
   {
case SDL_MOUSEBUTTONDOWN:
if(event.button.button==SDL_BUTTON_LEFT)
    {
 aa=1;
    }

break;
  }
 }
aa=0;
}
else if(k==2)
{                     while(aa==0)

 {                       Mix_PlayChannel(0, son2, 0);
SDL_BlitSurface(image1,NULL,screen,&positionecran);
SDL_BlitSurface(cadre,NULL,screen,&sposcadre);
SDL_BlitSurface(stexte,NULL,screen,&s1position);
SDL_Flip(screen);
SDL_WaitEvent(&event);
switch(event.type)
   {
case SDL_MOUSEBUTTONDOWN:
if(event.button.button==SDL_BUTTON_LEFT)
    {
 aa=1;
    }

break;
  }
 }
aa=0;

}
if(k==3)
{                       Mix_PlayChannel(0, son2, 0);
done=0;
}
break;
}
break;
}   
    }
SDL_FreeSurface(image1);
SDL_FreeSurface(image2);
SDL_FreeSurface(image3);
SDL_FreeSurface(cadre);
TTF_CloseFont(police);
TTF_Quit();
Mix_FreeChunk(son);
 Mix_FreeMusic(music);
Mix_CloseAudio();
SDL_FreeSurface(texte);
SDL_FreeSurface(texte2);
SDL_FreeSurface(atexte);
SDL_FreeSurface(atexte2);
SDL_FreeSurface(btexte);
SDL_FreeSurface(btexte2);
SDL_FreeSurface(ctexte);
SDL_FreeSurface(ctexte2);
SDL_Quit();
return 0;
}




