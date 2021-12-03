
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


void Color(int couleurDuTexte,int couleurDeFond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void gotoligcol( int lig, int col )
{
// ressources
COORD mycoord;

mycoord.X = col;
fflush(stdin);
mycoord.Y = lig;
SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

int choix()
{
  int choix;
  Color(12,0);
  printf("Bienvenue dans ce jeu de qwirkle. Veuillez choisir parmi ces 4 options\n\n");
  Color(15,0);
  do
  {
    printf("   1.Les regles du jeu \n   2.Nouvelle partie\n   3.Reprendre une partie sauvegardee\n   4.Scores de tous les joueurs a chaque partie.\n ");
    scanf("%d", &choix);
    fflush(stdin);
    if (choix != 1 && choix != 2 && choix != 3 && choix != 4)
      printf("\nEcrivez un nombre entre 1 et 4\n");
  } while (choix != 1 && choix != 2 && choix != 3 && choix != 4);
  return choix;
}

int modes()
{
  int choixmod;
  Color(12,0);
  printf("Dans quel mode souhaitez vous jouer?");
  Color(15,0);
  printf("\n1. mode normal\n2. mode degrade\n");
  do
  {
    scanf("%d", &choixmod);
    fflush(stdin);
    if (choixmod != 1 && choixmod != 2)
      printf("\nEcrivez un nombre entre 1 et 2\n");
  } while (choixmod != 1 && choixmod != 2);
  return choixmod;
}

int choixnbrjrs()
{
  int nbrjoueur;
  Color(12, 0);
  printf("Combien de joueurs vont participer (entre 2 et 4)\n");
  Color(15,0);
  do
  {
    scanf("%d", &nbrjoueur);
    fflush(stdin);
    if (nbrjoueur != 2 && nbrjoueur != 3 && nbrjoueur != 4)
      printf("\nEcrivez un nombre entre 2 et 4\n");
  } while (nbrjoueur != 2 && nbrjoueur != 3 && nbrjoueur != 4);
  return nbrjoueur;
}



void saisiepseudo(char pseudo[50],int i){
  Color(6,0);
  printf("Saisissez le pseudo du joueur %d\n", i+1);
  Color(15,0);
  gets(pseudo);
}
