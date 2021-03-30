#ifndef MINIMAP_H_INCLUDED
#define MINIMAP_H_INCLUDED


typedef struct{
SDL_Surface* background_minimap;
SDL_Rect pos_mini;
SDL_Surface* bonhomme;
SDL_Rect pos_bonhoe;
}Minimap;

SDL_Rect MAJMinimap( SDL_Rect posJoueur, int redimensionnement);

void initmap(Minimap *m);
void afficherminimap(Minimap m,SDL_Surface *ecran);
void affichertemps(int* tempsDebut);
void Liberer(Minimap*m);

#endif // MINIMAP_H_INCLUDED



