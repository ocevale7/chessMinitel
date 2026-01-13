# Wiki Chessminitel

## 1. Composition de l'équipe
- ARDISSON Noémie
- BOISSET Valentin
- PY Antonin

## 2. Description du projet

Notre projet était de développer un jeu d'échecs à quatre joueurs en réseau, utilisant quatre Minitels comme interfaces utilisateur. Chacun étant connecté à une carte RiotOS équipée d'un module LoRa pour la communication sans fil. L'objectif est de réaliser une partie complète, stable et synchronisée en réseau. Chaque joueur peut voir l'état du plateau de jeu, les pièces en mouvement, et effectuer ses propres mouvements en utilisant le clavier du Minitel. La communication entre les Minitels est assurée par les modules LoRa, garantissant que chaque joueur voit les mises à jour en temps réel malgré la distance qui les sépare.

## 3. Problématique

Le problème que nous avons identifié est de démontrer la faisabilité et la fiabilité de la communication en réseau LoRa pour une application interactive et critique en temps réel (un jeu), en utilisant des matériels hétérogènes et contraints (Minitel, RiotOS, LoRa). Spécifiquement, il s'agit de résoudre la complexité d'assurer une synchronisation parfaite de l'état du jeu sur quatre nœuds distincts malgré les contraintes du réseau LoRa (débit faible, latence variable, taille limitée des messages, pas de garantie de réception). Ce problème est crucial car il met en lumière les défis techniques liés à l'utilisation de technologies anciennes (Minitel) combinées à des technologies modernes (LoRa, RiotOS) pour créer une expérience utilisateur fluide et cohérente dans un contexte de jeu en réseau.

Nous avons dû aborder plusieurs sous-problèmes pour atteindre cet objectif :
- **Gestion des entrées utilisateur** : Capturer et interpréter les commandes du clavier du Minitel de manière efficace.
- **Affichage graphique** : Adapter l'affichage des pièces d'échecs sur l'écran du Minitel, qui a des limitations graphiques.
- **Protocole de communication** : Concevoir un protocole léger et robuste pour la transmission des états du jeu entre les Minitels via LoRa.
- **Synchronisation de l'état du jeu** : Assurer que tous les Minitels affichent le même état du jeu en temps réel, malgré les pertes de paquets et les délais inhérents au réseau LoRa.

Nous avons atteint nos objectifs en développant une application qui permet à quatre joueurs de participer à une partie d'échecs en réseau, avec une interface utilisateur fonctionnelle sur le Minitel et une communication fiable via LoRa. Le système gère efficacement les entrées utilisateur, met à jour l'affichage en temps réel, et maintient la synchronisation de l'état du jeu entre les différents nœuds.

## 4. Matériel utilisé

Nous avons utilisé tout au long de ce projet trois cartes RIOT-OS avec chacune un STLink permettant de la programmer. La plupart du temps nous n'avons utilisé qu'un minitel pendant les séances pour développer l'affichage ou pour mettre en place la récupération des input clavier celui-ci étant toujours associé à une carte afin de passer de 3,3 V à 5V et inversement. Dans les faits, le but est qu'une partie puisse se jouer avec de un à quatre minitels distincts chacun avec sa carte RIOT-OS et sa carte pour l'amplification.


## 5. Scénario d'utilisation

Quatre amis, dont deux en colocation, souhaitent faire une partie d'échec sur minitel en 1 contre 1 contre 1 contre 1. Ces amis ne se trouvent pas au même endroit mais à chaque endroit il y a un minitel relié à une carte RiotOS avec un module LoRa. Ils lancent l'application sur leur minitel respectif et se connectent à la partie. Chacun peut alors voir l'état du plateau de jeu, les pièces en mouvement, et effectuer ses propres mouvements en utilisant le clavier du minitel. La communication entre les minitels est assurée par les modules LoRa, garantissant que chaque joueur voit les mises à jour en temps réel malgré la distance qui les sépare.

Pour commencer la partie, chaque joueur flash sa carte RiotOS avec le firmware du jeu d'échecs. Une fois l'application lancée, chaque minitel est configuré pour se connecter au réseau LoRa et rejoindre la partie en cours. Les numéros des joueurs jouant sur le minitel doivent être spécifiés au moment du make (par défaut les quatre joueurs jouent sur le même minitel mais on peut en mettre de un à quatre sur le même minitel). Par exemple, pour jouer en tant que joueur 1 et 3 sur le même minitel, la commande serait : `make JOUEUR=13` (les joueurs vont de 0 à 3).

Ils entament une partie, chaque joueur effectuant ses mouvements à tour de rôle. Le système gère la synchronisation des états du jeu, assurant que tous les joueurs voient les mêmes informations en temps réel.

À la fin de la partie, le classement est affiché sur chaque minitel.

## 6. Budget approximatif

7 * 3 h de cours + 5 * 3h de jeudi aprem + ~15h de dev du jeux + ? 

## 7. Bilan du projet


## 8. Idées d'améliorations

Mettre un bot contre qui ont peut jouer, pouvoir avoir plusieurs types d'interface homme - machine