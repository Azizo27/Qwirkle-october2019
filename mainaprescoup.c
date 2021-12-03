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

void mainaprescoup(t_tuile piochejoueur[6], t_tuile coupjoue, int *tailledutableau)
{
  int i, repetition = 0, z = 0;
  t_tuile tableautemp[6];
  for (i = 0; i < *tailledutableau; i++)
  {
    if (coupjoue.couleur == piochejoueur[i].couleur &&
        coupjoue.forme == piochejoueur[i].forme)
    {

      repetition++;
    }
    if (coupjoue.couleur != piochejoueur[i].couleur ||
        coupjoue.forme != piochejoueur[i].forme ||
        repetition != 1)
    {

      tableautemp[z] = piochejoueur[i];
      z++;
    }
  }
  for (i = 0; i < z; i++)
  {
    piochejoueur[i].couleur = tableautemp[i].couleur;
    piochejoueur[i].forme = tableautemp[i].forme;
  }
  for (i = z; i < 6; i++)
  {
    piochejoueur[i].couleur = NULL;
    piochejoueur[i].forme = NULL;
  }
  *tailledutableau = z;
}
