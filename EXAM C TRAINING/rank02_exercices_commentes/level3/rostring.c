/*
SUJET : rostring
Affiche une string après rotation d'UN MOT vers la gauche : le
premier mot devient le dernier, les autres gardent leur ordre.
Mots séparés par un seul espace en sortie. Si aucun argument, '\n'.
Fonctions autorisées : write, malloc, free
*/

#include <unistd.h>

int		skip_whitespace(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t')
		++i;
	return (i);
}

int		ft_wordlen(char *str)
{
	int i = 0;

	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
		++i;
	return (i);
}
// Ces deux fonctions sont identiques à celles de epur_str -- réflexe
// utile : reconnaître les briques de base déjà rencontrées ailleurs
// dans le rank02 pour aller plus vite à l'exam.

int		print_word(char *str, int i, int *is_first)
// Affiche UN mot à partir de la position i, avec un espace devant
// SAUF si c'est le premier mot affiché (via le pointeur is_first,
// modifié pour que l'appelant garde la trace de cet état entre
// plusieurs appels successifs).
{
	int word_len;

	i = skip_whitespace(str, i);
	word_len = ft_wordlen(str + i);
	if (*is_first == 0)
		write(1, " ", 1);
	write(1, str + i, word_len);
	*is_first = 0;
	// "*is_first = 0" : on déréférence le pointeur pour MODIFIER la
	// variable de l'APPELANT (pas une copie locale) -- indispensable
	// puisque cette fonction est appelée PLUSIEURS FOIS de suite et
	// doit "se souvenir" qu'on n'est plus au premier mot.
	return (i + word_len);
	// On retourne la nouvelle position (après le mot affiché), pour
	// que l'appelant sache où reprendre la lecture.
}

int		epur_str(char *str)
// Affiche TOUS les mots de str (sauf le tout premier, qui est géré
// séparément dans main -- voir plus bas) avec un espace entre eux.
{
	int i = 0;
	int is_first = 1;

	i = skip_whitespace(str, i);
	while (str[i] != '\0')
	{
		i = print_word(str, i, &is_first);
		// "&is_first" : on passe l'ADRESSE de la variable locale,
		// pour que print_word puisse la modifier directement.
		i = skip_whitespace(str, i);
	}
	return (is_first);
	// Retourne 1 si AUCUN mot n'a été affiché (chaîne vide/espaces
	// seulement), 0 sinon -- utile pour savoir, dans main, si un
	// espace séparateur doit être ajouté avant le premier mot repris
	// à la fin.
}

int		main(int argc, char **argv)
{
	if (argc >= 2)
	// Note : "argc >= 2" et pas "== 2" ici -- ce sujet accepte
	// implicitement le premier argument même s'il y en a d'autres
	// après (rare mais à noter, contrairement à la plupart des
	// autres exos qui exigent EXACTEMENT 1 argument).
	{
		char *str = argv[1];
		int i = 0;
		int is_first;

		i = skip_whitespace(str, i);
		i = i + ft_wordlen(str + i);
		// On avance i pour "sauter" ENTIÈREMENT le premier mot
		// (celui qu'on va afficher EN DERNIER, à la toute fin).
		is_first = epur_str(str + i);
		// On affiche TOUS les mots restants (2e mot, 3e mot...)
		// à partir de str + i -- c'est-à-dire APRÈS le premier mot.
		print_word(str, 0, &is_first);
		// Enfin, on affiche le PREMIER mot (position 0 de str),
		// EN DERNIER -- c'est ça qui réalise la "rotation" demandée.
	}
	write(1, "\n", 1);
	return (0);
}

/*
POINT CLÉ : l'astuce ici est de traiter les mots dans un ORDRE
DIFFÉRENT de leur ordre d'apparition dans la string : on affiche
D'ABORD tout ce qui suit le premier mot, PUIS le premier mot en tout
dernier -- c'est exactement la "rotation d'un cran vers la gauche"
demandée par le sujet. Bon combo de révision avec epur_str
(fonctions utilitaires identiques, logique d'assemblage différente).
*/
