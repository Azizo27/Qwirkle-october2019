
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

void coupvalide(t_tuile piochejoueur[6], t_tuile plateau[12][26], int nbrcoup, t_tuile *coupjoue, int *coordonnee_ligne, int *coordonne_colonne, int tab,  int *scoretotal, int *pointdutour)
{
  int i, j, converligne, convercolonne, couleurtuile, occurence;
  int c, pointgagnes=0;
  int  ligne_valide = 1;

  t_tuile coupajouer;
  char choixligne, choixcolonne, formetuile;
  occurence = 0;
  do
  {
    // Boucle verification validite coup
    do
    {
      // Boucle case jouable apres premier coup (autour pas vide)
    do{
      // Boucle verification quon fit pas une ligne >6
      do
      { // Boucle verifiction que la case est bien vide

       do{
        do
        { // Boucle choix ligne

          printf("\nSaisissez votre ligne :");
          fflush(stdin);
        scanf("%c", &choixligne);
            fflush(stdin);

          if ((choixligne < 'a') || (choixligne > 'l'))
            printf("Ce n est pas une case du tableau\n");
        } while ((choixligne < 'a') || (choixligne > 'l'));

        do
        { // Boucle choix colonne
          printf("Saisissez votre colonne :");
          fflush(stdin);
          scanf("%c", &choixcolonne);

          if ((choixcolonne < 'a') || (choixcolonne > 'z'))
            printf("Ce n est pas une case du tableau\n");
        } while ((choixcolonne < 'a') || (choixcolonne > 'z'));

        converligne = choixligne - 'a';
        convercolonne = choixcolonne - 'a';
        ligne_valide = nombre_tuile_est_valide(converligne, convercolonne, plateau);
      }while (ligne_valide == 0);
        if (plateau[converligne][convercolonne].forme != 'Z' && plateau[converligne][convercolonne].couleur != 100)
          printf("Les coordonnees ne sont pas disponible.\n ");
      } while (plateau[converligne][convercolonne].forme != 'Z' && plateau[converligne][convercolonne].couleur != 100);

      if (nbrcoup > 0 &&
          ((converligne > 0 && plateau[converligne - 1][convercolonne].forme == 'Z' )|| converligne == 0) &&
          ((converligne < 11 && plateau[converligne + 1][convercolonne].forme == 'Z') || converligne == 11) &&
          ((convercolonne > 0 && plateau[converligne][convercolonne - 1].forme == 'Z' )|| convercolonne == 0) &&
          ((convercolonne < 25 && plateau[converligne][convercolonne + 1].forme == 'Z') || convercolonne == 25))
        printf("vous ne pouvez pas placer votre tuile a cet endroit. Veuillez choisir d autres coordonnees\n");
    } while (nbrcoup > 0 &&
             ((converligne > 0 && plateau[converligne - 1][convercolonne].forme == 'Z') || converligne == 0) &&
             ((converligne < 11 && plateau[converligne + 1][convercolonne].forme == 'Z') || converligne == 11) &&
             ((convercolonne > 0 && plateau[converligne][convercolonne - 1].forme == 'Z') || convercolonne == 0) &&
             ((convercolonne < 25 && plateau[converligne][convercolonne + 1].forme == 'Z') || convercolonne == 25));


          do
          { printf("Saisissez la forme de votre tuile :");
            fflush(stdin);
            scanf("%c", &formetuile);
            fflush(stdin);
            if (formetuile != 'C' && formetuile != 'R' && formetuile != 'E' && formetuile != 'L' && formetuile != 'T' && formetuile != 'X')
              printf("Cette lettre ne correspond a aucune forme\n");
          } while (formetuile != 'C' && formetuile != 'R' && formetuile != 'E' && formetuile != 'L' && formetuile != 'T' && formetuile != 'X');
          coupajouer.forme = formetuile;


          do
          { printf("Saisissez la couleur de votre tuile (un chiffre entre 0 et 5):");
            fflush(stdin);
            scanf("%d", &couleurtuile);

            if (couleurtuile < 0 && couleurtuile > 5)
              printf("Ce chiffre ne correspond a aucune couleur\n");
          } while (couleurtuile != 0 && couleurtuile != 1 && couleurtuile != 2 && couleurtuile != 3 && couleurtuile != 4 && couleurtuile != 5);
          coupajouer.couleur = couleurtuile;

          for (i = 0; i < 6; i++)
      {
        if (coupajouer.couleur == piochejoueur[i].couleur &&
            coupajouer.forme == piochejoueur[i].forme)
          occurence++;
      }
      if (occurence == 0)
        printf("Votre coup n est pas valide, Recommencez");
    } while (occurence < 1);



    if (
        (nbrcoup > 0) &&
      ((converligne > 0 && coupajouer.forme != plateau[converligne - 1][convercolonne].forme) || converligne == 0) &&
      ((converligne < 11 && coupajouer.forme != plateau[converligne + 1][convercolonne].forme) || converligne == 11) &&
      ((convercolonne > 0 && coupajouer.forme != plateau[converligne][convercolonne - 1].forme) || convercolonne == 0) &&
      ((convercolonne < 25 && coupajouer.forme != plateau[converligne][convercolonne + 1].forme) ||
       convercolonne == 25) &&
      ((converligne > 0 && coupajouer.couleur != plateau[converligne - 1][convercolonne].couleur) ||
       converligne == 0) &&
      ((converligne < 11 && coupajouer.couleur != plateau[converligne + 1][convercolonne].couleur) || converligne == 11) &&
      ((convercolonne > 0 && coupajouer.couleur != plateau[converligne][convercolonne - 1].couleur) || convercolonne == 0) &&
      ((convercolonne < 25 && coupajouer.couleur != plateau[converligne][convercolonne + 1].couleur) ||
       convercolonne == 25))


      printf("Le coup est invalide. Veuillez recommencer\n");

  } while (
       (nbrcoup > 0) &&
      ((converligne > 0 && coupajouer.forme != plateau[converligne - 1][convercolonne].forme) || converligne == 0) &&
      ((converligne < 11 && coupajouer.forme != plateau[converligne + 1][convercolonne].forme) || converligne == 11) &&
      ((convercolonne > 0 && coupajouer.forme != plateau[converligne][convercolonne - 1].forme) || convercolonne == 0) &&
      ((convercolonne < 25 && coupajouer.forme != plateau[converligne][convercolonne + 1].forme) ||
       convercolonne == 25) &&
      ((converligne > 0 && coupajouer.couleur != plateau[converligne - 1][convercolonne].couleur) ||
       converligne == 0) &&
      ((converligne < 11 && coupajouer.couleur != plateau[converligne + 1][convercolonne].couleur) || converligne == 11) &&
      ((convercolonne > 0 && coupajouer.couleur != plateau[converligne][convercolonne - 1].couleur) || convercolonne == 0) &&
      ((convercolonne < 25 && coupajouer.couleur != plateau[converligne][convercolonne + 1].couleur) ||
       convercolonne == 25));

  plateau[converligne][convercolonne].couleur = coupajouer.couleur;
  plateau[converligne][convercolonne].forme = coupajouer.forme;
  pointgagnes = points_apres_coup(convercolonne, converligne, plateau);
  if (nbrcoup ==0)
    pointgagnes = 1;

  *pointdutour=pointgagnes;
  *coupjoue = coupajouer;
  *coordonne_colonne = convercolonne;
  *coordonnee_ligne = converligne;
   *scoretotal=tab+pointgagnes;

   gotoligcol(8,80);
   printf("%c%c%c%d ", choixligne, choixcolonne, formetuile, couleurtuile);


}
