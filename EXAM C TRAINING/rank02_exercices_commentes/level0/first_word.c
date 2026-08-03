/*
==========================================================================
SUJET : first_word
==========================================================================
Écrire un programme qui prend une string en argument et affiche son
premier mot, suivi d'un retour à la ligne.

Un mot est une portion de string délimitée par des espaces/tabulations
ou par le début/la fin de la string.

Si le nombre de paramètres n'est pas 1, ou s'il n'y a pas de mot,
afficher juste un retour à la ligne.

Fonctions autorisées : write
==========================================================================
*/

#include <unistd.h>
// On inclut unistd.h car c'est ce header qui déclare la fonction write().
// write() est un appel système (syscall) : il communique directement
// avec le noyau pour écrire des octets bruts vers un file descriptor.

void	ft_putchar(char c)
// On définit notre propre fonction pour afficher UN caractère,
// puisqu'on n'a pas le droit d'utiliser printf (seul write est autorisé).
{
	write(1, &c, 1);
	// write() prend 3 arguments : (fd, buffer, taille)
	// - 1        : le file descriptor de la sortie standard (stdout)
	// - &c       : l'adresse du caractère c (write veut un pointeur,
	//              pas la valeur directement, car c'est prévu pour
	//              écrire des BUFFERS/tableaux d'octets)
	// - 1        : on écrit 1 seul octet (1 seul caractère)
}

int	main(int ac, char **av)
// ac  = argument count  -> nombre d'arguments passés au programme
// av  = argument vector -> tableau de strings (les arguments eux-mêmes)
// (voir notre discussion : ac/av et argc/argv sont juste des noms,
//  strictement équivalents pour le compilateur)
//
// Rappel important : av[0] est TOUJOURS le nom du programme lui-même.
// Donc si tu lances "./first_word bonjour", alors :
//   ac      = 2
//   av[0]   = "./first_word"
//   av[1]   = "bonjour"
{
	int	i;
	// i va servir d'index pour parcourir la string caractère par
	// caractère (comme un curseur qui avance dans av[1]).

	i = 0;
	// On initialise l'index à 0 : on commence au tout début de la string.

	if (ac == 2)
	// On vérifie qu'il y a EXACTEMENT 1 argument fourni par l'utilisateur
	// (2 car av[0] = nom du programme, av[1] = l'argument réel).
	// Si ac != 2 (0, 1, 3 arguments...), on saute tout le bloc et on
	// affiche juste '\n' à la fin -> conforme au sujet
	// ("./first_word a b" -> doit afficher juste un retour à la ligne).
	{
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		// PREMIÈRE BOUCLE : on "mange" les espaces/tabulations en début
		// de string. Tant que le caractère courant est un espace ' '
		// ou une tabulation '\t', on avance l'index i.
		// Objectif : sauter tous les espaces AVANT le premier mot.
		// Ex: "   lorem,ipsum  " -> on avance i jusqu'à tomber sur 'l'.

		while (av[1][i] != '\0' && av[1][i] != ' ' && av[1][i] != '\t')
		// DEUXIÈME BOUCLE : maintenant qu'on est au début du premier mot,
		// on avance tant que le caractère :
		//  - n'est PAS le caractère de fin de string ('\0')
		//  - n'est PAS un espace ' '
		//  - n'est PAS une tabulation '\t'
		// Autrement dit : tant qu'on est encore À L'INTÉRIEUR du mot.
		{
			ft_putchar(av[1][i]);
			// On affiche le caractère courant du mot.
			i++;
			// On avance au caractère suivant.
		}
		// Dès qu'on rencontre un espace, une tab, ou la fin de la
		// string, la boucle s'arrête -> on a fini d'afficher le
		// premier mot en entier.
	}
	// Si ac != 2, on n'entre jamais dans ce bloc : rien n'est affiché
	// ici, on passe directement à la ligne suivante.

	ft_putchar('\n');
	// Dans TOUS les cas (qu'il y ait eu un mot affiché ou non), on
	// termine par un retour à la ligne, comme demandé par le sujet.

	return (0);
	// On retourne 0 au système : convention en C pour dire "le
	// programme s'est terminé normalement, sans erreur".
}

/*
==========================================================================
POINTS CLÉS À RETENIR POUR L'EXAM :
==========================================================================
1. av[0] est toujours le nom du programme -> décale les index de 1.
2. Le pattern "sauter les espaces" puis "lire le mot" est un classique
   à connaître par cœur (on le retrouve dans last_word, ft_split, etc.)
3. write() attend un pointeur (&c), pas une valeur directe.
4. Toujours vérifier ac AVANT d'accéder à av[1], sinon segfault si
   aucun argument n'est passé (accès mémoire invalide).
==========================================================================
*/
