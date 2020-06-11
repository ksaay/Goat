#ifndef PERSO_H_INCLUDED 
#define PERSO_H_INCLUDED
typedef struct
{

SDL_Surface *sprite;
SDL_Rect posanimation,posjoueur;
int direction;
int score;
int etat;
int vie;
}perso;
void init_perso(perso *p1,perso *p2);
void affiche_persopre(perso *p1,SDL_Surface *screen);
void affiche_persodeu(perso *p2,SDL_Surface *screen);
void deplacement_perso(perso *p1,perso *p2);
int charger_sprite(perso *p1,perso *p2);
void animate_personnagepre(perso *p1);
void animate_personnagedeu(perso *p2);
void gestion_evenement(SDL_Event event,perso *p1,perso *p2,SDL_Surface * screen);

#endif 
