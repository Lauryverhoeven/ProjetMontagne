# Questions: 
1) jusqu'où avez-vous été ? qu'est-ce que vous avez fait/pas fait ?
On a fini tout ce qui est compté pour le barème et on a fait la classe montagne_pointu (cervin) optionnelle. 

2) avez-vous une version graphique ? Si oui, avec quelle bibliothèque graphique (Qt (quelle version ?), WxWidget, SDL, Glut, autre [précisez]) ?
On a utilisé Qt (version 5.9.5), c'est-à-dire celle sur la VM. 

3) combien d'heures en moyenne par personne par semaine estimez vous avoir passé sur le projet ? (essayez d'être objectif : n'oubliez pas qu'au début vous n'avez peut être pas fait grand chose, comptez sur 14 semaines, c.-à-d. la première semaine incluse, ne comptez pas le cours ni les exercices hors projet, n'oubliez pas de diviser le total par 2 car je veux une estimation moyenne par personne.)
Entre 10h-25h par semaine par personne. 


# Projet

## Compilation et éxecution : 

### Option 1 : 

Telecharger le zip du projet, et l' extraire dans un repertoire tel que `/path/to/folder`.

Se placer dans le repertoire `/path/to/folder/ProjetMontagne`.

Pour compiler le projet, executer les commandes suivantes :

```
qmake 
make 

```

Pour executer l' application, taper la commande suivante :

```
Qt_GL/progICC_gl 

```

### Option 2 : 

Telecharger le zip du projet, et l' extraire dans un repertoire tel que `/path/to/folder`.

Ouvrir le logiciel QTCreator, cliquer sur "Ouvrir Projet" puis trouver le projet. Selectionner le projet. Ouvrir le .pro et configurer le projet.

### Option 3 : 

Ouvrir le logiciel QTCreator, cliquer sur "Nouveau projet", choisir "Importer un projet". Choisir git clone et mettre ce lien pour configurer le projet: https://github.com/Lauryverhoeven/ProjetMontagne.git

## Precisions sur l'affichage : 

Nous avons affiché une montagne/chaine de montagnes (marron) avec de la neige (blanche) dessus lorsque l'altitude est haute. Ceci est entouré par une plaine (verte) et dans le ciel des nuages (gris) se déplacent dans le sens du vent. De la pluie (bleue) s'affiche également sur un cube du sol sous forme de "flaque d'eau" lorsque un certain taux d'humidité est atteint dans la colonne d'air surplombant ce cube. 

### Se deplacer : 
Touches fleches (haut, bas, gauche, droite)

### Effectuer une rotation de la montagne : 
Touches E, Q, A, D, W (zoom in), S (zoom out)

### Mettre l' animation en pause : 
Touche espace 

## Remarques : 

Des valeurs conseillées pour obtenir un résultat pertinent lors de l'execution du programme sont les suivantes :

Dimensions de la boite : 30x30x30 (ne pas excéder 50x50x50 sinon l'affichage devient lent)

Dimensions de chaque cube de la boite : 20x20x20

Vitesse du vent sur les bords : 20 

Lambda : 20.0/29.0

### Dans le cas de l'affichage d'une seule montagne : 

Coordonnées du centre de la montagne : x0 = 15, y0 = 15

Hauteur de la montagne : H = 15

Etalement de la montagne selon les coordonnées x et y : sigma_x = 5, sigma_y = 5

Ces valeurs seront proposées directement lors du démarrage du programme. 

### Dans le cas de l'affichage d'une chaine de montagnes composée de plusieurs montagnes : 
#### Montagne 1 : 
x0 = 15, y0 = 15, H = 18, sigma_x = 5, sigma_y = 10
#### Montagne 2 :
x0 = 2, y0 = 22, H = 12,sigma_x = 12 ,sigma_y = 3
#### Montagne 3 : 
x0 = 20, y0 = 2, H = 15, sigma_x = 8 ,sigma_y = 4

### Dans le cas de l'affichage d'une montagne pointue

Cliquer sur Browse et selectionner le fichier cervin_reduced.dat (ou tout autre fichier qui contient des données compatibles avec l'affichage d'une montagne). 

