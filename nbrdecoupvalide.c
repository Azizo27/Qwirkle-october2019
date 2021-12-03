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


int verifier_existe_coup_valide(t_tuile pioche_joueur[6], t_tuile plateau[12][26])
{
  int i, j, k;
  int nbr_coup_valide=0;
  for (i=0; i<12; i++)
  {
    for (j=0; j<26; j++)
    {
      for (k=0; k<6; k++)
      {

        if (
          ( pioche_joueur[k].forme == plateau[i][j].forme || pioche_joueur[k].couleur == plateau[i][j].couleur ) &&
           ((i > 0 && plateau[i - 1][j].forme == 'Z' ) ||
           (i < 11 && plateau[i + 1][j].forme == 'Z') ||
           (j > 0 && plateau[i][j - 1].forme == 'Z' ) ||
           (j < 25 && plateau[i][j + 1].forme == 'Z')))
           nbr_coup_valide ++;
      }
    }
  }
return nbr_coup_valide;
}
