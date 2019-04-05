// Auteur : David Varoso Gomes
// Date : 20.02.2019
// Version : 1.1
// But : Créer une jeu Bataille Navale

#ifndef BATAILLENAVALEXA_TABLEAU_H
#define BATAILLENAVALEXA_TABLEAU_H

// Libraries
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

int nbbateauxcoule =0; // Variable pour savoir quand on a gagné
int score = 0; // Score du joueur

// Affichage de la zone de jeu

FILE* txtscore; // Ficher ou on enregistr le score

// Interface "graphique" du jeu
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
    int nbcoups = 0; // Variable pour suivre le nombre de tirs du joueur

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



    // Boucle avec le nombre de coups max pour une partie

    while (nbcoups < 80 ) {

        // Condition de défaite, si le nombre de coups arrive a 40 c'est perdu
        if(nbcoups==40){

            // écrit dans le fichier score.txt que la partie est perdue
            fprintf(txtscore,"Partie perdue :( \n");

            // écrit dans le fichier score.txt le score
            fprintf(txtscore," %s ","Voici votre score :");
            fprintf(txtscore," %d ""points !",score);

            // Lignes de séparation
            fprintf(txtscore,"\n-------------------------------------\n\n");

            // Texte de défaite
            printf("\n\n\nVous avez perdu ! Vous n'avez pas réussi a couler tout les bateaux en 40 coups, dommage !\n\n");
            printf("\nVous pouvez voir le score de tout les joueurs dans le fichier Score.txt !");
            printf("Plus de chance la prochaine fois !\n\n");
            system("pause");
            exit(0);

        }

        // Condition de victoire, si le nombre de bateaux coulées est égal a 5 (nb de bateaux max dans la partie) c'est gagné
        if(nbbateauxcoule==5){

            // écrit dans le fichier score.txt que la partie est gagnée
            fprintf(txtscore,"Partie gagnée !! =D\n ");

            // écrit dans le fichier score.txt le score
            fprintf(txtscore," %s ","Voici votre score :");
            fprintf(txtscore," %d ""points !",score);

            // Lignes de séparation
            fprintf(txtscore,"\n-------------------------------------\n\n");

            // Texte de victoire
            printf("\n\nVotre score final est de %d !", score);
            printf("\nVous pouvez voir le score de tout les joueurs dans le fichier Score.txt !");
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

        // Condition pour la sécurité de tir, pour ne pas tirer 2x sur la même case

        if(tableauAfficher[vertical][horizontal] == *"X" || tableauAfficher[vertical][horizontal] == *"R"){
            printf("\nVous avez déjà tiré sur cette case, je vous donne une autre chance :)\n\n\n");

            int ligne = 0;
            int colonne = 0;

            int indicateurs = 1;
            int chiffres_ligne=1;

            printf(" ");

            // Indicateurs numériques de la grille
            for (indicateurs = 1; indicateurs < 10; indicateurs++) {
                printf("%5d", indicateurs);
            }


            // Re-affiche la grille

            for (ligne = 0; ligne < 9; ligne++) {
                printf("\n");

                printf("%d",chiffres_ligne);
                chiffres_ligne++;

                for (colonne = 0; colonne < 9; colonne++) {
                    printf("%5c", tableauAfficher[ligne][colonne]);

                }

            }

            printf("\nChoisisez votre position dans la ligne : \n");
            scanf("%d", &vertical);
            printf("\nChoisisez votre position dans la colonne : \n");
            scanf("%d", &horizontal);

            system("cls");

        }

        // Condition pour quand un tir touche un bateau

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

            // Pour le torpieur
            if (tableau_de_jeu[vertical][horizontal] == TORPIEUR){
                vie_torpieur++;
                // Condition pour savoir si le bateau est coulé
                if (vie_torpieur == 2) {
                    printf("Vous avez coulé le torpieur !\n");
                    nbbateauxcoule++;

                }

            }

            // Pour le sous-marin
            if (tableau_de_jeu[vertical][horizontal] == SOUS_MARIN){
                vie_sous_marin++;

                // Condition pour savoir si le bateau est coulé
                if (vie_sous_marin == 3){
                    printf("Vous avez détruit le sous-marin !\n");
                    nbbateauxcoule++;

                }

            }

            // Pour le contre torpieur
            if (tableau_de_jeu[vertical][horizontal] == CONTRE_TORPIEUR){
                vie_contre_torpieur++;

                // Condition pour savoir si le bateau est coulé
                if (vie_contre_torpieur == 3){
                    printf("Vous avez coulé le contre-torpieur !\n");
                    nbbateauxcoule++;

                }

            }

            // Pour le croiseur
            if (tableau_de_jeu[vertical][horizontal] == CROISEUR){
                vie_croiseur++;

                // Condition pour savoir si le bateau est coulé
                if (vie_croiseur == 4){
                    printf("Vous avez coulé le croiseur !\n");
                    nbbateauxcoule++;

                }

            }

            // pour la porte-avion
            if (tableau_de_jeu[vertical][horizontal] == PORTE_AVION){
                vie_porte_avion++;

                // Condition pour savoir si le bateau est coulé
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

        // Condition si on rate, plouf

        if (tableau_de_jeu[vertical][horizontal] == 0) {

            score=score-5;
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

        // Ajoute a chaque fois 1 a nb de coups
        nbcoups++;
    }
}


#endif //BATAILLENAVALEXA_TABLEAU_H
