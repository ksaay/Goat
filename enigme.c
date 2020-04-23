#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"enigme2.h"

void afficheenigme(SDL_Surface *screen)
{

SDL_Surface *image,*background= NULL;
SDL_Surface *texte1 ;
SDL_Surface *texte2;
TTF_Font *police=NULL;
TTF_Init();

SDL_Rect positiontexte1;
SDL_Rect positiontexte2;
SDL_Rect positionecran;
SDL_Rect positionimage;
SDL_Color couleur= {255,100,70};
SDL_Init(SDL_INIT_VIDEO);




TTF_Font* font=TTF_OpenFont("pacifico.ttf",32);
positionecran.x=0;
positionecran.y=0;
SDL_FillRect(screen,0,SDL_MapRGB(screen->format,255,255,0));
SDL_WM_SetCaption("enigmestatique",NULL);

image=IMG_Load("enigme.png");

background =IMG_Load("back.jpg");

SDL_BlitSurface(background,NULL,screen,&positionecran);



positionimage.x = screen->w / 2 - image->w / 2;
positionimage.y = screen->h / 2 - image->h / 2;

SDL_BlitSurface(image,NULL,screen,&positionimage);

texte1=TTF_RenderText_Solid(font,"Choose the right option",couleur);
texte2=TTF_RenderText_Solid(font,"a:25,  b:35,  c:40",couleur);

positiontexte1.x=80;
positiontexte1.y=2;
positiontexte2.x=250;
positiontexte2.y=30;

SDL_BlitSurface(texte1,NULL,screen,&positiontexte1);
SDL_BlitSurface(texte2,NULL,screen,&positiontexte2);

SDL_Flip(screen);
}
void reponsenigme(SDL_Surface *screen)
{
SDL_Event event;
SDL_Surface *image1,*image2=NULL;
SDL_Rect positionimage1;
image2 =IMG_Load("youlose.jpg");
image1 =IMG_Load("youwin.jpg");
positionimage1.x =150;
positionimage1.y =90;


while(event.type!=SDL_QUIT)
{
SDL_WaitEvent(&event);


switch(event.type)
{

case SDL_KEYDOWN:
switch(event.key.keysym.sym)
{
case SDLK_a: 
SDL_BlitSurface(image2,NULL,screen,&positionimage1);


SDL_Flip(screen);
break;
case SDLK_b: 
SDL_BlitSurface(image1,NULL,screen,&positionimage1);
SDL_Flip(screen);
break;
case SDLK_c: 
SDL_BlitSurface(image2,NULL,screen,&positionimage1);
SDL_Flip(screen);
break;

}
SDL_Flip(screen);
break;
}

}
}


