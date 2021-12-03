
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

typedef struct t_tuile
{
  int couleur;
  char forme;
} t_tuile;


void nouveaudecketmain(t_tuile pioche[6], t_tuile deck[108], int *tailledelamain, int *tailledudeck)
{

  int nbrtuileapioche, i, j, z=0;
  t_tuile decktemp[108];
  nbrtuileapioche = 6 - *tailledelamain;
  if (nbrtuileapioche > *tailledudeck)
  {
    nbrtuileapioche = *tailledudeck;
  }

  for (i = 0; i < nbrtuileapioche; i++)
  {
    pioche[5 -i] = deck[i];
  }
  j = nbrtuileapioche;
  do
  {
    deck[j - nbrtuileapioche] = deck[j];
    j++;
  } while (deck[j].couleur != NULL && deck[j].forme != NULL && j < *tailledudeck);

  for (j= *tailledudeck - nbrtuileapioche; j<*tailledudeck; j++){
    deck[j].couleur = NULL;
    deck[j].forme = NULL;
  }
  *tailledudeck = *tailledudeck - nbrtuileapioche;
  *tailledelamain = *tailledelamain + nbrtuileapioche;
}
