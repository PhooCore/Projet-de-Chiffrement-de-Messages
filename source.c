/******************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N° de Sujet :  3                                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé :  Chiffrement de messages                                                               *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : NGUYEN Tuyet                                                              *
*                                                                             *
*  Nom-prénom2 : AHMAD FAISAL Aneesa                                                            *                                                          *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier : source.c                                                          *
*                                                                             *
******************************************************************************/
#include "source.h"
#include <stdio.h>
#include <wctype.h> 

// Fonction pour vérifier que la chaîne ne contient que des lettres ou des espaces
bool verifier_alphanumerique(const wchar_t  *chaine) {
    for (int i = 0; chaine[i] != L'\0'; i++) {
        // Si le caractère n'est pas une lettre majuscule, minuscule ou un espace
        if (!(iswalpha(chaine[i]) || chaine[i] == L' ')) {
            return false; //Chaîne invalide
        }
    }
    return true; //Chaîne valide
}

// Fonction pour chiffrer une chaîne avec le chiffrement de César
void chiffrer_cesar(wchar_t  *chaine, int cle) {
    // Parcourt chaque caractère de la chaîne
    for (int i = 0; chaine[i] != L'\0'; i++) {

        // Si le caractère est une majuscule
        if (chaine[i] >= L'A' && chaine[i] <= L'Z') {
            // (chaine[i] - 'A') : position alphabétique du caractère
            // + cle : on décale cette position selon la clé
            // % 26 : on reste dans l'alphabet
            // + 'A' : on reconvertit la position en caractère majuscule
            chaine[i] = (chaine[i] - L'A' + cle) % 26 + L'A';

        // Si le caractère est une minuscule
        } else if (chaine[i] >= L'a' && chaine[i] <= L'z') {
            // Même logique que pour les majuscules
            chaine[i] = (chaine[i] - L'a' + cle) % 26 + L'a';
        } // Les autres caractères (espaces) ne sont pas modifiés
    }
}

// Fonction pour déchiffrer une chaîne avec le chiffrement de César
void dechiffrer_cesar(wchar_t  *chaine, int cle) {
    // Parcourt chaque caractère de la chaîne
    for (int i = 0; chaine[i] != L'\0'; i++) {

        // Si le caractère est une lettre majuscule
        if (chaine[i] >= L'A' && chaine[i] <= L'Z') {
            // On retire la clé pour revenir à la lettre d'origine
            // +26 puis %26 permet d'éviter un résultat négatif
            chaine[i] = (chaine[i] - L'A' - cle + 26) % 26 + L'A';

        // Si le caractère est une lettre minuscule
        } else if (chaine[i] >= L'a' && chaine[i] <= L'z') {
            // Même logique que pour les majuscules
            chaine[i] = (chaine[i] - L'a' - cle + 26) % 26 + L'a';
        }
    }
}

// Fonction pour chiffrer une chaîne avec le chiffrement de Vigenère
void chiffrer_vigenere(wchar_t  *chaine, const wchar_t  *cle) {
    int longueurCle = 0;

    // On calcule la longueur de la clé (nombre de lettres)
    while (cle[longueurCle] != L'\0') 
        longueurCle++;

    // i : index de la chaîne à chiffrer
    // j : index de la clé (qui boucle si elle est plus courte que la chaîne)
    for (int i = 0, j = 0; chaine[i] != L'\0'; i++) {
        wchar_t lettre = chaine[i];

        // Si c'est une lettre majuscule
        if (lettre >= L'A' && lettre <= L'Z') {
            // (lettre - 'A') : on calcule la position du caractère dans l'alphabet
            // (cle[j % longueurCle] - 'A') : on récupère la valeur de la clé
            // + : on additionne la position de la lettre et la clé pour déplacer la lettre dans l'alphabet
            // % 26 : on prend le reste de la division par 26 pour rester dans les limites de l'alphabet
            // + 'A' : on reconvertit la position résultante en caractère majuscule
            chaine[i] = (lettre - L'A' + (cle[j % longueurCle] - L'A')) % 26 + L'A';
            j++;// On passe à la lettre suivante de la clé
        
        // Si le caractère est une lettre minuscule 
        } else if (lettre >= L'a' && lettre <= L'z') {
            // Même logique que pour les minuscule
            chaine[i] = (lettre - L'a' + (cle[j % longueurCle] - L'a')) % 26 + L'a';
            j++;
        }
    }
}

