# Wiki Chessminitel

## 1. Composition de l'équipe
- ARDISSON Noémie
- BOISSET Valentin
- PY Antonin

## 2. Description du projet

Notre projet était de développer un jeu d'échecs à quatre joueurs en réseau, utilisant quatre Minitels comme interfaces utilisateur. Chacun étant connecté à une carte RiotOS équipée d'un module LoRa pour la communication sans fil. L'objectif est de réaliser une partie complète, stable et synchronisée en réseau. Chaque joueur peut voir l'état du plateau de jeu, les pièces en mouvement, et effectuer ses propres mouvements en utilisant le clavier du Minitel. La communication entre les Minitels est assurée par les modules LoRa, garantissant que chaque joueur voit les mises à jour en temps réel malgré la distance qui les sépare.

## 3. Problématique

Le problème que nous avons identifié est de démontrer la faisabilité et la fiabilité de la communication en réseau LoRa pour une application interactive et critique en temps réel (un jeu), en utilisant des matériels hétérogènes et contraints (Minitel, RiotOS, LoRa). Spécifiquement, il s'agit de résoudre la complexité d'assurer une synchronisation parfaite de l'état du jeu sur quatre nœuds distincts malgré les contraintes du réseau LoRa (débit faible, latence variable, taille limitée des messages, pas de garantie de réception). TODO

## 4. Matériel utilisé

Nous avons utilisé tout au long de ce projet trois cartes RIOT-OS avec chacune un STLink permettant de la programmer. La plupart du temps nous n'avons utilisé qu'un minitel pendant les séances pour développer l'affichage ou pour mettre en place la récupération des input clavier celui-ci étant toujours associé à un amplificateur afin de passer de 3,3 V à 5V. Dans les faits, le but est qu'une partie puisse se jouer sur de un à quatre minitels distincts chacun avec sa carte RIOT-OS et son amplificateur.


## 5. Scénario d'utilisation

Quatre amis souhaitent faire une partie d'échec sur minitel en 1 contre 1 contre 1 contre 1. Ces amis ne se trouvent pas au même endroit mais chacun possède un minitel relié à une carte RiotOS avec un module LoRa. Ils lancent l'application sur leur minitel respectif et se connectent à la partie. Chacun peut alors voir l'état du plateau de jeu, les pièces en mouvement, et effectuer ses propres mouvements en utilisant le clavier du minitel. La communication entre les minitels est assurée par les modules LoRa, garantissant que chaque joueur voit les mises à jour en temps réel malgré la distance qui les sépare.

Pour commencer la partie, chaque joueur flash sa carte RiotOS avec le firmware du jeu d'échecs. Une fois l'application lancée, chaque minitel est configuré pour se connecter au réseau LoRa et rejoindre la partie en cours. Son numéro de joueur (0 à 3) doit être spécifié au moment du make.

Ils entament une partie, chaque joueur effectuant ses mouvements à tour de rôle. Le système gère la synchronisation des états du jeu, assurant que tous les joueurs voient les mêmes informations en temps réel.

À la fin de la partie, le classement est affiché sur chaque minitel.

## 6. Budget approximatif


## 7. Bilan du projet


## 8. Idées d'améliorations

