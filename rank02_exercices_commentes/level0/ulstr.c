/*
SUJET : ulstr
Inverse la casse de toutes les lettres d'une string (minuscule <->
majuscule). Les autres caractères sont inchangés.
Si nombre d'arguments != 1, afficher juste '\n'.
Fonctions autorisées : write
*/

#include <unistd.h>

int main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i] != '\0')
		{
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
				av[1][i] = av[1][i] - 32;
			// En ASCII, la différence entre une minuscule et sa
			// majuscule correspondante est TOUJOURS 32 ('a'=97,
			// 'A'=65, 97-65=32). Donc minuscule -> majuscule
			// = -32.
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				av[1][i] = av[1][i] + 32;
			// Et inversement, majuscule -> minuscule = +32.
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}

/*
POINT CLÉ : l'astuce "+32 / -32" pour changer la casse d'une lettre
est LA technique ASCII à connaître par cœur pour l'exam (revient dans
str_capitalizer, rstr_capitalizer, camel_to_snake, snake_to_camel...
qui utilisent d'ailleurs souvent 32 directement, comme ici, plutôt
que de calculer la différence entre 'a' et 'A').
*/
