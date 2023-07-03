# Pipex

<div align="center">
  <img src="https://media3.giphy.com/media/ZXZuGnK2h8T8rca9XB/giphy.gif?cid=6c09b95234xeocjm1zmhoo71uqdxn1md6ut3crtnvdw9rog9&ep=v1_internal_gif_by_id&rid=giphy.gif&ct=g" alt="GIF d'introduction"width="200px">
</div>
Le projet Pipex consiste à développer une application en ligne de commande qui permet d'émuler le fonctionnement d'un pipeline de commandes en utilisant les redirections de fichiers et les tubes (pipes) en C.
## Objectif

L'objectif du projet Pipex est de recréer le comportement du shell lors de l'exécution d'une commande en pipeline. Cela implique la gestion des redirections de fichiers pour l'entrée et la sortie, ainsi que la création d'un tube (pipe) pour connecter les différentes commandes entre elles.
## Fonctionnement

L'application Pipex prend en entrée une série de commandes à exécuter en pipeline, ainsi que les fichiers d'entrée et de sortie appropriés. Elle crée un tube (pipe) pour connecter les commandes et utilise les redirections de fichiers pour diriger l'entrée et la sortie de chaque commande.
## Utilisation

Pour utiliser l'application Pipex, exécutez le programme en passant les arguments appropriés :

bash

./pipex file1 cmd1 cmd2 file2

    file1 est le fichier d'entrée initial.
    cmd1 est la première commande à exécuter.
    cmd2 est la deuxième commande à exécuter.
    file2 est le fichier de sortie final.

L'application exécutera les commandes cmd1 et cmd2 en utilisant les redirections de fichiers et les tubes (pipes), en prenant file1 comme entrée et en produisant file2 comme sortie.
