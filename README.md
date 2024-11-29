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

![menu](img/menu.png)

<p align="center">
  <img src="img/screen1.png" alt="screen1" width="49%">
  <img src="img/screen2.png" alt="screen2" width="49%">
</p>

Structure des fichiers  
Un fichier .cub doit respecter une structure précise pour définir une carte :

```
NO ./textures/wall/wall_1.png
SO ./textures/wall/wall_2.png
WE ./textures/wall/wall_3.png
EA ./textures/wall/wall_4.png

FL ./textures/wall/floor_1.png
CE ./textures/wall/blue.png

/* RGB */
F 65,65,65
C 37,30,94

    1111111111111111111111111
    1000000000110000000000001
11111100001D1000000000000111111111
1000000000000000011100001111111111
111111111011000001 10000D000000011
100000000010000001110000100011111
111100011110110111000000100011
111110111110111011101D100000001
1100000011010101100000000000011
1000E0000000000000000000000111
10000000000000001101010000001
11000001110101011111011D10001
11110111 1110101 101111010001
11111111 1111111 111111111111
1111
11
1
```

Contrôles (par défaut) :  

![settings](img/settings.png)
