// Auteur : David Gomes
// Date : 20.02.2019
// Version : 1.0
// But : Créer une jeu Bataille Navale


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Tableau.h"
#pragma execution_character_set ("utf-8")
int choixcouleur;

void menu(){

    unsigned int choix = 0;

    while (choix != 1 && choix != 4) //Boucle pour afficher le menu tant que l'utilisateur n'a pas appuiyer sur jouer ou quitter
    {
        // Choix de l'utilisateur
        printf("--------------------------------------------------------\n       \n--------------------------------------------------------\n\n\n");
        printf("       _~                                   _~\n"
               "    _~ )_)_~                             _~ )_)_~\n"
               "    )_))_))_)      BATAILLE NAVALE       )_))_))_)\n"
               "    _!__!__!_                            _!__!__!_\n"
               "    \\______t/                            \\______t/\n"
               "  ~~~~~~~~~~~~~                         ~~~~~~~~~~~~~\n"
               "\n"
               "--------------------------------------------------------\n       "
               "\n--------------------------------------------------------\n\n\n");

        printf("1 - Jouer\n2 - Option\n3 - Règles du jeu\n4 - Quitter\n\nQuel est votre choix ?\n");
        scanf("%d", &choix);

        // Menu de base
        // Les action qui suiveront le choix de l'utilisateur


        switch (choix) {

            {
                case 1:
                    printf("-----------------------------\n       Bataille navale\n-----------------------------\n\n\n");
                printf("Le plateu de jeu ce présente comme ceci : \n\n");
                printf("     1    2    3    4    5    6    7    8    9\n"
                       "1    -    -    -    -    -    -    -    -    -\n"
                       "2    -    -    -    -    -    -    -    -    -\n"
                       "3    -    -    -    -    -    -    -    -    -\n"
                       "4    -    -    -    -    -    -    -    -    -\n"
                       "5    -    -    -    -    -    -    -    -    -\n"
                       "6    -    -    -    -    -    -    -    -    -\n"
                       "7    -    -    -    -    -    -    -    -    -\n"
                       "8    -    -    -    -    -    -    -    -    -\n"
                       "9    -    -    -    -    -    -    -    -    -");

                affichageGrille();



                break;
            }
            {
                case 2:
                    system("cls");
                    printf("Choisisez une couleur pour votre programme !\n");
                    printf("1 - Bleu Foncé & Fond Noir\n2 - Bleu Clair Fond Noir\n3 - Bleu Clair & Fond Bleu\n\n\nQuel est votre choix ?\n");
                    printf("Vous pouvez revenir sur votre choix si la couleur ne vous plait pas a partir du menu.\n");
                    scanf("%d",&choixcouleur);
                    system("cls");

                    if(choixcouleur==1){
                        system("color 9");
                    }

                    if(choixcouleur==2){
                        system("color b");
                    }

                    if(choixcouleur==3){
                        system("color 3b");
                    }

                break;
            }
            {
                case 3:
                system("cls");
                printf("Voici les règles:\n\nIl s'aggit d'un jeu de bataille navale, vous devez couler tout les bataux de votre adversaire aussi vite que possible ou vous risquez d'avoir les poissons comme voisins !\n\n");
                printf("Comme dans tout jeu il y a également un score, il augemente de 10 si vous touchez un bateau mais en cas de tir dans l'eau il descend de 3\n\n");
                printf("Il a differents types de bateaux plus ou moins grands : \n => Les torpieurs ( 2 cases ) \n => Les sous-marins ( 3 cases ) \n => Les contre-torpieurs ( 3 cases ) \n => Les croiseurs ( 4 cases ) \n => Les porte-avions ( 5 cases ) \n");
                printf("Il n'y qu'un bateau de chaque type.\n\n");
                system("pause");
                system("cls");
                break;
            }
            {
                default:
                system("cls");
                printf("Merci d'avoir joué a ce jeu ! \n");
                system("pause");
                break;
            }
        }
    }
}




char playername[15];

int main() {
    SetConsoleOutputCP(65001);  //Cette liste permet d'afficher des accents

    printf("Bienvenu dans la bataille navalle !\n");
    printf("Comment vous appelez-vous capitaine ?\n");
    scanf("%s", playername);
    printf("Bienvenu %s !\n", playername);

    if (txtscore == NULL) {
        txtscore = fopen("Score.txt", "a");
        fprintf(txtscore,"-------------------------------------\n");
        fprintf(txtscore, "Pseudo du joueur : %s\n\n",playername);

    }



    printf("Que vouleuz-vous faire ?\n");

    menu();

    fclose(txtscore);



    return 0;
}