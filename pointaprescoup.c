
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

int points_apres_coup(int colonne, int ligne, t_tuile plateau[12][26]){
  int i, j, pt_gagnes_ligne=0, pt_gagnes_colonne=0;
  // calculer le nombre de tuile qui se suivent après a tuile placee sur la ligne
  j=colonne+1;
  while ( plateau[ligne][j].forme != 'Z' &&  j<=26)
  {
      pt_gagnes_ligne ++; // la tuile dans le plateau dans la même ligne une colonne apres pas vide => on gagne un point
      j ++; // On va voir la colonne dapres
  }
  j=colonne-1;

  while (plateau[ligne][j].forme != 'Z' &&  j>=0)
  {
      pt_gagnes_ligne ++; // la tuile dans le plateau dans la même ligne une colonne avant est pas vide => on gagne un point
      j -- ; // On va voir la colonne avant
  }
  // Si on a gagne des points sur la ligne, on prend un point de plus qui correspond a la tuile placee.
  if (pt_gagnes_ligne > 0)
    pt_gagnes_ligne = pt_gagnes_ligne +1;

  i=ligne+1;
  while ( plateau[i][colonne].forme != 'Z' &&  i<=12)
  {

      pt_gagnes_colonne ++; // la tuile dans le plateau dans la même colonne une ligne apres pas vide => on gagne un point
      i ++; // On va voir la colonne dapres
  }
  i = ligne-1;

  while (plateau[i][colonne].forme != 'Z'  &&  i>=0)
  {

      pt_gagnes_colonne ++; // la tuile dans le plateau dans la même colonne une ligne avant est pas vide => on gagne un point
      i -- ; // On va voir la colonne avant
  }
if (pt_gagnes_colonne > 0)
    pt_gagnes_colonne = pt_gagnes_colonne +1;


// Si on fait des lignes de 6 on gagne 6 points
if (pt_gagnes_colonne ==6)
  pt_gagnes_colonne = pt_gagnes_colonne + 6;
if (pt_gagnes_ligne ==6)
  pt_gagnes_ligne = pt_gagnes_ligne + 6;

return pt_gagnes_colonne + pt_gagnes_ligne;
}
