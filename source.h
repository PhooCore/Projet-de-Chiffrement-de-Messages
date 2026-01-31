/******************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N° de Sujet :  3                                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé :  Chiffrement de messages                                       *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : NGUYEN Tuyet                                                 *
*                                                                             *
*  Nom-prénom2 : AHMAD FAISAL Aneesa                                          *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier : source.h                                                  *
*******************************************************************************/

#ifndef SOURCE_H    // Si SOURCE_H n'a pas encore été défini
#define SOURCE_H    // Définir SOURCE_H pour éviter les inclusions multiples

#include <stdbool.h>  // Inclut la bibliothèque qui permet d'utiliser le type bool 
#include <wchar.h>     // Pour wchar_t, fonctions associées

// Déclare une fonction qui vérifie si une chaîne de caractères est alphanumérique
bool verifier_alphanumerique(const wchar_t  *chaine); 

// Déclare une fonction qui chiffre une chaîne de caractères selon l'algorithme de chiffrement de César
// La clé 'cle' est un nombre qui détermine le décalage des lettres
void chiffrer_cesar(wchar_t  *chaine, int cle);

// Déclare une fonction qui déchiffre une chaîne de caractères selon l'algorithme de chiffrement de César
// La clé 'cle' est un nombre qui détermine le décalage des lettres
void dechiffrer_cesar(wchar_t  *chaine, int cle);

// Déclare une fonction qui chiffre une chaîne de caractères selon l'algorithme de Vigenère
// La clé 'cle' est une chaîne de caractères utilisée pour déterminer le décalage pour chaque lettre
void chiffrer_vigenere(wchar_t  *chaine, const wchar_t  *cle);

// Déclare une fonction qui déchiffre une chaîne de caractères selon l'algorithme de Vigenère
// La clé 'cle' est une chaîne de caractères utilisée pour déterminer le décalage pour chaque lettre
void dechiffrer_vigenere(wchar_t  *chaine, const wchar_t  *cle);

// Déclare une fonction qui enlève les espaces d'une chaîne de caractères
// Elle modifie la chaîne en place, supprimant tous les espaces
void enlever_espaces(wchar_t  *cle);

// Déclare une fonction qui enlève les accents d’un caractère
// Retourne le caractère équivalent non accentué s’il existe, sinon retourne le caractère original
wchar_t enlever_accent(wchar_t c);

#endif // SOURCE_H
