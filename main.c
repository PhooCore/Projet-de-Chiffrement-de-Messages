/******************************************************************************  
*  ASR => 4R2.04                                                              *  
*******************************************************************************  
*                                                                             *  
*  N° de Sujet :  3                                                           *  
*                                                                             *  
*******************************************************************************  
*                                                                             *  
*  Intitulé :  Chiffrement de messages                                       *  
*                                                                             *  
*******************************************************************************  
*                                                                             *  
*  Nom-prénom1 : NGUYEN Tuyet                                                *  
*                                                                             *  
*  Nom-prénom2 : AHMAD FAISAL Aneesa                                         *  
*                                                                             *  
*******************************************************************************  
*                                                                             *  
*  Nom du fichier : main.c                                                   *  
*                                                                             *  
******************************************************************************/  

#include <stdio.h>      //Pour l'affichage et la saisie
#include <wchar.h>      //Pour manipuler les chaînes wide-char (wchar_t)
#include <locale.h>     //Pour activer la prise en charge des caractères spéciaux (comme les accents) avec wchar_t
#include <stdbool.h>    //Pour utiliser le type bool
#include <string.h>     //Pour manipuler les chaînes
#include "source.h"     // Fichier d'en-tête contenant les déclarations des fonctions de chiffrement (César, Vigenère, etc.)

