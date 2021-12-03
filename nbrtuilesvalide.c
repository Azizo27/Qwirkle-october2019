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



int nombre_tuile_est_valide(int ligne, int colonne, t_tuile plateau[12][26]){
  int i, j;
  int nombre_tuile_ligne=0;
  int nombre_tuile_colonne=0;
  int est_valide = 1;
  // calculer le nombre de tuile qui se suivent après a tuile placee sur la ligne
  j=colonne+1;
  while ( plateau[ligne][j].forme != 'Z' &&  j<=26)
  {
      nombre_tuile_ligne ++; // la tuile dans le plateau dans la même ligne une colonne apres pas vide => on gagne un point
      j ++; // On va voir la colonne dapres
  }
  j=colonne-1;

  while (plateau[ligne][j].forme != 'Z' &&  j>=0)
  {
      nombre_tuile_ligne ++; // la tuile dans le plateau dans la même ligne une colonne avant est pas vide => on gagne un point
      j -- ; // On va voir la colonne avant
  }
  // Si on a gagne des points sur la ligne, on prend un point de plus qui correspond a la tuile placee.
  i=ligne+1;
  while ( plateau[i][colonne].forme != 'Z' &&  i<=12)
  {

      nombre_tuile_colonne ++; // la tuile dans le plateau dans la même colonne une ligne apres pas vide => on gagne un point
      i ++; // On va voir la colonne dapres
  }
  i = ligne-1;

  while (plateau[i][colonne].forme != 'Z'  &&  i>=0)
  {

      nombre_tuile_colonne ++; // la tuile dans le plateau dans la même colonne une ligne avant est pas vide => on gagne un point
      i -- ; // On va voir la colonne avant
  }

  if ( nombre_tuile_colonne == 6 || nombre_tuile_ligne == 6 )
    est_valide = 0;
  return est_valide;
}

