# Questions: 
1)jusqu'où avez-vous été ? qu'est-ce que vous avez fait/pas fait ?
On a fini tout ceux qui sont comptés pour la barème et on a fait le classe montagne_pointu (cervin) en tant que optionnel. 

2) avez-vous une version graphique ? Si oui, avec quelle bibliothèque graphique (Qt (quelle version ?), WxWidget, SDL, Glut, autre [précisez]) ?
On a utilisé Qt (version 5.9.5), celui sur VM. 

3) combien d'heures en moyenne par personne par semaine estimez vous avoir passé sur le projet ? (essayez d'être objectif : n'oubliez pas qu'au début vous n'avez peut être pas fait grand chose, comptez sur 14 semaines, c.-à-d. la première semaine incluse, ne comptez pas le cours ni les exercices hors projet, n'oubliez pas de diviser le total par 2 car je veux une estimation moyenne par personne.)
Entre 10h-25h par semaine par personne. 


# ProjetIccPerso

## Compilation et éxecution : 

### Option 1 : 

Telecharger le zip du projet, et l' extraire dans un repertoire tel que `/path/to/folder`.

Se placer dans le repertoire `/path/to/folder/ProjetIccPerso`.

Pour compiler le projet, executer les commandes suivantes :

```
qmake ProjetIccPerso.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug
make clean -j4 in /path/to/folder/build-ProjetIccPerso-Desktop-Debug
```

Pour executer l' application, taper la commande suivante :

```
/path/to/folder/build-ProjetIccPerso-Desktop-Debug/Qt_GL/progICC_gl
```

### Option 2 : 

Telecharger le zip du projet, et l' extraire dans un repertoire tel que `/path/to/folder`.

Ouvrir le logiciel QTCreator, cliquer sur "Nouveau Projet" puis "Importer un projet existant". Selectionner le projet. Aller dans "Ouvrir un projet" et ouvrir le projet qui vient d'être créé. Compiler le projet. 

## Remarques et commentaires : 

Les valeurs conseillées pour obtenir un résultat pertinent lors de l'execution du programme sont les suivantes :
### Dans le cas de l'affichage d'une seule montagne : 

x0 = 15, y0 = 15, H = 15, sigma_x = 5, sigma_y = 5

### Dans le cas de l'affichage d'une chaine de montagnes composée de plusieurs montagnes : 
lambda = 20.0/29.0
#### Montagne 1 : 
x0 = 15, y0 = 15, H = 18, sigma_x = 5, sigma_y = 10
#### Montagne 2 :
x0 = 2, y0 = 22, H = 12,sigma_x = 12 ,sigma y = 3
#### Montagne 3 : 
x0 = 20, y0 = 2, H = 15, sigma_x = 8 ,sigma_y = 4

### NB : 
Nous laissons cependant une option à l'utilisateur pour choisir librement les paramètres de la montagne/chaine de montagnes.
