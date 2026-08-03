/*
SUJET : rstr_capitalizer
Prend une ou plusieurs strings, pour chacune : met en MAJUSCULE la
DERNIÈRE lettre de chaque mot, et en minuscule le reste. Affiche le
résultat suivi de '\n' (une seule fois à la fin de tout).
Si aucun argument, afficher '\n'.
Fonctions autorisées : write
*/

#include <unistd.h>

void	str_capitalizer(char *str)
{
	while (*str != '\0')
	{
		while (*str != '\0' && (*str == ' ' || *str == '\t'))
		{
			write(1, str, 1);
			++str;
		}
		// On affiche et saute les espaces/tabs TELS QUELS (ils ne
		// sont pas modifiés, seulement les lettres des mots).

		while (*str != '\0' && *str != ' ' && *str != '\t')
		// On parcourt maintenant un MOT entier, lettre par lettre.
		{
			if (*str >= 'a' && *str <= 'z'
			&& (*(str + 1) == '\0' || *(str + 1) == ' ' || *(str + 1) == '\t'))
				*str = *str - ('a' - 'A');
			// Condition clé : la lettre courante est minuscule
			// ET le caractère JUSTE APRÈS elle (*(str+1)) marque
			// la FIN du mot ('\0', espace ou tab) -> c'est donc
			// la DERNIÈRE lettre du mot -> on la met en
			// majuscule (-32, même astuce ASCII qu'ailleurs,
			// calculée ici via ('a'-'A') plutôt qu'écrite en
			// dur).
			else if (*str >= 'A' && *str <= 'Z' && *(str + 1) != '\0'
			&& *(str + 1) != ' ' && *(str + 1) != '\t')
				*str = *str + ('a' - 'A');
			// Sinon, si c'est une majuscule et qu'elle N'EST PAS
			// la dernière lettre du mot, on la remet en
			// minuscule (toutes les lettres SAUF la dernière
			// doivent être en minuscule).
			write(1, str, 1);
			++str;
		}
	}
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		write(1, "\n", 1);
	else
	{
		int i = 1;
		while (i < argc)
		{
			str_capitalizer(argv[i]);
			// On applique la transformation à CHAQUE argument
			// (argv[1], argv[2]...) l'un après l'autre.
			++i;
		}
	}

	return (0);
}

/*
POINT CLÉ : la technique "*(str + 1)" (regarder le caractère SUIVANT
sans avancer le pointeur principal) permet de savoir si on est sur la
DERNIÈRE lettre d'un mot AVANT de décider comment la transformer --
un "lookahead" (regard vers l'avant) très utile pour ce genre de
règles contextuelles. Comparer avec str_capitalizer.c (level2), qui
capitalise la PREMIÈRE lettre au lieu de la dernière.
*/