// Fonction pour déchiffrer une chaîne avec le chiffrement de Vigenère
void dechiffrer_vigenere(wchar_t  *chaine, const wchar_t  *cle) {
    int longueurCle = 0;

    // On calcule la longueur de la clé
    while (cle[longueurCle] != L'\0') 
        longueurCle++;

    // i : index de la chaîne à déchiffrer
    // j : index de la clé (qui tourne en boucle si elle est plus courte que la chaîne)
    for (int i = 0, j = 0; chaine[i] != L'\0'; i++) {
        wchar_t lettre = chaine[i];

        // Si c'est une lettre majuscule
        if (lettre >= L'A' && lettre <= L'Z') {
            // (lettre - 'A') : on calcule la position du caractère dans l'alphabet
            // (cle[j % longueurCle] - 'A') : on récupère la valeur de la clé
            // - cle[j % longueurCle] : on soustrait la valeur de la clé à la position de la lettre pour inverser le chiffrement
            // + 26 : on ajoute 26 pour éviter d'obtenir des indices négatifs (en cas de soustraction trop forte)
            // % 26 : on prend le reste de la division par 26 pour nous assurer que la position reste dans les limites de l'alphabet
            // + 'A' : on reconvertit la position résultante en caractère majuscule
            chaine[i] = (lettre - L'A' - (cle[j % longueurCle] - L'A') + 26) % 26 + L'A';
            j++;// On avance dans la clé

        // Si c'est une lettre minuscule
        } else if (lettre >= L'a' && lettre <= L'z') {
            // Même logique que pour les minuscule
            chaine[i] = (lettre - L'a' - (cle[j % longueurCle] - L'a') + 26) % 26 + L'a';
            j++;
        }
    }
}

// Fonction pour retirer tous les espaces d'une chaîne de caractères
void enlever_espaces(wchar_t  *chaine) {
    // i est utilisé pour parcourir la chaîne
    // j pour reconstruire la chaîne sans espaces
    int i, j = 0;

    // Parcours de chaque caractère de la chaîne
    for (i = 0; chaine[i] != L'\0'; i++) {
        // Si le caractère n'est pas un espace
        if (chaine[i] != L' ') {
            // On copie le caractère à la position j
            chaine[j++] = chaine[i];
        }
    }
    // À la fin de la chaîne, on ajoute un caractère nul pour marquer la fin de la nouvelle chaîne
    chaine[j] = L'\0';
}

// Fonction pour enlever les accents
wchar_t enlever_accent(wchar_t c) {
    switch (c) {
        case L'à': case L'á': case L'â': case L'ä': case L'ã': case L'å': return L'a';
        case L'è': case L'é': case L'ê': case L'ë': return L'e';
        case L'ì': case L'í': case L'î': case L'ï': return L'i';
        case L'ò': case L'ó': case L'ô': case L'ö': case L'õ': return L'o';
        case L'ù': case L'ú': case L'û': case L'ü': return L'u';
        case L'ç': return L'c';

        case L'À': case L'Á': case L'Â': case L'Ä': case L'Ã': case L'Å': return L'A';
        case L'È': case L'É': case L'Ê': case L'Ë': return L'E';
        case L'Ì': case L'Í': case L'Î': case L'Ï': return L'I';
        case L'Ò': case L'Ó': case L'Ô': case L'Ö': case L'Õ': return L'O';
        case L'Ù': case L'Ú': case L'Û': case L'Ü': return L'U';
        case L'Ç': return L'C';

        default: return c;
    }
}
