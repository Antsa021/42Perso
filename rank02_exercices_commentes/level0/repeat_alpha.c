/*
SUJET : repeat_alpha
Affiche une string en répétant chaque caractère alphabétique autant
de fois que son index alphabétique. 'a'->'a' (1x), 'b'->'bb' (2x),
'e'->'eeeee' (5x). La casse ne change pas. Si nombre d'arguments != 1,
afficher juste '\n'.
Fonctions autorisées : write
*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int i;
	// index qui parcourt la string donnée en argument.
	int k;
	// compteur de répétitions pour le caractère courant.
	char *str;
	// alias pratique vers av[1], pour ne pas écrire av[1][i] partout.

	i = 0;
	k = 1;
	if (ac ==2)
	// On vérifie qu'il y a exactement 1 argument utilisateur
	// (2 en comptant le nom du programme).
	{
		str = av[1];
		while (str[i] != '\0')
		{
			k = 1;
			// Par défaut, si le caractère n'est PAS une lettre
			// (ex: '.', chiffre, espace...), on l'affiche 1 seule
			// fois -> k=1 réinitialisé à chaque nouveau caractère.
			if (str[i] >= 'A' && str[i] <= 'Z')
				k = str[i] - 64;
			// Astuce ASCII : 'A' vaut 65. Donc 'A' - 64 = 1,
			// 'B' - 64 = 2, ..., 'Z' - 64 = 26.
			// On calcule ainsi directement l'index alphabétique
			// (A=1, B=2...) SANS tableau ni comparaison lettre
			// par lettre.
			if (str[i] >= 'a' && str[i] <= 'z')
				k = str[i] - 96;
			// Même principe : 'a' vaut 97, donc 'a' - 96 = 1,
			// 'b' - 96 = 2, etc.
			while (k >= 1)
			{
				write(1, &str[i], 1);
				// On réaffiche TOUJOURS le MÊME caractère
				// (str[i], celui d'origine, casse comprise),
				// k fois de suite.
				k--;
			}
			i++;
			// Une fois les répétitions faites, on passe au
			// caractère suivant de la string.
		}
	}
	write(1, "\n", 1);
	return (0);
}

/*
POINT CLÉ : l'astuce "caractère - 64" ou "caractère - 96" pour obtenir
l'index alphabétique (1 à 26) est une technique ASCII très utile à
connaître, elle repose sur le fait que les lettres sont consécutives
dans la table ASCII.
*/
