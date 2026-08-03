/*
SUJET : hidenp
Prend deux strings, affiche "1" si la première est "cachée" dans la
deuxième (chaque caractère de s1 trouvé dans s2, DANS L'ORDRE, pas
forcément consécutifs), sinon "0". Toujours suivi de '\n'.
Si arguments != 2, afficher '\n'.
Fonctions autorisées : write
*/

#include <unistd.h>

void	hidenp(char *probe, char *target)
// probe : la string qu'on cherche à "cacher" (= trouver dedans).
// target : la string dans laquelle on cherche.
{
	while (*probe != '\0')
	// Tant qu'il reste des caractères de probe à trouver...
	{
		while (*probe != *target && *target != '\0')
			++target;
		// On avance target JUSQU'À trouver un caractère identique
		// au caractère courant de probe (ou jusqu'à la fin de
		// target s'il n'y en a pas).
		if (*target == '\0')
		{
			write(1, "0", 1);
			return;
			// Si on a atteint la fin de target SANS trouver le
			// caractère cherché, c'est un échec IMMÉDIAT -> on
			// affiche "0" et on quitte la fonction avec return
			// (pas besoin de continuer à chercher le reste).
		}
		++target;
		// On avance target D'UN CRAN APRÈS avoir trouvé le
		// caractère (pour ne pas réutiliser le même caractère de
		// target deux fois pour deux caractères différents de
		// probe -- important !).
		++probe;
		// On passe au caractère SUIVANT de probe à chercher.
	}
	write(1, "1", 1);
	// Si on est sorti de la boucle normalement (tous les caractères
	// de probe ont été trouvés en ordre), c'est un succès.
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		hidenp(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}

/*
POINT CLÉ : structurellement identique à l'algo de "wdmatch" (level1)
-- c'est le même problème de "sous-séquence" (subsequence), écrit ici
avec des pointeurs qui avancent directement (*probe, *target, ++probe,
++target) au lieu d'index+tableau (comme dans wdmatch). Bon exercice
de comparaison des deux styles.
*/
