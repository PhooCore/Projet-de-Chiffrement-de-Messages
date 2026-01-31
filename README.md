# Projet de Chiffrement de Messages

Un programme en C permettant de chiffrer et déchiffrer des messages en utilisant deux algorithmes classiques : **César** et **Vigenère**.

## Table des matières

- [Description](#description)
- [Fonctionnalités](#fonctionnalités)
- [Prérequis](#prérequis)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Algorithmes implémentés](#algorithmes-implémentés)
- [Auteurs](#auteurs)

## Description

Ce projet a été réalisé en binôme dans le cadre de la ressource  **R2.04 : Communication et fonctionnement bas niveau**. Nous avons eu le choix entre 3 différents projets, le chiffrement en était le 3e. 
Il s'agit d'une application console interactive qui permet de chiffrer et déchiffrer des messages textuels en utilisant deux méthodes de chiffrement historiques.
Le programme gère les caractères accentués et offre une interface utilisateur intuitive.

## Fonctionnalités

- Chiffrement et déchiffrement avec l'algorithme de **César**
- Chiffrement et déchiffrement avec l'algorithme de **Vigenère**
- Support des caractères accentués (conversion automatique)
- Gestion des majuscules et minuscules
- Validation des entrées utilisateur
- Interface en français avec support UTF-8
- Menu interactif avec navigation facile

## Prérequis

- **Compilateur C** : GCC (GNU Compiler Collection) ou équivalent
- **Système d'exploitation** : Linux, macOS, ou Windows (avec MinGW)
- **Make** : Pour utiliser le Makefile (optionnel)

## Installation

### Cloner le dépôt

```bash
git clone https://github.com/votre-username/chiffrement-messages.git
cd chiffrement-messages
```

### Compilation avec Make

```bash
make
```

### Compilation manuelle

```bash
gcc -c source.c -o source.o
gcc -c main.c -o main.o
gcc source.o main.o -o main
```

### Exécution

```bash
./main
```

Ou sur Windows :
```bash
main.exe
```

## Utilisation

1. **Lancez le programme** : `./main`
2. **Choisissez un algorithme** :
   - Option 1 : Chiffrement César
   - Option 2 : Chiffrement Vigenère
   - Option 3 : Quitter
3. **Entrez votre message** (lettres et espaces uniquement)
4. **Entrez la clé** :
   - Pour César : un nombre entier (ex: 3)
   - Pour Vigenère : un mot (ex: "CRYPTO")
5. **Choisissez une action** :
   - Chiffrer le message
   - Déchiffrer le message
   - Retourner au menu principal

## Algorithmes implémentés

### Chiffrement de César

Le chiffrement de César consiste à décaler chaque lettre de l'alphabet d'un nombre fixe de positions. Par exemple, avec un décalage de 3 :
- A → D
- B → E
- Z → C

**Exemple** : 
- Message : `HELLO`
- Clé : `3`
- Chiffré : `KHOOR`

### Chiffrement de Vigenère

Le chiffrement de Vigenère utilise un mot-clé pour déterminer le décalage de chaque lettre. C'est un chiffrement polyalphabétique plus sécurisé que César.

**Exemple** :
- Message : `HELLO`
- Clé : `KEY`
- Chiffré : `RIJVS`

## Auteurs

- **NGUYEN Tuyet Phuong** 
- **AHMAD FAISAL Aneesa** 

## Licence

Ce projet est un travail académique réalisé à des fins éducatives.

⭐ N'hésitez pas à mettre une étoile si ce projet vous a été utile !
