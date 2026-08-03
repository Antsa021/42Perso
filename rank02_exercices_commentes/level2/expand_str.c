/*
SUJET : expand_str
Affiche une string avec EXACTEMENT trois espaces entre chaque mot,
sans espace/tab au début/fin, suivi de '\n'.
Si arguments != 1, ou pas de mot, afficher '\n'.
Fonctions autorisées : write
*/

#include <unistd.h>

int		word_len(char *str)
{
	int i = 0;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
		++i;
	return (i);
}

void	expand_str(char *str)
{
	int len;
	int first_word = 1;

	while (*str != '\0')
	// Ici on utilise *str (déréférencement direct du pointeur, qui
	// AVANCE au fil de la fonction), contrairement à epur_str qui
	// utilisait un index i séparé -- deux styles équivalents.
	{
		while (*str == ' ' || *str == '\t')
			++str;
		// On avance le pointeur str lui-même pour sauter les
		// espaces (au lieu d'avancer un index i comme dans
		// skip_whitespace de epur_str).
		len = word_len(str);
		if (len > 0 && first_word == 0)
			write(1, "   ", 3);
		// "   " (3 espaces) écrits en UN SEUL appel write -- 3
		// octets. Condition "len > 0" : on ne veut pas afficher le
		// séparateur si on est tombé sur la fin de la string
		// (aucun mot après les espaces qu'on vient de sauter).
		first_word = 0;
		write(1, str, len);
		str = str + len;
		// On avance le pointeur str de "len" positions -- même
		// arithmétique de pointeurs que epur_str (str + i), mais
		// ici on réaffecte directement str au lieu d'utiliser un i.
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		expand_str(argv[1]);

	write(1, "\n", 1);
	return (0);
}

/*
POINT CLÉ : comparer ce fichier avec epur_str.c est un excellent
exercice -- même problème, mais une version manipule un INDEX (i)
sur une string fixe, l'autre déplace directement le POINTEUR (str).
Les deux techniques sont interchangeables, savoir passer de l'une à
l'autre est un bon signe de maîtrise pour l'exam.
*/
