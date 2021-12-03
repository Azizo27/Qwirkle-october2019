
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


void initialiser_plateau(t_tuile plateau[12][26])
{
  int i, j;
  for (i = 0; i < 12; i++)
  {
    for (j = 0; j < 26; j++)
    {
      plateau[i][j].forme = 'Z';
      plateau[i][j].couleur = 100;
    }
  }
}

void creer_structure(t_tuile tuiles[108], int tailledudeck)
{
  int i, j;
  int x = 0;
  t_tuile tuile;
  int tabcouleur[6] = {0, 1, 2, 3, 4, 5};
  char tabforme[6] = {'C', 'R', 'E', 'L', 'T', 'X'};
  for (i = 0; i < 6; i++)
  {
    for (j = 0; j < 6; j++)
    {


      tuile.couleur = tabcouleur[i];
      tuile.forme = tabforme[j];
      tuiles[x] = tuile;
      if (tailledudeck == 108)
        {
        tuiles[x+1] = tuile;
        tuiles[x+2] = tuile;
        x = x+3;
       }else{
      x++;
      }
    }

    }
  }




void melangerdeck(t_tuile tuiles[108],int tailledudeck)
{
  int z, i, j;
  t_tuile temp;
  srand(time(NULL));

  for (z=0; z <rand()%99999; z++)
  {
    i = rand()%(tailledudeck);
    j = rand()%(tailledudeck);
    temp = tuiles[i];
    tuiles[i] = tuiles[j];
    tuiles[j] = temp;
  }
}

void initiajeu(t_tuile mainjoueurs[4][6], t_tuile tuiles[108], int nbrjoueurs, int *tailledudeck )
{
  int i, j;
  int z;
  z = 0;
  for (i = 0; i < nbrjoueurs; i++)
  {
    for (j = 0; j < 6; j++)
    {
      mainjoueurs[i][j] = tuiles[z];
      z++;
    }
  }
  for (i = 0; i < *tailledudeck - z; i++)
  {
    // On remplace les tuiles par celles qui sont a la fin
    tuiles[i].couleur = tuiles[i + z].couleur;
    tuiles[i].forme = tuiles[i + z].forme;
  }

  for (i = *tailledudeck - z; i <  *tailledudeck; i++)
  {
    // Les tuiles videes sont mises a null
    tuiles[i].couleur = NULL;
    tuiles[i].forme = NULL;
  }

  *tailledudeck =  *tailledudeck - z;
}

