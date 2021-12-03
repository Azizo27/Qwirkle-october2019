


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


int indexsuperieur(int tab[4], int nbrjoueur)
{ int i, index=0;
  for (i=0; i< nbrjoueur; i++)
  {
     if (tab[i]>tab[index])
        index=i;
  }
  return index;
}
