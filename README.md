# Cub3d

**Description :**

Cub3D est un projet inspiré du célèbre jeu **Wolfenstein 3D**.  
Le but est de recreer un moteur de jeu 3D simple utilisant la technique du **raycating**.

---

### **Usage**
```
make
./cub3D <chemin vers la map>
```
Contrôles (par défaut) :

![menu](img/menu.png)

<p align="center">
  <img src="img/screen1.png" alt="screen1" width="49%">
  <img src="img/screen2.png" alt="screen2" width="49%">
</p>

Structure des fichiers
Exemple de fichier .cub
Un fichier .cub doit respecter une structure précise pour définir une carte :

```
NO ./textures/north_wall.png
SO ./textures/south_wall.png
WE ./textures/west_wall.png
EA ./textures/east_wall.png
F 220,100,0
C 225,30,0

111111
100001
102001
100001
111111
```
![settings](img/settings.png)
