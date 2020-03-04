# Le graal de l'intégration
Projet de CSD 2018 réalisé par 3 élèves de 1er année: FLORY Colin, MAUSSION Juliette et RENAULT Jean-Baptiste.

## Pour commencer
Ces différentes instructions vont vous permettre d'obtenir une copie de notre projet sur votre machine. Cette copie pourra être utilisée pour effectuer des test et juger de la qualité de notre travail. 

### Prérequis
Pour faire fonctionner notre projet, votre machine doit être en possesion d'un compilateur C. L'utilsation d'un environnement de développement Unix tel que Linux ou Apple est fortement recommandé.

### Installation
Pour obtenir une version correcte de notre projet sur votre machine vous devrez appliquer ces differentes lignes de commande dans un terminal ouvert à l'emplacement où vous désirez entreposez notre travail:

Vous devez tout d'abord fournir votre adresse mail correspondant à votre compte gitlab:


```
git config --global user.email "email@example.com"

```

Et pour récuperer notre projet:

```
git clone https://gitlab.telecomnancy.univ-lorraine.fr/projetsC/G21.git

```
Git vous demandera ensuite votre addresse email et votre mot de passe correspondant à votre compte gitlab.

### Installation bibliothéque gtk+
Si gtk n'est pas déjà installé sur votre machine linux, il faut : <br />
	-Mettre vos paquets à jour : sudo apt-get update <br />
	-Installer la bibliothèque : sudo apt-get install libgtk2.0-dev <br />
	-Vérifier que le runtime s'est bien installé : sudo apt-get install libgtk2.0-0 <br />
On compile ensuite avec : gcc -c nom_executable.c $(pkg-config --libs --cflags gtk+-2.0) nom_executable (pour avoir un executable)
						  gcc -c nom_executable.c $(pkg-config --libs --cflags gtk+-2.0) -o nom_executable.o (pour avoir un fichier .o)




## Lancement du projet
Pour lancer notre projet, il vous suffit d'écrire : "make" dans votre terminal ouvert au registre src pour que tout les fichiers se compilent. Il vous faudra ensuite écrire ./main pour lancer notre projet.

## Plus en profondeur
Nous vous invitons à lire notre compte-rendu papier. ce dernier vous éclairera sur nos différents choix de programmation en accord avec notre état de l'art ( qui est aussi dans le compte-rendu).

## Auteurs
* **FLORY Colin**
* **MAUSSION juliette** 
* **RENAULT Jean-baptiste**
