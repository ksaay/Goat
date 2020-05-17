#ifndef ENEMI_H_INCLUDED 
#define ENEMI_H_INCLUDED

typedef struct
{

SDL_Surface *sprite;
SDL_Rect posanime,positionenemi ;
int etat;
}enemi;
void init_enemi(enemi *e);
void affiche_enemi(enemi *e,SDL_Surface *screen);
int deplacement_enemi(enemi *e);
void animame_enemi(enemi *e);
int charger_sprite(enemi *e);






#endif 
