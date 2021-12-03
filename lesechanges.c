
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


void echangetotal(t_tuile deck[108], t_tuile mainjoueur[6], int tailledudeck, int tailledelamain)
{  int i;
   t_tuile temp[6];
   if (tailledudeck<tailledelamain)
    {
        tailledelamain=tailledudeck;
        printf("etant donne qu il n y a que %d carte dans le deck, nous allons echanger %d de vos cartes\n", tailledudeck, tailledudeck);
    }
   for (i=0; i<tailledelamain; i++)
    {
        temp[i].forme=mainjoueur[i].forme;
        temp[i].couleur=mainjoueur[i].couleur;
        mainjoueur[i].couleur=deck[i].couleur;
        mainjoueur[i].forme=deck[i].forme;
     }
  for (i=0; i<tailledelamain; i++)
  {
       deck[i].forme=temp[i].forme;
       deck[i].couleur = temp[i].couleur;
  }


}


void echangeparticulier (t_tuile deck[108], t_tuile mainjoueur[6], int tailledudeck, int tailledelamain)
{ int i=0, j, decision;
  int index[6] , indexchoisi;
  t_tuile temp;
   if (tailledudeck<tailledelamain)
    {
        tailledelamain=tailledudeck;
        printf("etant donne qu il n y a que %d carte dans le deck, nous allons pouvoir echanger %d cartes au maximum\n", tailledudeck, tailledudeck);
    }
  do
  {
      printf("Donnez l index de la tuile que vous voulez modifier(exemple: tapez 3 pour echanger la tuile numero 3)\n");
     do{
     fflush(stdin);
     scanf("%d", &indexchoisi);
     if (indexchoisi<0 || indexchoisi>tailledelamain) printf("Cette index n existe pas. Veuillez recommencer");
     } while (indexchoisi<0 || indexchoisi>tailledelamain);
    index[i]=indexchoisi -1;
    i++;
    printf("Si vous voulez echanger une autre tuile, appuyez sur 1. Sinon, appuyer sur 0\n");
         do{
     fflush(stdin);
     scanf("%d", &decision);
     } while (decision!=0 && decision!=1);

  }while (i<tailledelamain && i< tailledudeck && decision==1);

  for (j=0; j<i; j++)
    {
        temp=deck[j];
        deck[j]=mainjoueur[index[j]];
        mainjoueur[index[j]]=temp;
     }

}





