# ce répertoire contient les fichiers sources de codes de mon programme pour la résolution des 4 problèmes d'optimisation en utilisant les solveurs proposés
Pour lancer le programme (création de l'exécutable optim), naviguer en utilisant le terminal (sous linux) vers le dossier qui contient les fichiers, puis à l'aide de la commande "make" l'exécutable est créé.
L'interaction avec le programme se fait comme suit : dans le même terminal, vous écrivez./Optim [nom_solveur] [nom_probleme] (Exemple ./Optim S1 P1) après appuyer sur ENTRER et le fichier result.txt est créé contenant ainsi les réulats (fmin et (Xmin,ymin)). Pour évaluer les différents solveurs appliqués aux 4 problèmes il faut respecter certaines consignes. utiliser les raccourcis de solveurs (S1, S2.... S7) et les raccourcis de problèmes (P1, P2... P4).
Les fichiers sources contient des commentaires facilitant ainsi leurs lectures.
# Modélisation informatique
J'ai essayé dans ma solution proposée, de donner une certaine abstraction mathématique et une certaine versatilité aux différents problèmes et soveurs ( autrement dit on peut dans certains cas utiliser les memes codes proposés à d'autres types de problèmes). Cependant, la solution proposée fonctionne que sur les problèmes 1D et 2D ( ici le problème 3D n'était pas évoqué).
# La solution proposée contient 4 fichiers différents : Main.cpp, Solveur.hpp, Solveur.cpp et Makefile:

- Main.cpp : c'est le fichier qui permet l'exécution et la gestion du choix de problèmes et solveurs ainsi que à partir de ce fichier le Makefile génére le fichier exécutable "Optim".
- Solveur.hpp: fichier qui contient toutes les déclarations des classes "Point" et les classes dérivées "P1",..,"P4" et les Solveurs "S1",..., "S7", ainsi que les deux polymorphismes "Solveur" et "Probleme".
- Solveur.cpp : c'est là où il y a tout le travail, un fichier qui définit toutes les méthodes des classes et les fonctions utilisées.
- Makefile: ce fichier permet de générer l'exécutable "Optim".



