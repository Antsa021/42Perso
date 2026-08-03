/*
SUJET : epur_str
Affiche une string avec EXACTEMENT un espace entre les mots, sans
espace/tab au début/fin, suivi de '\n'.
Si arguments != 1, ou pas de mot, afficher '\n'.
Fonctions autorisées : write
*/

#include <unistd.h>

int		skip_whitespace(char *str, int i)
// Fonction utilitaire réutilisable : avance i tant qu'on est sur un
// espace ou une tab, et retourne la nouvelle position.
{
	while (str[i] == ' ' || str[i] == '\t')
		++i;
	return (i);
}

int		ft_wordlen(char *str)
// Retourne la longueur du mot qui commence à str (jusqu'au premier
// espace/tab/'\0' rencontré).
{
	int i = 0;

	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
		++i;
	return (i);
}

void	epur_str(char *str)
{
	int i = 0;
	int first_word = 1;
	// Flag booléen : sert à savoir si on doit afficher un espace
	// AVANT le mot courant (jamais avant le tout premier mot).
	int word_len;

	i = skip_whitespace(str, i);
	// On saute les espaces/tabs éventuels EN TOUT DÉBUT de string.
	while (str[i] != '\0')
	{
		if (first_word == 0)
			write(1, " ", 1);
		// On n'affiche l'espace séparateur QU'À PARTIR du 2e mot
		// (jamais avant le premier, ni après le dernier puisque la
		// boucle s'arrête).
		word_len = ft_wordlen(str + i);
		// "str + i" : ARITHMÉTIQUE DE POINTEURS. str + i pointe
		// vers le i-ème caractère de str -- strictement équivalent
		// à &str[i], mais écrit différemment.
		write(1, str + i, word_len);
		// On écrit directement TOUT le mot en UN SEUL appel à
		// write (word_len octets), au lieu de caractère par
		// caractère -- plus efficace.
		i = i + word_len;
		// On avance i de la longueur du mot qu'on vient d'afficher.
		first_word = 0;
		i = skip_whitespace(str, i);
		// On saute les espaces qui suivent, avant le prochain tour
		// de boucle (ou la fin de la string).
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		epur_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}

/*
POINT CLÉ : les fonctions utilitaires "skip_whitespace" et
"ft_wordlen" sont réutilisées TELLES QUELLES dans rostring (level3),
qui est en fait une variante plus complexe de ce même problème. Bon
combo à réviser ensemble.
Note : write(1, str + i, word_len) illustre qu'on peut écrire
PLUSIEURS octets d'un coup avec write, pas seulement 1 par 1.
*/
