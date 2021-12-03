
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

void afficheligne()
{
    gotoligcol(1, 51);
     printf("|a");
    gotoligcol(2, 51);
     printf("|b");
    gotoligcol(3, 51);
     printf("|c");
    gotoligcol(4, 51);
     printf("|d");
    gotoligcol(5, 51);
     printf("|e");
    gotoligcol(6, 51);
     printf("|f");
    gotoligcol(7, 51);
     printf("|g");
    gotoligcol(8, 51);
     printf("|h");
    gotoligcol(9, 51);
     printf("|i");
    gotoligcol(10, 51);
     printf("|j");
    gotoligcol(11, 51);
     printf("|k");
    gotoligcol(12, 51);
     printf("|l");



}





int rotationjoueur(int nbrjoueur, int numerojoueur)
{
  if (numerojoueur < nbrjoueur - 1)
    numerojoueur++;
  else
    numerojoueur = 0;
  return numerojoueur;
}
