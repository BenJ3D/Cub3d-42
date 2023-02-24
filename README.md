<h1 align=center>Cub3D 42</h1>

<p align="center">
<img src="https://user-images.githubusercontent.com/49345674/221225597-bedfe442-84b4-430b-98ea-a326213a863a.gif" />
</p>

Le projet Cub3D est un projet en duo à réaliser à l'école 42, dans lequel les étudiants doivent développer un moteur de jeu en utilisant les techniques de parsing et de lancer de rayons.

Le parsing consiste à lire un fichier de configuration pour extraire les informations nécessaires au jeu, telles que la map du jeu, les liens vers les images à utiliser, ainsi que les couleurs du ciel et du sol.

Le lancer de rayons, également appelé raycasting, est une technique de rendu 3D qui simule le comportement de la lumière dans l'environnement du jeu. Pour chaque pixel de l'écran, on tire un rayon depuis la caméra du joueur et on cherche les murs qui sont traversés par le rayon. En utilisant la distance entre la caméra et le mur, on peut dessiner en 3D la map par rapport à la distance des rayons.

Le moteur de jeu est implémenté en utilisant la librairie graphique miniLibX pour l'affichage des images et la gestion des événements clavier.

L'objectif du projet est de créer un jeu fonctionnel, offrant une expérience immersive en temps réel tout en respectant les normes de programmation modulaire et la norme de codage de l'école 42.

<h4>Bonus</h4>
En plus des fonctionnalités de base, plusieurs bonus ont été implémentés pour améliorer l'expérience utilisateur, notamment les collisions, la minimap, les portes, l'animation sur les murs, le réglage de la focale et la prise en charge du mouvement souris.

<h4>Utilisation</h4>
Pour compiler et lancer le projet, il suffit d'exécuter les commandes suivantes :

```
make
./cub3d maps/map.cub
```

pour les bonus :

```
make bonus
./cub3d_bonus maps/map_bonus.cub
```
