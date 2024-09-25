# 🧟‍🔬 ft_so_long

## Introduction

Ce projet consiste à développer un jeu en 2D en utilisant la bibliothèque graphique **MiniLibX**. Le jeu, nommé "So Long", a pour but de guider un personnage 🧟‍♂️ à travers une carte, de collecter des objets 🧪 et de parvenir à l'exit 🏁. Ce projet vous permettra de développer des compétences en gestion de fenêtres, manipulation de textures et animation de sprites.

![Gameplay Preview](https://github.com/ftTower/soLong/blob/main/md_asset/ezgif-3-1614a8c958.gif)

---

## 🧟‍♂️ Fonctionnalités Obligatoires (Mandatory)

Le jeu respecte les exigences suivantes :

- **🧠 2D Gameplay** : Le jeu se déroule en vue 2D, soit en vue de dessus, soit en défilement horizontal.
- **🔬 Mouvement du Personnage** : Le joueur peut déplacer le personnage à l’aide des touches `W`, `A`, `S` et `D`.
- **🧱 Obstacles** : Le personnage ne peut pas traverser les murs.
- **🧪 Collection d’Objets** : Le joueur doit récupérer tous les objets présents sur la carte avant d’accéder à la sortie.
- **🚪 Sortie** : Le joueur doit atteindre la sortie pour terminer le niveau.
- **🔢 Comptage des Mouvements** : Le nombre total de mouvements effectués par le joueur est affiché en temps réel.
- **🪟 Gestion de Fenêtre** : La fenêtre du jeu peut être correctement redimensionnée et fermée.
- **🖼️ Chargement d’Images** : Le jeu utilise des images provenant de la bibliothèque **MiniLibX**.
- **🗺️ Parsing de Cartes** : Le jeu peut lire et interpréter des cartes `.ber` définissant la disposition du niveau.
- **✔️ Vérification de la Carte** : Le jeu vérifie que la carte est valide et qu’un chemin vers la sortie existe.

---

## 🧟‍🔬 Fonctionnalités Bonus

Ces fonctionnalités supplémentaires apportent une meilleure expérience utilisateur :

- **💀 Défaite du Joueur** : Le joueur peut perdre si son personnage est touché par un ennemi patrouillant 🧟‍♀️.
- **🎥 Animations de Sprites** : Le jeu utilise des animations pour les personnages et les ennemis.
- **👁️ Affichage du Nombre de Mouvements** : Le nombre total de mouvements est affiché directement dans la fenêtre du jeu.
- **🧩 Autotiling** : Gestion dynamique des textures en fonction de la configuration des tuiles environnantes pour un rendu plus naturel.

![Autotiling Preview](https://github.com/ftTower/soLong/blob/main/md_asset/Capture%20d%E2%80%99%C3%A9cran%202024-09-25%20015825.png)

---

## ⚠️ Chargement et Erreurs

Le jeu propose des messages d'erreur détaillés pour guider l’utilisateur en cas de problème de chargement ou de manipulation des fichiers :

![Erreur Exemple](https://github.com/ftTower/soLong/blob/main/md_asset/Capture%20d%E2%80%99%C3%A9cran%202024-09-25%20020401.png)
![Erreur Exemple](https://github.com/ftTower/soLong/blob/main/md_asset/Capture%20d%E2%80%99%C3%A9cran%202024-09-25%20020152.png)
![Erreur Exemple](https://github.com/ftTower/soLong/blob/main/md_asset/Capture%20d%E2%80%99%C3%A9cran%202024-09-25%20020328.png)
![Erreur Exemple](https://github.com/ftTower/soLong/blob/main/md_asset/Capture%20d%E2%80%99%C3%A9cran%202024-09-25%20020253.png)
![Erreur Exemple](https://github.com/ftTower/soLong/blob/main/md_asset/Capture%20d%E2%80%99%C3%A9cran%202024-09-25%20020228.png)


---

## 🧪 Installation et Utilisation

1. Clonez le dépôt :
   ```bash
   git clone https://github.com/ftTower/soLong.git
   cd so_long
   make minlibx
   make
