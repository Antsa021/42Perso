*This activity has been created as part of the 42 curriculum by <senandri>.*

# Get Next Line

## Description

`get_next_line` est une fonction qui lit une ligne à la fois depuis un file
descriptor. Appelée en boucle, elle permet de parcourir l'intégralité d'un
fichier (ou de l'entrée standard) ligne par ligne, sans jamais charger tout le
contenu en mémoire d'un coup.

```c
char	*get_next_line(int fd);
```

À chaque appel, la fonction renvoie la prochaine ligne du fichier pointé par
`fd`, retour à la ligne (`\n`) inclus. Lorsqu'il n'y a plus rien à lire, ou en
cas d'erreur, elle renvoie `NULL`. La dernière ligne d'un fichier qui ne se
termine pas par `\n` est renvoyée sans `\n`.

L'intérêt principal du projet est la découverte des **variables statiques** :
la fonction doit se souvenir, entre deux appels, des caractères déjà lus mais
pas encore renvoyés.

## Instructions

Le projet contient les fichiers suivants, tous à la racine du dépôt :

```
.
├── README.md
├── get_next_line.c
├── get_next_line_utils.c
└── get_next_line.h
```

### Compilation

La fonction se compile directement avec `cc`, en définissant la taille du
buffer de lecture via l'option `-D BUFFER_SIZE=n` :

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

Le code compile aussi **sans** le flag `-D BUFFER_SIZE` : une valeur de secours
(42) est définie dans le header. Il fonctionne pour n'importe quelle taille de
buffer (1, 42, 9999...).

### Exemple d'utilisation

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
```

> Important : c'est l'appelant qui doit `free` chaque ligne renvoyée.

## Algorithme

À chaque appel, `get_next_line` enchaîne trois étapes, en s'appuyant sur une
variable statique `stash` (la « réserve ») qui conserve son contenu entre les
appels.

1. **Lire (`read_to_stash`)** — on lit le fichier par tranches de
   `BUFFER_SIZE` octets avec `read`, et on accumule chaque tranche dans le
   `stash`. La lecture s'arrête dès qu'un `\n` apparaît dans le `stash`, ou dès
   que `read` ne renvoie plus rien.
2. **Extraire (`extract_line`)** — on copie le début du `stash`, jusqu'au
   premier `\n` inclus, dans une nouvelle chaîne : c'est la ligne renvoyée.
3. **Mettre à jour (`update_stash`)** — on conserve dans le `stash` uniquement
   ce qui suit ce premier `\n`, prêt pour le prochain appel, et on libère
   l'ancien `stash`.

### Justification des choix

- **Variable statique plutôt que globale.** Les variables globales sont
  interdites par le sujet. La variable statique offre exactement le
  comportement voulu (persistance entre appels) tout en restant locale à la
  fonction. Elle est automatiquement initialisée à `NULL` au premier appel.

- **Lecture incrémentale plutôt que lecture totale.** Le sujet demande de lire
  le moins possible : on s'arrête dès qu'une ligne complète est disponible,
  sans lire tout le fichier à l'avance. Cela permet à la fonction de
  fonctionner sur des flux non bornés (entrée standard) et de rester économe en
  mémoire.

- **Buffer alloué en `BUFFER_SIZE + 1`.** `read` ne place pas de `\0`
  terminateur : le caractère supplémentaire reçoit ce `\0`, posé manuellement à
  la position renvoyée par `read`, afin de pouvoir traiter le buffer comme une
  chaîne valide.

- **Gestion des trois valeurs de retour de `read`.** Une valeur positive
  signifie que des octets ont été lus (on continue) ; `0` signale la fin du
  fichier (on s'arrête) ; `-1` signale une erreur (on libère tout et on renvoie
  `NULL`).

- **Robustesse aux tailles de buffer extrêmes.** Avec `BUFFER_SIZE = 1`, le
  fichier est lu caractère par caractère ; avec une valeur très grande, une
  seule lecture peut suffire. Dans les deux cas, la boucle de lecture et
  l'extraction d'une seule ligne à la fois donnent le même résultat correct. Le
  buffer est alloué sur le tas (`malloc`) plutôt que sur la pile, afin d'éviter
  un dépassement de pile pour les très grandes valeurs de `BUFFER_SIZE`.

- **Gestion mémoire.** Chaque concaténation crée une nouvelle chaîne ; l'ancien
  `stash` est systématiquement libéré pour éviter toute fuite. La ligne
  renvoyée, en revanche, appartient à l'appelant, qui doit la libérer.

## Resources

- `man 2 read` — comportement de `read` et signification de sa valeur de retour.
- `man 3 malloc` / `man 3 free` — allocation et libération de mémoire sur le tas.
- Documentation sur les **variables statiques** en C et leur durée de vie.
- Notions de **file descriptor** et de descripteurs standards (0, 1, 2).

### Peer-to-peer learning

Le peer-to-peer learning a été utilisé de manière importante pendant ce projet.
Les échanges avec d'autres étudiants ont notamment permis de mieux comprendre la
gestion du `stash`, les cas limites liés à `read`, ainsi que la répartition des
responsabilités entre les différentes fonctions.

Un problème de performances et de gestion mémoire est apparu lors de tests avec
des lignes très longues : des concaténations répétées pouvaient entraîner un
temps d'exécution trop élevé. Les discussions avec d'autres étudiants ont aidé
à identifier l'origine du problème, à distinguer les exigences réellement
évaluées par la moulinette des cas de stress supplémentaires, et à conserver une
implémentation cohérente avec les contraintes du sujet.

Ces échanges ont aussi servi à confronter les choix de découpage en fonctions,
vérifier la conformité à la Norme, tester différents `BUFFER_SIZE` et repérer
des erreurs de libération mémoire avant les tests finaux.


### Utilisation de l'IA

Des assistants IA (ChatGPT et Claude) ont été utilisés comme support
pédagogique : compréhension des concepts (variable statique, file descriptors,
comportement de `read`), structuration du code en fonctions courtes conformes à
la Norme, et explication détaillée du fonctionnement ligne par ligne. 