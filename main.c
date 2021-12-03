//https://openclassrooms.com/forum/sujet/tri-decroissant-d-un-tableau-72637
//extraits de code récupérés de la page campus du projet informatique
//https://www.supinfo.com/articles/single/4409-ecriture-sauvegarde-fichier-langage-c
//cours numéro 4 ,5, 6, 7, 8 et 10 de madame Palasi
//les particularités de la table ASCII


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



int main()
{
    FILE* fic;
    t_tuile deck[108], plateau[12][26], mainjoueur[4][6], coupjoue;
    int i,j, nbrjoueur, nbrcoup = 0, choixmenu, choixmode, tailledelamain = 6, numerojoueur = 0, tailledudeck;
    int nbr_coup_valide=2, coordonne_ligne, coordonne_colonne, tab[4]= {0,0,0,0}, scorertotal=0, pointdutour, choixechange, tmp, index;
    char   continuer,pseudo[4][50], quitterlejeu;
    char tuile_temp[4];
    int score;



    Color(15,0);
    int partie_existante=0;
    choixmenu = choix();
    //system("cls");
    switch (choixmenu)
    {
    case 1:
        texteregle();
        break;


    case 3:
        // Ouverture du fichier
        // Chargement des valeurs
        //choixmenu = 2;
        partie_existante = 1;
        reprendre_partie(&choixmode, &nbrjoueur, mainjoueur, pseudo, tab, &tailledudeck, deck, plateau, &partie_existante);


    case 2:
        if (partie_existante == 0)
        {
            choixmode = modes();
            nbrjoueur = choixnbrjrs();
            system("cls");

            if (choixmode==1)
                tailledudeck = 108;
            else
                tailledudeck = 36;
            creer_structure(deck, tailledudeck);


            melangerdeck(deck, tailledudeck);
            initialiser_plateau(plateau);
            initiajeu(mainjoueur, deck, nbrjoueur, &tailledudeck);

            for (i=0; i<nbrjoueur; i++)
                saisiepseudo(pseudo[i], i);
        }

      do
      { system("cls");
              for (j=0; j<26; j++)
                 printf("%c ", 'a'+j);
                printf("\n");
               for (i = 0; i < 12; i++)
              {
                for ( j = 0; j < 26; j++)
                  {   if ( plateau[i][j].forme == 'Z')
                          printf("  ", plateau[i][j].forme);
                     else
                        cartecoloreplateau(plateau, i, j);

                  }
                printf("\n");
              }
              afficheligne();
              gotoligcol(2,80);
              printf("Joueur %d: %s \n",numerojoueur+1, pseudo[numerojoueur] );
              gotoligcol(4,80);
              printf("Main :\n");
              gotoligcol(5,80);
              cartecoloremain(mainjoueur[numerojoueur], tailledelamain);
              gotoligcol(7,80);
              printf("Coup joue :");
              gotoligcol(10,80);
              printf("Score du coup :");
              gotoligcol(11,80);
              printf("%d", scorertotal);
              gotoligcol(13,80);
              printf("Score total :");
              gotoligcol(14,80);
              printf("%d", tab[numerojoueur]);
              gotoligcol(18,0);

        printf("\n\nSouhaitez vous :\n1.Echanger entierement la main\n2.Echanger partiellement votre main.\n3.Garder votre main\n\n");

          do{ fflush(stdin);
              scanf("%d", &choixechange);
            } while (choixechange!=1 && choixechange!=2 && choixechange!=3);

        if (choixechange==1)
            echangetotal(deck, mainjoueur[numerojoueur], tailledudeck, tailledelamain);
        if (choixechange==2)
            echangeparticulier(deck, mainjoueur[numerojoueur], tailledudeck, tailledelamain);

        if (nbrcoup >0)
        {
          nbr_coup_valide = verifier_existe_coup_valide(mainjoueur[numerojoueur], plateau);
          Color(8,0);
          printf("\nAide : il existe %d coup valide \n\n", nbr_coup_valide);
          Color(15,0);
          Sleep(1500);
        }
        if (nbr_coup_valide >0)
        {

            do
            { system("cls");
              for (j=0; j<26; j++)
                 printf("%c ", 'a'+j);
                printf("\n");
               for (i = 0; i < 12; i++)
              {
                for ( j = 0; j < 26; j++)
                  {   if ( plateau[i][j].forme == 'Z')
                          printf("  ", plateau[i][j].forme);
                     else
                        cartecoloreplateau(plateau, i, j);

                  }
                printf("\n");
              }
              afficheligne();
              gotoligcol(2,80);
              printf("Joueur %d: %s \n",numerojoueur+1, pseudo[numerojoueur] );
              gotoligcol(4,80);
              printf("Main :\n");
              gotoligcol(5,80);
              cartecoloremain(mainjoueur[numerojoueur], tailledelamain);
              gotoligcol(7,80);
              printf("Coup joue :");
              gotoligcol(10,80);
              printf("Score du coup :");
              gotoligcol(11,80);
              printf("%d", scorertotal);
              gotoligcol(13,80);
              printf("Score total :");
              gotoligcol(14,80);
              printf("%d", tab[numerojoueur]);
              gotoligcol(18,0);

              coupvalide(mainjoueur[numerojoueur], plateau, nbrcoup, &coupjoue, &coordonne_ligne, &coordonne_colonne, tab[numerojoueur], &scorertotal, &pointdutour);
              gotoligcol(11,80);
              printf("%d", pointdutour);
              Sleep(500);
               system("cls");

                 for (j=0; j<26; j++)
                 printf("%c ", 'a'+j);
                printf("\n");
               for (i = 0; i < 12; i++)
              {
                for ( j = 0; j < 26; j++)
                  {   if ( plateau[i][j].forme == 'Z')
                          printf("  ", plateau[i][j].forme);
                     else
                        cartecoloreplateau(plateau, i, j);

                  }
                printf("\n");
              }
              afficheligne();
              tab[numerojoueur]=scorertotal;
              scorertotal=0;
               system("cls");
              for (j=0; j<26; j++)
                 printf("%c ", 'a'+j);
                printf("\n");
               for (i = 0; i < 12; i++)
              {
                for ( j = 0; j < 26; j++)
                  {   if ( plateau[i][j].forme == 'Z')
                          printf("  ", plateau[i][j].forme);
                     else
                        cartecoloreplateau(plateau, i, j);

                  }
                printf("\n");
              }
              afficheligne();
              gotoligcol(2,80);
              printf("Joueur %d:  %s \n",numerojoueur+1, pseudo[numerojoueur] );
              gotoligcol(4,80);
              printf("Main :\n");
               mainaprescoup(mainjoueur[numerojoueur], coupjoue, &tailledelamain);
              gotoligcol(5,80);
              cartecoloremain(mainjoueur[numerojoueur], tailledelamain);
              gotoligcol(7,80);
              printf("Coup joue :");
              gotoligcol(10,80);
              printf("Score du coup");
              gotoligcol(11,80);
              printf("%d", scorertotal);
              gotoligcol(13,80);
              printf("Score total");
              gotoligcol(14,80);
              printf("%d", tab[numerojoueur]);
              gotoligcol(18,0);
              pointdutour=0;
              nbrcoup++;
                  printf("\n\n");


              if (tailledelamain > 0)
              {
                printf("Appuyez sur 1 si vous voulez jouer un autre coup et sur espace pour passer au joueur suivant\n");
                fflush(stdin);
                scanf("%c", &continuer);
              }
              if (tailledelamain==0 || nbr_coup_valide==0)
              { printf("Vous n avez plus aucun coup disponible, nous allons passer au joueur suivant\n\n");
                continuer=' ';
                Sleep(1500);
              }
            } while (continuer == '1');
            if (tailledudeck > 0)
              nouveaudecketmain(mainjoueur[numerojoueur], deck, &tailledelamain, &tailledudeck);
            points_apres_coup(coordonne_ligne, coordonne_colonne, plateau);
        }
        else {
            echangetotal(deck, mainjoueur[numerojoueur], tailledudeck, tailledelamain);
            nbr_coup_valide = verifier_existe_coup_valide(mainjoueur[numerojoueur], plateau);
        }

        numerojoueur = rotationjoueur(nbrjoueur, numerojoueur);

        if (numerojoueur==0)
        {printf("\n\nAppuyer sur C si vous souhaitez continuer la partie et sur Q si vous souhaitez sauvegarder avant de quitter la partie\n\n\n");
         do{
         fflush(stdin);
         scanf("%c", &quitterlejeu);
         } while (quitterlejeu!='C' && quitterlejeu!='Q');
        }

      } while ( nbr_coup_valide > 0 && tailledelamain >0 && quitterlejeu!='Q');
      system("cls");
      if (quitterlejeu=='Q')
        {
            sauvegardescore(pseudo, nbrjoueur, choixmode, mainjoueur, tab, tailledudeck, deck, plateau);

        }
      Color(12, 0);
      printf("\n\n\nVoici les scores\n\n");
      Color(15,0);
      for (numerojoueur=0; numerojoueur<nbrjoueur; numerojoueur++)
          printf("%s a fait un score de %d\n", pseudo[numerojoueur], tab[numerojoueur]);
      printf("\n\n\n\n");
        index=indexsuperieur(tab, nbrjoueur);
        Color(10, 0);
        printf("\n%s a gagne avec %d point\n\n", pseudo[index], tab[index]);
        Color(15, 0);
        printf("Merci d avoir joue\n\n\n");

      break;


  case 4:
    fic=fopen("partieencours.txt","r");
    if (fic)
    {

        fscanf(fic,"%d",&choixmode);//on lit un réel

        fscanf(fic,"%d",&nbrjoueur);//on lit un réel

        for (i=0; i<nbrjoueur; i++)
        {
            fscanf(fic,"%s",pseudo[i]);//on lit une chaine de caractere


        }


        // Recuperation de la main de chaque joueur
        for (i=0; i<nbrjoueur; i++)
        {
            for(j=0; j<6; j++)
                {
                    fscanf(fic,"%s", &tuile_temp);//on lit une chaine de caractere
                }
        }
        printf( "Les scores sont \n");
        for (i=0; i<nbrjoueur; i++)
           {
               fscanf(fic,"%d", &score);
               printf("%s : %d \n", pseudo[i], score);
          }
    }

    else printf("Vous n avez pas joue de precedente partie\n");

   }

  return 0;
}
