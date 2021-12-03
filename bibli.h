#ifndef BIBLI_H_INCLUDED
#define BIBLI_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>



void Color(int couleurDuTexte,int couleurDeFond);



void gotoligcol( int lig, int col );



int choix();
int modes();
int choixnbrjrs();
void saisiepseudo(char pseudo[50],int i);
void texteregle();
int verifier_existe_coup_valide(t_tuile pioche_joueur[6], t_tuile plateau[12][26]);
void afficheligne();
int rotationjoueur(int nbrjoueur, int numerojoueur);
int points_apres_coup(int colonne, int ligne, t_tuile plateau[12][26]);
void nouveaudecketmain(t_tuile pioche[6], t_tuile deck[108], int *tailledelamain, int *tailledudeck);
int nombre_tuile_est_valide(int ligne, int colonne, t_tuile plateau[12][26]);
void mainaprescoup(t_tuile piochejoueur[6], t_tuile coupjoue, int *tailledutableau);
void echangetotal (t_tuile deck[108], t_tuile mainjoueur[6], int tailledudeck, int tailledelamain);
void echangeparticulier (t_tuile deck[108], t_tuile mainjoueur[6], int tailledudeck, int tailledelamain);
void initialiser_plateau(t_tuile plateau[12][26]);
void creer_structure(t_tuile tuiles[108], int tailledudeck);
void melangerdeck(t_tuile tuiles[108],int tailledudeck);
void initiajeu(t_tuile mainjoueurs[4][6], t_tuile tuiles[108], int nbrjoueurs, int *tailledudeck );

void coupvalide(t_tuile piochejoueur[6], t_tuile plateau[12][26], int nbrcoup, t_tuile *coupjoue, int *coordonnee_ligne, int *coordonne_colonne, int tab,  int *scoretotal, int *pointdutour);

void cartecoloremain(t_tuile main[6], int tailledelamain);
void cartecoloreplateau(t_tuile plateau[12][26], int i, int j);








#endif // BIBLI_H_INCLUDED
