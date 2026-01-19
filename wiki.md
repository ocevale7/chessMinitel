# Wiki Chessminitel

## 1. Composition de l'équipe
- ARDISSON Noémie
- BOISSET Valentin
- PY Antonin

## 2. Description du projet

Notre projet était de développer un jeu d'échecs à quatre joueurs en réseau, utilisant quatre Minitels comme interfaces utilisateur. Chacun étant connecté à une carte RiotOS équipée d'un module LoRa pour la communication sans fil. L'objectif est de réaliser une partie complète, stable et synchronisée en réseau. Chaque joueur peut voir l'état du plateau de jeu, les pièces en mouvement, et effectuer ses propres mouvements en utilisant le clavier du Minitel. La communication entre les Minitels est assurée par les modules LoRa, garantissant que chaque joueur voit les mises à jour en temps réel malgré la distance qui les sépare.

![Photo de l'installation](images/image_montage.jpg)

On voit sur l'image une installation avec un Minitel relié à une carte RiotOS (carte verte) équipée d'un module LoRa. Celle-ci est reliée à une carte STLink permettant de flasher le programme sur la cartes wyres. Le Minitel sert d'interface utilisateur pour le jeu d'échecs, tandis que la carte RiotOS gère la logique du jeu et la communication via LoRa avec les autres Minitels.

## 3. Problématique

Le problème que nous avons identifié est de démontrer la faisabilité et la fiabilité de la communication en réseau LoRa pour une application interactive et critique en temps réel (un jeu), en utilisant des matériels hétérogènes et contraints (Minitel, RiotOS, LoRa). Spécifiquement, il s'agit de résoudre la complexité d'assurer une synchronisation parfaite de l'état du jeu sur quatre nœuds distincts malgré les contraintes du réseau LoRa (débit faible, latence variable, taille limitée des messages, pas de garantie de réception). Ce problème est crucial car il met en lumière les défis techniques liés à l'utilisation de technologies anciennes (Minitel) combinées à des technologies modernes (LoRa, RiotOS) pour créer une expérience utilisateur fluide et cohérente dans un contexte de jeu en réseau.

Nous avons dû aborder plusieurs sous-problèmes pour atteindre cet objectif :
- **Gestion des entrées utilisateur** : Capturer et interpréter les commandes du clavier du Minitel de manière efficace.
- **Affichage graphique** : Adapter l'affichage des pièces d'échecs sur l'écran du Minitel, qui a des limitations graphiques.
- **Protocole de communication** : Concevoir un protocole léger et robuste pour la transmission des états du jeu entre les Minitels via LoRa.
- **Synchronisation de l'état du jeu** : Assurer que tous les Minitels affichent le même état du jeu en temps réel, malgré les pertes de paquets et les délais inhérents au réseau LoRa.

Nous avons atteint nos objectifs en développant une application qui permet à quatre joueurs de participer à une partie d'échecs en réseau, avec une interface utilisateur fonctionnelle sur le Minitel et une communication des coups via LoRa. La communication des coups n'est pas parfaite (notamment à cause de lectures erronées), il resterait à fiabiliser les échanges LoRa. Le système gère efficacement les entrées utilisateur, met à jour l'affichage en temps réel, et maintient la synchronisation de l'état du jeu entre les différents nœuds.

## 4. Matériel et Technologies utilisés

### 4.1 Matériel

Nous avons utilisé tout au long de ce projet trois cartes wyres avec RIOT-OS, chacune avec un STLink permettant de la programmer. La plupart du temps nous n'avons utilisé qu'un minitel pendant les séances pour développer l'affichage ou pour mettre en place la récupération des input clavier celui-ci étant toujours associé à une carte afin de passer de 3,3 V à 5V et inversement. Dans les faits, le but est qu'une partie puisse se jouer avec de un à quatre minitels distincts chacun avec sa carte RIOT-OS et sa carte pour l'amplification.

![Carte Wyres-Base](images/image_carte_wyres_stlink.jpg)

La carte Wyres est la carte verte sur la photo, elle est équipée d'un module LoRa. La carte STLink est la carte bleue en dessous de la carte Wyres, elle permet de flasher le firmware sur la carte Wyres.

![Minitel](images/image_montage.jpg)

Le minitel est ici relié à la carte Wyres via une carte d'interface conçue par le fablab pour adapter les niveaux de tension et les connecteurs. Le Minitel sert d'interface utilisateur pour le jeu d'échecs, tandis que la carte Wyres gère la logique du jeu et la communication via LoRa avec les autres Minitels.

![Affichage sur le Minitel](images/image_plateau_minitel.jpg)

Nous avons adapté l'affichage des pièces d'échecs aux contraintes graphiques du Minitel, en utilisant des caractères semigraphiques pour représenter les différentes pièces et le plateau de jeu.

### 4.2 Technologies

Nous avons utilisé le système d'exploitation temps réel RIOT-OS pour gérer les tâches de notre application, notamment la communication LoRa et l'interface utilisateur Minitel. Le langage de programmation principal utilisé est le C++, qui nous a permis de structurer notre code de manière modulaire et orientée objet.

#### 4.2.1 Communication LoRa
 
Le LoRa (Long Range) est la technologie de communication sans fil que nous avons choisie pour permettre la communication entre les différents Minitels. Elle est adaptée aux applications nécessitant une faible consommation d'énergie et une longue portée, ce qui est idéal pour notre projet de jeu en réseau. De plus, un module LoRa est intégré à chaque carte wyres utilisée. Le protocole de communication que nous avons développé est un protocole de communication point à point simplifié pour minimiser la taille des messages échangés, en se concentrant uniquement sur les informations essentielles nécessaires pour synchroniser l'état du jeu entre les différents nœuds. Celui-ci inclut seulement les informations sur le coup joué (position de départ et position d'arrivée) ainsi qu'un entête permettant de déterminer que le message provient bien de notre jeu. Ce protocole n'est donc pas robuste face aux pertes de paquets ou aux corruptions, mais il permet une communication efficace dans le contexte de notre application. Nous avons cependant quelques corruptions que nous n'avions pas anticipées. On ne peut donc pas garantir que tous les coups soient bien reçus par tous les minitels. En génral, ils sont reçus, mais ont été corrompus et le jeu les considère donc comme invalides.

#### 4.2.2 Interface utilisateur Minitel

Nous avons programmé l'interface utilisateur sur le Minitel en utilisant les caractères semigraphiques disponibles, en adaptant l'affichage des pièces d'échecs aux contraintes graphiques du Minitel. Les pièces sont donc représentées par des formes simplifiées, mais restant reconnaissables et un glossaire des pièces est affiché tout au long de la partie pour aider les joueurs. Pour voir les pièces et la table des caractères semigraphiques disponibles sur le Minitel, vous pouvez consulter le README du projet.

La saisie des coups se fait via le clavier du Minitel, en utilisant une notation simplifiée pour indiquer les positions des pièces sur le plateau. Ainsi, les joueurs peuvent entrer leurs mouvements de manière intuitive, malgré les limitations du clavier du Minitel. Nous avons également implémenté des messages d'erreur à l'écran pour guider les joueurs tout au long de la partie (quand un coup est invalide par exemple). 

L'affichage des pièces et du plateau a été optimisé pour s'adapter aux contraintes colorimétriques du Minitel. En effet, le Minitel ne peut afficher que 8 couleurs différentes, nous avons donc choisi des représentations de pièces qui restent distinctes malgré cette limitation. Les cases du plateau sont également colorées de manière à maximiser le contraste entre les différentes pièces. De plus, les pièces sont affichées dans deux sens différents selon le joueur auquel elles appartiennent, afin de faciliter la reconnaissance des pièces pour chaque joueur. Ainsi, les pièces des joueurs 1 et 3 sont affichées verticalement, tandis que celles des joueurs 0 et 2 sont affichées horizontalement. Cela permet de n'avoir besoin que de 2 "couleurs" différentes pour représenter les pièces, tout en assurant une bonne lisibilité pour chaque joueur.

![Interface sur le Minitel](images/image_plateau_minitel.jpg)

Les couleurs mentionnées plus hauts pour les pièces sont simplement les pièces blanches et noires classiques des échecs, mais adaptées aux contraintes du Minitel. Pour ce faire, il a en fait fallu afficher les pièces blanches en deux teintes différentes, si la pièce blanche est sur une case blanche elle est plus foncée que si elle est sur une case noire, et inversement pour les pièces noires. Cela permet de garder un bon contraste entre les pièces et le plateau, malgré les limitations du Minitel. Ceci est visible sur l'image ci-dessus où l'on peut voir que les pièces blanches sur les cases blanches sont plus foncées que celles sur les cases noires.

#### 4.2.3 Développement, compilation et logique de jeu

Le développement de l'application a été réalisé en utilisant un environnement de développement compatible avec RIOT-OS et les cartes wyres. La compilation du code se fait via des commandes Makefile, facilitant le processus de construction et de déploiement sur les cartes.

Le jeu a été testé principalement avec un seul Minitel connecté à une carte wyres, mais le code est conçu pour être extensible à quatre Minitels distincts, chacun avec sa propre carte wyres et son module LoRa. Cela permet de jouer une partie complète d'échecs à quatre joueurs en réseau, en utilisant la communication LoRa pour synchroniser l'état du jeu entre les différents nœuds.

Le code source du jeu d'échec est codé en C++ et respècte les règles des échecs à quatre joueurs. Un coup spécial n'est pas cependant pas implémenté, il s'agit du roque. Chaque pièce est représentée par une classe dédiée, héritant d'une classe abstraite Piece. La logique du jeu est gérée par une classe Game, qui maintient l'état global du jeu et gère les tours de jeu. Le plateau est représenté par une classe Plateau, qui gère l'affichage sur le Minitel et la représentation interne du plateau. Les entrées utilisateur sont capturées via le clavier du Minitel, et les coups sont validés par la logique de jeu. En vérifiant la validité des coups, le système assure que les joueurs respectent les règles du jeu, et affiche des messages d'erreur en cas de coup invalide.


## 5. Scénario d'utilisation

Quatre amis, dont deux en colocation, souhaitent faire une partie d'échec sur minitel en 1 contre 1 contre 1 contre 1. Ces amis ne se trouvent pas au même endroit mais à chaque endroit il y a un minitel relié à une carte RiotOS avec un module LoRa. Ils lancent l'application sur leur minitel respectif et se connectent à la partie. Chacun peut alors voir l'état du plateau de jeu, les pièces en mouvement, et effectuer ses propres mouvements en utilisant le clavier du minitel. La communication entre les minitels est assurée par les modules LoRa, garantissant que chaque joueur voit les mises à jour en temps réel malgré la distance qui les sépare.

Pour commencer la partie, chaque joueur flash sa carte RiotOS avec le firmware du jeu d'échecs. Une fois l'application lancée, chaque minitel est configuré pour se connecter au réseau LoRa et rejoindre la partie en cours. Les numéros des joueurs jouant sur le minitel doivent être spécifiés au moment du make flash (par défaut les quatre joueurs jouent sur le même minitel mais on peut en mettre de un à quatre sur le même minitel). Par exemple, pour jouer en tant que joueur 1 et 3 sur le même minitel, la commande serait : `make flash JOUEUR=13` (les joueurs vont de 0 à 3).

Ils entament une partie, chaque joueur effectuant ses mouvements à tour de rôle. Le système gère la synchronisation des états du jeu, assurant que tous les joueurs voient les mêmes informations en temps réel.

Pour jouer un coup, un joueur utilise le clavier du minitel pour entrer les coordonnées x et y de la pièce qu'il souhaite déplacer, suivies des coordonnées x et y de la case de destination. Par exemple, pour déplacer une pièce de la case (12, 6) à la case (10, 6), le joueur entrerait "12 06 10 06" sur le clavier du minitel. Le système valide le coup en fonction des règles des échecs à quatre joueurs et met à jour l'état du jeu en conséquence. Si le coup est invalide, un message d'erreur est affiché, et le joueur doit réessayer. Si le coup est valide, l'état du plateau est mis à jour et la nouvelle position des pièces est affichée sur tous les minitels. La coordnnée x correspond à la colonne (de 0 à 13) et la coordonnée y à la ligne (de 0 à 13). Pour voir quel joueur doit jouer, un joueur peut regarder l'affichage `current player` qui indique le numéro du joueur censé jouer, un point apparaît également à côté de son score dans l'angle du plateau qui lui est associé. Le joueur 0 est le joueur sur la droite de l'écran, le joueur 1 est en bas, le joueur 2 est à gauche et le joueur 3 en haut.

À la fin de la partie, le classement est affiché sur chaque minitel. Avec la proposition de rejouer une nouvelle partie.

## 6. Budget approximatif

Main d’oeuvre = (7 * **3 h de cours** + 6 * **3h de jeudi aprem**) * 3 personnes
              + **~24h de dev du jeux** 
              + **~6h de lecture doc et implémentation affichage** 
              + **~12h de lecture doc plus implémentation LoRa** 
              = **159h**

Matériel = **1 à 4 Minitel** (~50€ l’unité) 
         + **1 à 4 wyres-base** (~10 € l’unité) 
         + **1 à 4 STLink** (~10€ l’unité) 
         + **les petites connectiques** (5€) 
         + **1 à 4 cartes de connexion Wyres/Minitel et connecteur DIN** (~15€ l’unité) 
         = 200 + 40 + 5 + 40 + ~60 = **345 €**

## 7. Bilan du projet

Nous avons rencontré plusieurs défis techniques au cours de ce projet, notamment la gestion des limitations du Minitel en termes d'affichage et de saisie, ainsi que la mise en place d'une communication fiable via LoRa. Le développement du protocole de communication reste à améliorer pour gérer les pertes de paquets et les corruptions. Nous avons cependant une implémentation de jeu d'échec à quatre joueurs fonctionnelle, avec une interface utilisateur bien adaptée au Minitel. Les coups sont bien envoyés entre les Minitels (mis à part les corruptions qui nous avons pu observer) et le plateau est mis à jour en temps réel.

Nous avons également quelques ajouts majeurs par rapport au cahier des charges initial. Prémièrement, la possibilité de jouer à plusieurs joueurs sur le même Minitel, ce qui n'était pas prévu au départ. Deuxièmement, la possibilité de jouer une partie pré-enregistrée sur un unique Minitel, ce qui nous permet de voir l'affichage du plateau sur une partie complète sans avoir besoin de la jouer nous mêmes.

## 8. Idées d'améliorations

- Mettre un bot contre qui on peut jouer
- Pouvoir avoir plusieurs types d'interface homme - machine
- Pouvoir se connecter depuis n’importe quelle plateforme
- Connecter une autre forme d’input au lieu du clavier
- Ajouter le coup spécial non implémenté (roque)
- Améliorer le protocole de communication pour gérer les pertes de paquets et les corruptions