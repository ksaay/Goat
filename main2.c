#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include <time.h>
#include"SDL/SDL_mixer.h"
#include "fonctions.h"
#include "SDL/SDL_ttf.h"
void notf(int* x)
{
SDL_Surface *texte = NULL;
SDL_Surface *texte1 = NULL;
SDL_Surface *texte2 = NULL;
SDL_Surface *texte3 = NULL;
SDL_Surface *texte4 = NULL;
SDL_Surface *texte5 = NULL;
SDL_Surface *texte6 = NULL;
SDL_Rect position;
SDL_Rect position1;
SDL_Rect position2;
SDL_Rect position3;
SDL_Rect position4;
SDL_Rect position5;
SDL_Rect position6;
TTF_Font *police=NULL;
TTF_Init();
SDL_Color couleurNoire ={0,8,10};
SDL_Color couleurNoire1 ={255,150,20};
int xx,yy;
int q=0;
SDL_Surface *screen[30];
SDL_Event event;
SDL_Rect ball;

SDL_Rect init[20];
Mix_Music *music;
Mix_Chunk *effect;
Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
music=Mix_LoadMUS("music.mp3");
effect=Mix_LoadWAV("bang_1.wav");
Mix_PlayMusic(music,-1);
if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("\n un able to init  vid %s\n",SDL_GetError());
}
screen[0] = SDL_SetVideoMode(1000, 750, 32, SDL_SWSURFACE|SDL_DOUBLEBUF);
if(!screen[0])
{
printf("unable to set 1000 x 750 video : %s\n",SDL_GetError());
return 0;
}

screen[2]=IMG_Load("rip2.jpg");
screen[3]=IMG_Load("rip3.jpg");
screen[4]=IMG_Load("rip4.jpg");
screen[5]=IMG_Load("rip5.jpg");
screen[6]=IMG_Load("rip4.jpg");
screen[7]=IMG_Load("rip3.jpg");
screen[8]=IMG_Load("rip2.jpg");
screen[10]=IMG_Load("play1.png");
screen[11]=IMG_Load("settings1.png");
screen[12]=IMG_Load("exit1.png");
screen[13]=IMG_Load("play2.png");
screen[14]=IMG_Load("settings2.png");
screen[15]=IMG_Load("exit2.png");
screen[16]=IMG_Load("play3.png");
screen[17]=IMG_Load("settings3.png");
screen[18]=IMG_Load("exit3.png");
screen[19]=IMG_Load("back.png");
screen[20]=IMG_Load("credits1.png");
screen[21]=IMG_Load("credits2.png");
screen[22]=IMG_Load("credits3.png");
screen[23]=IMG_Load("amir1.jpg");
screen[24]=IMG_Load("v1.png");
screen[25]=IMG_Load("v2.png");
screen[26]=IMG_Load("creditss.jpg");
init[23].x=200; init[23].y=250;
init[10].x=310; init [10].y=350;
init[11].x=310; init [11].y=450;
init[12].x=310; init [12].y=550;
init[16].x=310; init[16].y=650;
init[13]=init[10];
init[14]=init[11];
init[15]=init[16];
init[24].y=330; init[24].x=450;
police = TTF_OpenFont("pacifico.ttf",35);
if(!police)
{
printf("unable to set 1000 x 750 video : %s\n",SDL_GetError());
return 0;
}
texte = TTF_RenderText_Blended(police, "Developped by Matadors: ",couleurNoire1);
texte1 = TTF_RenderText_Blended(police,"  Anouer Amin Kassaa ",couleurNoire);
texte2 = TTF_RenderText_Blended(police,"  Mohamed Hedi Zarrouk ",couleurNoire);
texte3 = TTF_RenderText_Blended(police,"   Sarra Gara ",couleurNoire);
texte4 = TTF_RenderText_Blended(police,"  Habib Firas Hadroug ",couleurNoire);
texte5 = TTF_RenderText_Blended(police,"   Oumaima Karmandi  ",couleurNoire);
texte6 = TTF_RenderText_Blended(police,"    Hssin Mtiraoui ",couleurNoire);
if(!screen[1])
{
printf("unable to set background: %s\n",SDL_GetError());
}
int click=0;
int i=2;

animation(3,screen,init);