int main() {
    setlocale(LC_ALL, ""); // Support des caractères spéciaux (accents, etc.)

    wchar_t message[256];       //Déclaration du message
    wchar_t cle_vigenere[256];  // Déclaration de la clé Vigenère
    int cle_cesar;              // Déclaration de la clé
    int choix, choix2;          //Choix liés au menu (principal et sous-menu)
    int result, result2;        //Vérifier la validité des choix liés aux menus

    do {
        wprintf(L"\n=== MENU ===\n");
        wprintf(L"1. Chiffrement César\n");
        wprintf(L"2. Chiffrement Vigenère\n");
        wprintf(L"3. Quitter\n");

        // Lecture et validation du choix de l'utilisateur
        do {
            wprintf(L"Votre choix : ");
            result = wscanf(L"%d", &choix);
            if (result != 1 || choix < 1 || choix > 3) {
                while (getwchar() != L'\n'); // Vide le buffer après le scanf
                wprintf(L"Erreur. Veuillez entrer un nombre entre 1 et 3.\n");
            }
        } while (result != 1 || choix < 1 || choix > 3);

        // Si l'utilisateur décide de quitter le programme
        if (choix == 3) {
            wprintf(L"Fin du programme.\n");
            break;
        }

        while (getwchar() != L'\n'); // Vider le buffer

        // Demander un message à l'utilisateur
        bool valide = false; // Nous aide à savoir si la chaîne de caractères est valide
        while (!valide) {
            wprintf(L"Entrez un message : ");
            fgetws(message, 256, stdin);        //Lis le message
            size_t len = wcslen(message);       //Création d'une variable len pour rendre la lecture plus simple
            if (len > 0 && message[len - 1] == L'\n') {
                message[len - 1] = L'\0'; // Suppression du retour à la ligne
            }

            if (verifier_alphanumerique(message)) {
                valide = true;
            } else {
                wprintf(L"Erreur : Le message contient des caractères non autorisés (hors lettres/espaces).\n");
            }
        }

        // Nettoyage du message
        for (int i = 0; message[i] != L'\0'; i++) {
            message[i] = enlever_accent(message[i]); //Remplacer les accents par les caractères sans accent
        }
        

        switch (choix) {
            case 1: {
                // César
                wchar_t copie_cesar[256];
                wcsncpy(copie_cesar, message, 256);

                do {
                    wprintf(L"Entrez une clé (entier) pour le chiffrement César : ");
                    result = wscanf(L"%d", &cle_cesar); // Lire la clé entrée par l'utilisateur
                    if (result != 1) { // Si result n'est pas un entier alors il a comme valeur 0
                        // Vider le buffer d'entrée en lisant les caractères jusqu'à rencontrer un saut de ligne '\n'
                        while (getwchar() != L'\n');    // Ignore tous les caractères jusqu'à la touche "Entrée"
                        wprintf(L"Erreur. Veuillez entrer un nombre entier.\n");
                    }
                } while (result != 1);  // Tant que la clé n'est pas un entier, la boucle va continuer

                do {
                    //Sous-menu
                    wprintf(L"\nMessage actuel : %ls\n", copie_cesar);// Affiche le message de l'utilisateur
                    wprintf(L"Clé César : %d\n", cle_cesar);          // Affiche la clé saisie
                    wprintf(L"1. Chiffrer\n2. Déchiffrer\n3. Retour\n");

                    // Vérifie la validité du choix de l'utilisateur
                    wprintf(L"Votre choix : ");
                    result2 = wscanf(L"%d", &choix2);
                    if (result2 != 1 || choix2 < 1 || choix2 > 3) {
                        while (getwchar() != L'\n');    // Vide le buffer après le scanf
                        wprintf(L"Erreur. Veuillez entrer un nombre entre 1 et 3.\n");
                    }
                    
                    // Actions selon le choix de l'utilisateur
                    switch (choix2) {
                        case 1:
                            chiffrer_cesar(copie_cesar, cle_cesar);             // Appelle la fonction de chiffrement César
                            wprintf(L"Message chiffré : %ls\n", copie_cesar);   // Affichage
                            break;                                              // Permet de revenir au sous-menu directement
                        case 2:
                            dechiffrer_cesar(copie_cesar, cle_cesar);           // Appelle la fonction de déchiffrement César
                            wprintf(L"Message déchiffré : %ls\n", copie_cesar); // Affichage
                            break;                                              // Permet de revenir au sous-menu directement
                        case 3:
                            wprintf(L"Retour au menu principal.\n");
                            break;                                              // Permet de revenir au sous-menu directement
                    }

                } while (choix2 != 3);
                break;
            }

            case 2: {
                // Vigenère
                do {
                    wprintf(L"Entrez une clé Vigenère : ");
                    fgetws(cle_vigenere, 256, stdin);   // Lire la clé entrée par l'utilisateur
                    // Supprimer le saut de ligne final s'il est présent
                    size_t len = wcslen(cle_vigenere);
                    if (len > 0 && cle_vigenere[len - 1] == L'\n') {
                        cle_vigenere[len - 1] = L'\0'; 
                    }

                    // Nettoyage de la clé vigenère
                    for (int i = 0; cle_vigenere[i] != L'\0'; i++) { //Parcourt toute la clé
                        cle_vigenere[i] = enlever_accent(cle_vigenere[i]); //Remplacer les accents par les caractères sans accent
                    }
                    enlever_espaces(cle_vigenere);

                    //Vérifie la validité de la clé
                    if (wcslen(cle_vigenere) == 0) {
                        wprintf(L"La clé ne peut pas être vide.\n");
                    } else if (!verifier_alphanumerique(cle_vigenere)) {
                        wprintf(L"La clé contient des caractères non valides.\n");
                    }
                // Répéter tant que la clé est vide ou invalide
                } while (wcslen(cle_vigenere) == 0 || !verifier_alphanumerique(cle_vigenere));

                do {
                    //Sous-menu
                    wprintf(L"\nMessage actuel : %ls\n", message);          // Affiche le message de l'utilisateur
                    wprintf(L"Clé Vigenère : %ls\n", cle_vigenere);         // Affiche la clé saisie
                    wprintf(L"1. Chiffrer\n2. Déchiffrer\n3. Retour\n");
                    wprintf(L"Votre choix : ");
                    result2 = wscanf(L"%d", &choix2);   //Lis le choix de l'utilisateur
                    //Verifie la validité du choix (bien entre 1 et 3)
                    if (result2 != 1 || choix2 < 1 || choix2 > 3) {
                        while (getwchar() != L'\n');
                        wprintf(L"Erreur. Veuillez entrer un nombre entre 1 et 3.\n");
                    }

                    switch (choix2) {
                        case 1:
                            chiffrer_vigenere(message, cle_vigenere);       // Appelle la fonction de chiffrement Vigenère
                            wprintf(L"Texte chiffré : %ls\n", message);     // Affichage
                            break;                                          // Permet de revenir au sous-menu directement
                        case 2:
                            dechiffrer_vigenere(message, cle_vigenere);     // Appelle la fonction de chiffrement Vigenère
                            wprintf(L"Texte déchiffré : %ls\n", message);   // Affichage
                            break;                                          // Permet de revenir au sous-menu directement
                        case 3:
                            wprintf(L"Retour au menu principal.\n");
                            break;                                          // Permet de revenir au sous-menu directement
                    }

                } while (choix2 != 3);
                break;      // Permet de revenir au sous-menu directement
            }
        }

    } while (choix != 3);   // Quitte le programme
}