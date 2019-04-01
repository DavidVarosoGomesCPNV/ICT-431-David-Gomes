//
// Created by David-Manuel.VAROSO on 08.03.2019.
//


#ifndef BATAILLENAVALEXA_TABLEAU_H
#define BATAILLENAVALEXA_TABLEAU_H

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>


#define MAX_LIGNE 10 // Constante pour la valeur max de la ligne
#define MAX_COLONNE 10 // Constante pour la valeur max de la ligne

#define TORPIEUR 2 // Constante pour la valeur du torpieur sur la grille
#define SOUS_MARIN 3 // Constante pour la valeur du sous-marin sur la grille
#define CONTRE_TORPIEUR 4  // Constante pour la valeur du contre-torpieur sur la grille
#define CROISEUR 5 // Constante pour la valeur du croiseur sur la grille
#define PORTE_AVION 6 // Constante pour la valeur du porte-avion

// Source des noms : https://www.regles-de-jeux.com/regle-de-la-bataille-navale/

// Vie des bateaux , pour savoir quand ils sont coulées
int vie_torpieur = 0;
int vie_sous_marin = 0;
int vie_contre_torpieur =0;
int vie_croiseur = 0;
int vie_porte_avion= 0;

int nbbateauxcoule =0;
int score = 0;

// Affichage de la zone de jeu


char tableauAfficher[MAX_LIGNE][MAX_COLONNE]={

        "----------",
        "----------",
        "----------",
        "----------",
        "----------",
        "----------",
        "----------",
        "----------",
        "----------",
        "----------"
};




// Fonction pour le tableau, ou on place les bateau

void affichageGrille() {

    int vertical, horizontal;
    int nbcoups = 0;

    // 1 torpieur : 2 cases, 1 sous-marin : 3 cases, 1 contre-torpieur : 3 cases, 1 croiseur : 4 cases et 1 porte-avions : 5 cases
    // Tout cela est aussi détailé dans l'option "Règles du jeu" du menu

    int tableau_de_jeu[MAX_LIGNE][MAX_COLONNE] = {
            0, 0, 0, 2, 2, 0, 0, 4, 0, 0,
            0, 5, 0, 0, 0, 0, 0, 4, 0, 0,
            0, 5, 0, 0, 0, 0, 0, 4, 0, 0,
            0, 5, 0, 0, 0, 3, 0, 0, 0, 0,
            0, 5, 0, 0, 0, 3, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 3, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 6, 6, 6, 6, 6, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };



    // boucle pr le nb de coups max

    while (nbcoups < 100 ) {

        if(nbbateauxcoule==5){

            printf("\nVotre score final est de %d !", score);
            printf("\nVous avez coulé tout les bateaux bien joué !\n");
            system("pause");
            exit(0);

        }

        // Affichage et demande des valeurs ou l'utilisateur veut tirer

        printf("\nChoisisez votre position dans la ligne : \n");
        scanf("%d", &vertical);
        printf("\nChoisisez votre position dans la colonne : \n");
        scanf("%d", &horizontal);


        // Modification de l'idex pour l'affichage des indicateurs 1,2,3 etc au dessus et a gauche de la grille
        vertical--;
        horizontal--;

        system("cls");

        // Condition si le tir tombe sur un bateau

        if(tableauAfficher[vertical][horizontal] == *"X" || tableauAfficher[vertical][horizontal] == *"R"){
            printf("\nVous avez déjà tiré sur cette case, je vous donne une autre chance :)\n");
            printf("\nChoisisez votre position dans la ligne : \n");
            scanf("%d", &vertical);
            printf("\nChoisisez votre position dans la colonne : \n");
            scanf("%d", &horizontal);

        }



        if (tableau_de_jeu[vertical][horizontal] == TORPIEUR ||
            tableau_de_jeu[vertical][horizontal] == SOUS_MARIN ||
            tableau_de_jeu[vertical][horizontal] == CONTRE_TORPIEUR ||
            tableau_de_jeu[vertical][horizontal] == CROISEUR ||
            tableau_de_jeu[vertical][horizontal] == PORTE_AVION) {

            // Il met un X a la place du - pour dire que il y avait quelque chose sur cette case et sa a été touché

            tableauAfficher[vertical][horizontal] = *"X";

            // Ecrit touché pour l'utilisateur


            printf("\nTouché ! \n");
            printf("\nVotre score actuel est de %d\n", score);
            score=score+15;

            // Diverses conditions pour savoir quand un bateau est coulé

            if (tableau_de_jeu[vertical][horizontal] == TORPIEUR){
                vie_torpieur++;

                if (vie_torpieur == 2) {
                    printf("Vous avez coulé le torpieur !\n");
                    nbbateauxcoule++;

                }

            }

            if (tableau_de_jeu[vertical][horizontal] == SOUS_MARIN){
                vie_sous_marin++;


                if (vie_sous_marin == 3){
                    printf("Vous avez détruit le sous-marin !\n");
                    nbbateauxcoule++;

                }

            }

            if (tableau_de_jeu[vertical][horizontal] == CONTRE_TORPIEUR){
                vie_contre_torpieur++;


                if (vie_contre_torpieur == 3){
                    printf("Vous avez coulé le contre-torpieur !\n");
                    nbbateauxcoule++;

                }

            }

            if (tableau_de_jeu[vertical][horizontal] == CROISEUR){
                vie_croiseur++;


                if (vie_croiseur == 4){
                    printf("Vous avez coulé le croiseur !\n");
                    nbbateauxcoule++;

                }

            }


            if (tableau_de_jeu[vertical][horizontal] == PORTE_AVION){
                vie_porte_avion++;


                if (vie_porte_avion == 5){
                    printf("Vous avez coulé le porte-avion !\n");
                    nbbateauxcoule++;

                }

            }


            // Boucle pour re-afficher le plateau de jeu actualisé après chaque tir

            int ligne = 0;
            int colonne = 0;

            int indicateurs = 1;
            int chiffres_ligne=1;

            // Affichage d'un espace pour que les indicateurs soient bien allignées avec les colonnes et les lignes


            printf(" ");

            for (indicateurs = 1; indicateurs < 10; indicateurs++) {
                printf("%5d", indicateurs);
            }


            // Reaffiche le tableau

            for (ligne = 0; ligne < 9; ligne++) {
                 printf("\n");

                 printf("%d",chiffres_ligne);
                 chiffres_ligne++;

                for (colonne = 0; colonne < 9; colonne++) {
                    printf("%5c", tableauAfficher[ligne][colonne]);

                }

            }


        }

        // Condition si on rate, plouf !

        if (tableau_de_jeu[vertical][horizontal] == 0) {

            score=score-3;
            // Met un R a la place du - pour dire que il n'y avait rien sur cette case mais que il y a eu un tir dessus
            tableauAfficher[vertical][horizontal] = *"R";

            printf("\nRaté ! \n");
            printf("\nVotre score actuel est de %d\n", score);

            int ligne = 0;
            int colonne = 0;

            int indicateurs = 1;
            int chiffres_ligne=1;




            printf(" ");

            for (indicateurs = 1; indicateurs < 10; indicateurs++) {
                printf("%5d", indicateurs);
            }


            for (ligne = 0; ligne < 9; ligne++) {
                printf("\n");

                printf("%d",chiffres_ligne);
                chiffres_ligne++;

                for (colonne = 0; colonne < 9; colonne++) {
                    printf("%5c", tableauAfficher[ligne][colonne]);

                }

            }


        }


        nbcoups++;
    }
}


#endif //BATAILLENAVALEXA_TABLEAU_H