SDL_BlitSurface(screen[2],NULL,screen[0],&init[2]); //animation 1
SDL_BlitSurface(screen[10],NULL,screen[0],&init[10]); //button play
SDL_BlitSurface(screen[11],NULL,screen[0],&init[11]);//button settings
SDL_BlitSurface(screen[20],NULL,screen[0],&init[12]);//button credits
SDL_BlitSurface(screen[12],NULL,screen[0],&init[16]);//button exit
SDL_Flip(screen[0]);
int play=0;
int place=0;
int menu=0;
int a=0;
int sound=1;
while(event.type!=SDL_QUIT&&q==0)
{
srand(time(NULL));
if(menu==3)
{

SDL_BlitSurface(screen[26],NULL,screen[0],&init[0]); //new background
position.x=200;
position.y=150;
position1.x=200;
position1.y=190;
position2.x=200;
position2.y=230;
position3.x=200;
position3.y=270;
position4.x=200;
position4.y=320;
position5.x=200;
position5.y=360;
position6.x=200;
position6.y=400;
SDL_BlitSurface(texte,NULL,screen[0],&position);
SDL_BlitSurface(texte1,NULL,screen[0],&position1);
SDL_BlitSurface(texte2,NULL,screen[0],&position2);
SDL_BlitSurface(texte3,NULL,screen[0],&position3);
SDL_BlitSurface(texte4,NULL,screen[0],&position4);
SDL_BlitSurface(texte5,NULL,screen[0],&position5);
SDL_BlitSurface(texte6,NULL,screen[0],&position6);
SDL_Flip(screen[0]);
SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_KEYDOWN:
			menu=0;
			break;
}
}

if(menu==2)
	{
SDL_BlitSurface(screen[23],NULL,screen[0],&init[0]); //new background
if(sound==1)
SDL_BlitSurface(screen[24],NULL,screen[0],&init[24]); //sound 
else SDL_BlitSurface(screen[25],NULL,screen[0],&init[24]); //sound 
SDL_Flip(screen[0]);
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_KEYDOWN:
			menu=0;
			break;
case SDL_MOUSEBUTTONDOWN:
if (sound==0)
sound=1;
else sound=0;
break;
		}
	}
	if(menu==1)
	{
SDL_BlitSurface(screen[19],NULL,screen[0],&init[0]); //new background
SDL_Flip(screen[0]);
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_KEYDOWN:
			menu=0;
			break;
		}
	}
if (menu==0)
{
srand(time(NULL));
play=rand() %3;
if(play==1)
{
i++;
if(i>8)
i=3;
animation(i,screen,init); //animation background
SDL_Delay(30);
}//ifplay==4

SDL_PollEvent(&event);
switch(event.type)
{
  case SDL_KEYDOWN:
switch(event.key.keysym.sym)
{
case SDLK_ESCAPE: (*x)=1;
q=1;
break;
case SDLK_DOWN:
place+=1;
 break;
case SDLK_a: 
if (a==0)
{
screen[0] = SDL_SetVideoMode(1000, 750, 32, SDL_SWSURFACE|SDL_DOUBLEBUF | SDL_FULLSCREEN);
a=1;
}
else
{
screen[0] = SDL_SetVideoMode(1000, 750, 32, SDL_SWSURFACE|SDL_DOUBLEBUF );
a=0;
}
break;
}//switch event
break;
case SDL_MOUSEMOTION:
SDL_GetMouseState(&xx,&yy);
place=buttons(i,screen,init,xx,yy);
if((place!=0)&&(play==0))
{
Mix_PlayChannel(1,effect,0);
play=1;
}
if(place==0)
play=0;
break;
case SDL_MOUSEBUTTONDOWN:
SDL_GetMouseState(&xx,&yy);
click=buttons(i,screen,init,xx,yy);
switch(click)
{
case 1: 
SDL_BlitSurface(screen[116],NULL,screen[0],&init[13]); //button play
SDL_BlitSurface(screen[11],NULL,screen[0],&init[11]);//button settings
SDL_BlitSurface(screen[20],NULL,screen[0],&init[12]);//button credits
SDL_BlitSurface(screen[12],NULL,screen[0],&init[16]);//button exit
SDL_Flip(screen[0]);
SDL_Delay(200);

menu=1;
break;
case 2:
menu=2;
break;
case 3:
menu=3;
break;


}
break;
}//switch key


switch(place) //animation buttons
{

case 0: //buttons init
SDL_BlitSurface(screen[2],NULL,screen[0],&init[2]); //animation 1
SDL_BlitSurface(screen[10],NULL,screen[0],&init[10]); //button play
SDL_BlitSurface(screen[11],NULL,screen[0],&init[11]);//button settings
SDL_BlitSurface(screen[20],NULL,screen[0],&init[12]);//button credits
SDL_BlitSurface(screen[12],NULL,screen[0],&init[16]);//button exit
break;
case 1: //button play2

SDL_BlitSurface(screen[2],NULL,screen[0],&init[2]); //animation 1
SDL_BlitSurface(screen[13],NULL,screen[0],&init[13]); //button play
SDL_BlitSurface(screen[11],NULL,screen[0],&init[11]);//button settings
SDL_BlitSurface(screen[20],NULL,screen[0],&init[12]);//button credits
SDL_BlitSurface(screen[12],NULL,screen[0],&init[16]);//button exit

break;
case 2: //button settings2

SDL_BlitSurface(screen[2],NULL,screen[0],&init[2]); //animation 1
SDL_BlitSurface(screen[10],NULL,screen[0],&init[13]); //button play
SDL_BlitSurface(screen[14],NULL,screen[0],&init[14]);//button settings
SDL_BlitSurface(screen[20],NULL,screen[0],&init[12]);//button credits
SDL_BlitSurface(screen[12],NULL,screen[0],&init[16]);//button exit
break;
case 3 : 
//credits
SDL_BlitSurface(screen[2],NULL,screen[0],&init[2]); //animation 1
SDL_BlitSurface(screen[10],NULL,screen[0],&init[10]); //button play
SDL_BlitSurface(screen[11],NULL,screen[0],&init[11]);//button settings
SDL_BlitSurface(screen[21],NULL,screen[0],&init[12]);//button credits
SDL_BlitSurface(screen[12],NULL,screen[0],&init[16]);//button exit

break;
case 4://button exit2

SDL_BlitSurface(screen[2],NULL,screen[0],&init[2]); //animation 1
SDL_BlitSurface(screen[10],NULL,screen[0],&init[10]); //button play
SDL_BlitSurface(screen[11],NULL,screen[0],&init[11]);//button settings
SDL_BlitSurface(screen[20],NULL,screen[0],&init[12]);//button credits
SDL_BlitSurface(screen[15],NULL,screen[0],&init[16]);//button exit
break;

}//switch place
SDL_Flip(screen[0]);
}//switch place
}
if(SDL_QUIT)
{
TTF_CloseFont(police);

TTF_Quit();
SDL_FreeSurface(texte);
SDL_FreeSurface(texte1);
SDL_FreeSurface(texte2);
SDL_FreeSurface(texte3);
SDL_FreeSurface(texte4);
SDL_FreeSurface(texte5);
SDL_FreeSurface(texte6);
Mix_CloseAudio();
Mix_FreeMusic(music);

}


}





