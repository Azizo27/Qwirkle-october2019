


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


void sauvegardescore(char pseudo[4][50], int nbrjoueur,  int modes, t_tuile mainjoueur[4][6], int score[4], int tailledudeck, t_tuile deck[108], t_tuile plateau[12][26])
{
    printf("sauvegarde en cours");
    FILE *fichier;
    int i, j;
    fichier=fopen("partieencours.txt", "w");
    if (fichier==NULL)
    {
        printf("Erreur");
    }
    else
    {
        fprintf(fichier,"%d\n",modes); // Ajout du mode au fichier
        fprintf(fichier, "%d\n", nbrjoueur );
        for (i=0; i<nbrjoueur; i++)
        {
            fprintf(fichier,"%s\n",pseudo[i]);
        }
        for (i=0; i< nbrjoueur; i++)
        {
            for (j=0; j<6; j++)
                fprintf(fichier, "%d%c ", mainjoueur[i][j].couleur, mainjoueur[i][j].forme);
            fprintf(fichier, "\n");
        }

        for (i=0; i<nbrjoueur; i++)
            fprintf(fichier, "%d\n", score[i]);

        fprintf(fichier, "%d\n", tailledudeck);
        for (i=0; i<tailledudeck; i++){
            fprintf(fichier, "%d%c ", deck[i].couleur, deck[i].forme);
        }
        fprintf(fichier, "\n");
        for (i=0; i< 12; i++)
        {
            for (j=0; j<26; j++)
                fprintf(fichier, "%d%c ", plateau[i][j].couleur, plateau[i][j].forme);
            fprintf(fichier, "\n");
        }

        fclose(fichier);
    }
        printf("fin de sauvegarde");

}



void reprendre_partie(int *choixmodes, int *nbrjoueur, t_tuile mainjoueurs[4][6], char pseudo[4][50],
                      int score[4], int *tailledudeck, t_tuile deck[108], t_tuile plateau[12][26], int *partie_existante )
{
    int i, j;
    int mode, joueurs, taille, score_temp;
    char tuile_tmp[4];

    FILE* fic;
    ///tentative ouverture
    fic=fopen("partieencours.txt","r");
    if(fic){

        fscanf(fic,"%d",&mode);//on lit un réel
        *choixmodes = mode;

        fscanf(fic,"%d",&joueurs);//on lit un réel
        *nbrjoueur = joueurs;

        for (i=0; i<joueurs; i++)
        {
            fscanf(fic,"%s",&pseudo[i]);//on lit une chaine de caractere


        }


        // Recuperation de la main de chaque joueur
        for (i=0; i<joueurs; i++)
        {
            for(j=0; j<6; j++)
                {
                    fscanf(fic,"%s", &tuile_tmp);//on lit une chaine de caractere
                    mainjoueurs[i][j].couleur = tuile_tmp[0] - 48;
                    mainjoueurs[i][j].forme = tuile_tmp[1] ;
                }
        }

        for (i=0; i<joueurs; i++)
           {
               fscanf(fic,"%d", &score_temp);
               score[i] = score_temp;
           }
        fscanf(fic, "%d", &taille);
        *tailledudeck = taille;
        for (i=0; i<taille; i++)
        {
            fscanf(fic,"%s", &tuile_tmp);//on lit une chaine de caractere
            deck[i].couleur = tuile_tmp[0] - 48;
            deck[i].forme = tuile_tmp[1] ;
        }

        printf("\n\n");
        for (i=0; i<12; i++)
        {
            for(j=0; j<26; j++)
                {
                    fflush(stdin);
                    tuile_tmp[3]= NULL;
                    fscanf(fic,"%s", &tuile_tmp);//on lit une chaine de caractere
                    if (tuile_tmp[3] != 'Z')
                    {
                        plateau[i][j].couleur = tuile_tmp[0] - 48;
                        plateau[i][j].forme = tuile_tmp[1] ;
                    }
                    else
                    {
                        plateau[i][j].couleur = 100;
                        plateau[i][j].forme = 'Z' ;
                    }
                }
        printf("\n");
        }

    fclose(fic);///on ferme le fichier
    *partie_existante =1;
}
else{
    printf("Aucune partie sauvegardee retrouvee. Vous allez etre redirige vers une nouvelle partie\n\n");
    *partie_existante = 0;

}
}
