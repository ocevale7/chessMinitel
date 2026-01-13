////////////////////////////////////////////////////////////////////////
/*
   Minitel1B_Hard - Fichier d'en-tête - Version du 5 mars 2023 à 21h27
   Copyright 2016-2023 - Eric Sérandour
   https://entropie.org/3615/
   
   Remerciements à :
   BorisFR, iodeo
   
   Documentation utilisée :
   Spécifications Techniques d'Utilisation du Minitel 1B
   http://543210.free.fr/TV/stum1b.pdf
   
////////////////////////////////////////////////////////////////////////
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
////////////////////////////////////////////////////////////////////////

#ifndef MINITEL1B_H  // Si la constante MINITEL1B_H n'est
#define MINITEL1B_H  // pas définie, on la définit.



////////////////////////////////////////////////////////////////////////

// Le standard Télétel

// Chapitre 2 : L'écran

// 1 Mode Vidéotex

// 1.2.3 Codage des caractères visualisables
// Jeu G0 => alphanumérique (voir p.100)
// Jeu G1 => semi-graphique (voir p.101 et 102)
// Jeu G2 => complément à G0 (voir p.103)
// Les caractères du jeu G2 sont obtenus si précédés du code SS2 (x19).
// On peut les afficher directement en utilisant printSpecialChar(byte b) :
#define LIVRE              0x23
#define DOLLAR             0x24
#define DIESE              0x26
#define PARAGRAPHE         0x27
#define FLECHE_GAUCHE      0x2C
#define FLECHE_HAUT        0x2D
#define FLECHE_DROITE      0x2E
#define FLECHE_BAS         0x2F
#define DEGRE              0x30
#define PLUS_OU_MOINS      0x31
#define DIVISION           0x38
#define UN_QUART           0x3C
#define UN_DEMI            0x3D
#define TROIS_QUART        0x3E
#define OE_MAJUSCULE       0x6A
#define OE_MINUSCULE       0x7A
#define BETA               0x7B
// Les diacritiques ne peuvent pas être affichés seuls.
// printSpecialChar(byte b) n'aura donc aucun effet ici.
#define ACCENT_GRAVE       0x41
#define ACCENT_AIGU        0x42
#define ACCENT_CIRCONFLE0xE 0x43
#define TREMA              0x48
#define CEDILLE            0x4B


// 1.2.4 Codage des attributs de visualisation (voir p.91)
// Ces fonctions sont obtenues si précédées du code ESC (0x1B).
// Nous avons alors accès à la grille C1. On peut y accéder directement
// en utilisant attributs(byte attribut).
// Couleur de caractère
#define CARACTERE_NOIR    (uint8_t*)"\x40" 
#define CARACTERE_ROUGE   (uint8_t*)"\x41" 
#define CARACTERE_VERT    (uint8_t*)"\x42" 
#define CARACTERE_JAUNE   (uint8_t*)"\x43" 
#define CARACTERE_BLEU    (uint8_t*)"\x44" 
#define CARACTERE_MAGENTA (uint8_t*)"\x45" 
#define CARACTERE_CYAN    (uint8_t*)"\x46" 
#define CARACTERE_BLANC   (uint8_t*)"\x47" 
// Couleur de fond             
#define FOND_NOIR         (uint8_t*)"\x50" 
#define FOND_ROUGE        (uint8_t*)"\x51" 
#define FOND_VERT         (uint8_t*)"\x52" 
#define FOND_JAUNE        (uint8_t*)"\x53" 
#define FOND_BLEU         (uint8_t*)"\x54" 
#define FOND_MAGENTA      (uint8_t*)"\x55" 
#define FOND_CYAN         (uint8_t*)"\x56" 
#define FOND_BLANC        (uint8_t*)"\x57" 
// Taille
#define GRANDEUR_NORMALE  0x4C  // Non utilisable en mode graphique
#define DOUBLE_HAUTEUR    0x4D  // Non utilisable en mode graphique
#define DOUBLE_LARGEUR    0x4E  // Non utilisable en mode graphique
#define DOUBLE_GRANDEUR   0x4F  // Non utilisable en mode graphique
// Clignotement ou fi0xité
#define CLIGNOTEMENT      0x48
#define FI0xE              0x49
// Début et fin de masquage
#define MASQUAGE          0x58
#define DEMASQUAGE        0x5F
// Début ou fin de lignage
#define FIN_LIGNAGE       0x59
#define DEBUT_LIGNAGE     0x5A  // En mode te0xte, l'espace (0x20) marque le début d'une zone de lignage. C'est l'élément déclencheur (voir p.93).
// Fond inversé ou normal
#define FOND_NORMAL       0x5C  // Non utilisable en mode graphique
#define INVERSION_FOND    0x5D  // Non utilisable en mode graphique
// Echappement vers la norme ISO 6429
#define CSI               0x1B5B


// 1.2.5 Fonctions de mise en page (voir p.94)
#define BS   0x08  // BackSpace : Déplacement du curseur d'un emplacement de caractère à gauche.
#define HT   0x09  // Horizontal Tab : Déplacement du curseur d'un emplacement de caractère à droite.
#define LF   0x0A  // Line Feed : Déplacement du curseur d'un emplacement de caractère vers le bas.
#define VT   0x0B  // Vertical Tab : Déplacement du curseur d'un emplacement de caractère vers le haut.
//#define CR   0x0D  // Carriage Return : Retour du curseur au début de la rangée courante.
// Les fonctions de type CSI sont développées à l'intérieur de la classe Minitel (plus bas).
#define RS   0x1E  // Record Separator : Retour du curseur en première position de la rangée 01. Ce code est un séparateur e0xplicite d'article.
#define FF   0x0C  // Form Feed : Retour du curseur en première position de la rangée 01 avec effacement complet de l'écran.
#define US   0x1F  // Unit Separator : Séparateur de sous-article.
#define CAN  0x18  // Cancel : Remplissage à partir de la position courante du curseur et jusqu'à la fin de la rangée par des espaces du jeu courant ayant l'état courant des attributs. La position courante du curseur n'est pas déplacée.


// 1.2.6 Autres fonctions (voir p.98)
// 1.2.6.1 Fonctions diverses :
#define REP  0x12  // Repetition : Permet de répéter le dernier caractère visualisé avec les attributs courants de la position active d'écriture.
#define NUL  0x00  // Null :
#define SP   0x20  // Space :
#define DEL  0x7F  // Delete :
#define BEL  0x07  // Bell : Provoque l'émission d'un signal sonore
// 1.2.6.2 Demande de position du curseur
//...
// 1.2.6.3 Fonctions d'e0xtension de code
#define SO   (uint8_t*)"\x0E"  // Shift Out : Accès au jeu G1. => Mode semi-graphique
#define SI   (uint8_t*)"\x0F"  // Shift In : Accès au jeu G0.  => Mode alphanumérique
#define SS2  (uint8_t*)"\x19"  // Single Shift 2 : Appel d'un caractère unique du jeu G2.
#define ESC  (uint8_t*)"\x1B"  // Escape : Echappement et accès à la grille C1.
// 1.2.6.4 Visualisation du curseur
#define CON  0x11  // Visualisation de la position active du curseur (curseur actif).
#define COFF 0x14  // Arrêt de la visualisation de la position active (curseur inactif).


// 1.2.7 Filtages particuliers (voir p.99)
//...


// 1.2.8 Comportements en cas d'erreur et resynchronisation (voir p.99)
// ...




// Chapitre 3 : Le clavier

// 6 Séquences émises par les touches de fonction en mode Vidéote0x ou Mi0xte (voir p.123)
#define ENVOI          0x1341
#define RETOUR         0x1342
#define REPETITION     0x1343
#define GUIDE          0x1344
#define ANNULATION     0x1345
#define SOMMAIRE       0x1346
#define CORRECTION     0x1347
#define SUITE          0x1348
#define CONNEXION_FIN  0x1359  // Non documenté

// 7 Codes et séquences émis par les touches de gestion du curseur et d'édition en mode Vidéote0x ou Mi0xte (voir p.124)
#define TOUCHE_FLECHE_HAUT         0x1B5B41
#define SUPPRESSION_LIGNE          0x1B5B4D
#define TOUCHE_FLECHE_BAS          0x1B5B42
#define INSERTION_LIGNE            0x1B5B4C
#define TOUCHE_FLECHE_DROITE       0x1B5B43
#define DEBUT_INSERTION_CARACTERE  0x1B5B3468
#define FIN_INSERTION_CARACTERE    0x1B5B346C
#define TOUCHE_FLECHE_GAUCHE       0x1B5B44
#define SUPRESSION_CARACTERE       0x1B5B50
// #define DEL                        0x7F  // Déjà défini plus haut (1.2.6.1)
// #define CR                         0x0D  // Déjà défini plus haut (1.2.5)
#define HOME                       0x1B5B4B
#define EFFACEMENT_PAGE            0x1B5B324A




// Chapitre 6 : Le Protocole (voir p.134)

// 1 Généralités (voir p.134)
#define CODE_EMISSION_ECRAN        0x50
#define CODE_EMISSION_CLAVIER      0x51
#define CODE_EMISSION_MODEM        0x52
#define CODE_EMISSION_PRISE        0x53
#define CODE_RECEPTION_ECRAN       0x58
#define CODE_RECEPTION_CLAVIER     0x59
#define CODE_RECEPTION_MODEM       0x5A
#define CODE_RECEPTION_PRISE       0x5B

// 3 Commandes d'aiguillages et de blocage des modules (voir p.134)
// 3.2 Format des commandes (voir p.135)
#define AIGUILLAGE_OFF             0x60
#define AIGUILLAGE_ON              0x61
// 3.4 Demande de statut d'aiguillages des modules (voir p.136)
#define TO                         0x62
#define FROM                       0x63

// 6 Demandes d'identification et de position curseur (voir p.139)
// 6.1 Demande d'identification du Minitel (voir p.139)
#define ENQROM                     0x7B

// 7 Commandes relatives au modem (voir p.139)
#define CONNEXION                  0x68
#define DECONNEXION                0x67

// 8 Commandes relatives à la prise (voir p.141)
#define PROG                       0x6B
#define STATUS_VITESSE             0x74

// 9 Commandes relatives au clavier (voir p.141)
#define ETEN                       0x41  // Clavier en mode étendu

// 10 Commandes relatives à l'écran (voir p.142)
#define ROULEAU                    0x43  // Ecran en mode rouleau

// 11 Commandes relatives à plusieurs modules (voir p.143)
#define START                      0x69
#define STOP                       0x6A
#define MINUSCULES                 0x45  // Mode minuscules / majuscules du clavier

// 12 Commandes Protocole relatives au changement de standard  (voir p.144)
#define MIXTE1                     0x327D
#define MIXTE2                     0x327E
#define TELINFO                    0x317D

// 13 L'état initial du minitel
// 13.2 Sur réception d'une commande de reset
//#define RESET                      0x7F




// Constantes personnelles pour hline et vline
#define CENTER  0
#define TOP     1
#define BOTTOM  2
#define LEFT    3
#define RIGHT   4
#define UP      5
#define DOWN    6


#define MINITEL_UART  UART_DEV(0)
#define MINITEL_BAUD  1200U


#include "board.h"
#include "periph/uart.h"
#include "stdio_uart.h"
#include "xtimer.h"

////////////////////////////////////////////////////////////////////////



void graphic_mode();
void text_mode();
void flush_minitel();

void write_bytes(uint8_t* b, size_t len);
void set_fg_color(uint8_t* c);
void set_bg_color(uint8_t* c);

void set_bg_black();
void set_bg_white();

void set_fg_white(bool darker);
void set_fg_black(bool lighter);

void retour_ligne();
void moveCursorXY(int x, int y);
void outMinitel(const char* str);
////////////////////////////////////////////////////////////////////////

#include "CoupleList.h"

int askIntMinitel(const char* label, int x, int y);
void recupInputMinitel(Couple& from, Couple& to);

#endif // Fin Si (MINITEL1B_H)