void animation (int i,SDL_Surface* screen[],SDL_Rect init[])
{
init[0].x=0;
init[0].y=0;

switch(i)
{
case 3: 
SDL_BlitSurface(screen[3],NULL,screen[0],&init[0]);
break;
case 4: 
SDL_BlitSurface(screen[4],NULL,screen[0],&init[0]);
break;
case 5: SDL_BlitSurface(screen[5],NULL,screen[0],&init[0]);
break;
case 6 : SDL_BlitSurface(screen[6],NULL,screen[0],&init[0]);
break;
case 7: 
SDL_BlitSurface(screen[7],NULL,screen[0],&init[0]);
break;
case 8: 
SDL_BlitSurface(screen[8],NULL,screen[0],&init[0]);
break;

}
}
int buttons(int i,SDL_Surface* screen[],SDL_Rect init[],int x,int y)
{

if((x>=340)&&(x<=530)&&(y>=356)&&(y<=402))
{
return 1;
}
else
{
if((x>=340)&&(x<=530)&&(y>=462)&&(y<=510))
{

return 2;
}
else
{
if((x>=340)&&(x<=530)&&(y>=564)&&(y<=612))
{

return 3;
}
else
{
if((x>=340)&&(x<=530)&&(y>=656)&&(y<=712))
{
return 4;
}
else
return 0;
}//small else
}//big else -
}//big else

}









void notf2()
{
SDL_Surface *screen[10];
SDL_Event event;
SDL_Rect ball;

SDL_Rect init[10];
if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("\n un able to init  vid %s\n",SDL_GetError());
}
screen[0] = SDL_SetVideoMode(1000, 750, 32, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);
if(!screen[0])
{
printf("unable to set 10000 x 750 video : %s\n",SDL_GetError());
}
screen[2]=IMG_Load("rip2.jpg");
screen[3]=IMG_Load("rip3.jpg");
screen[4]=IMG_Load("rip4.jpg");
screen[5]=IMG_Load("rip5.jpg");
screen[6]=IMG_Load("rip4.jpg");
screen[7]=IMG_Load("rip3.jpg");
screen[8]=IMG_Load("rip2.jpg");
screen[10]=IMG_Load("play1.png");
screen[11]=IMG_Load("settings1.png");
screen[12]=IMG_Load("exit1.png");
screen[13]=IMG_Load("play2.png");
screen[14]=IMG_Load("settings2.png");
screen[15]=IMG_Load("exit2.png");
screen[16]=IMG_Load("play3.png");
screen[17]=IMG_Load("settings3.png");
screen[18]=IMG_Load("exit3.png");
if(!screen[1])
{
printf("unable to set background: %s\n",SDL_GetError());
}

SDL_BlitSurface(screen[1],NULL,screen[0],&init[1]);
SDL_Flip(screen[0]);

int i=0;
while(event.type!=SDL_QUIT)
{
SDL_PollEvent(&event);
switch(event.type)
{
case SDL_KEYDOWN:
SDL_QUIT;
SDL_QuitSubSystem(SDL_INIT_VIDEO);
break;
}
}
free(screen);
}
