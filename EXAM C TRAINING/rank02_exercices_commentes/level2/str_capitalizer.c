/*
SUJET : str_capitalizer
Prend une ou plusieurs strings, pour chacune : met en majuscule la
PREMIÈRE lettre de chaque mot, et en minuscule le reste. Affiche le
résultat suivi de '\n'.
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
		// Affiche/saute les espaces tels quels.

		if (*str != '\0')
		{
			if (*str >= 'a' && *str <= 'z')
				*str = *str - ('a' - 'A');
			// La PREMIÈRE lettre rencontrée après les espaces
			// est forcément le DÉBUT d'un mot -> on la met en
			// majuscule si c'est une minuscule.
			write(1, str, 1);
			++str;
		}

		while (*str != '\0' && *str != ' ' && *str != '\t')
		// On traite maintenant TOUT LE RESTE du mot (après la
		// première lettre déjà gérée ci-dessus).
		{
			if (*str >= 'A' && *str <= 'Z')
				*str = *str + ('a' - 'A');
			// Toute lettre majuscule DANS le reste du mot est
			// remise en minuscule (seule la 1ère lettre du mot
			// doit rester en majuscule).
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
			++i;
		}
	}

	return (0);
}

/*
POINT CLÉ : structure en TROIS blocs distincts (espaces / première
lettre / reste du mot) -- plus simple que rstr_capitalizer car on n'a
pas besoin de "regarder en avant" (*(str+1)), la première lettre d'un
mot est toujours facile à repérer (juste après un espace ou le début
de string). Comparer les deux fichiers pour bien voir la différence
de logique entre "capitaliser le début" et "capitaliser la fin" d'un
mot.
*/
