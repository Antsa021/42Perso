/*
SUJET : pgcd
Prend deux entiers strictement positifs, affiche leur PGCD (plus
grand commun diviseur) suivi de '\n'.
Si arguments != 2, afficher '\n'.
Fonctions autorisées : printf, atoi, malloc, free
*/

#include <stdio.h>
#include <stdlib.h>

void	pgcd(int a, int b)
{
	int n = a;
	// On commence par tester le PLUS GRAND diviseur POSSIBLE de a
	// lui-même (a est forcément un diviseur de a).

	while (n > 0)
	{
		if (a % n == 0 && b % n == 0)
		// Dès qu'on trouve un n qui divise À LA FOIS a et b sans
		// reste, c'est un diviseur commun.
		{
			printf("%d", n);
			return;
			// Comme on teste n en partant du PLUS GRAND possible
			// (a) et en DESCENDANT, le PREMIER diviseur commun
			// trouvé est nécessairement le PLUS GRAND -> pas
			// besoin de continuer, on peut return immédiatement.
		}
		--n;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		pgcd(atoi(argv[1]), atoi(argv[2]));

	printf("\n");
	return (0);
}

/*
POINT CLÉ : cette méthode "brute force décroissante" (tester n de a
jusqu'à 1) fonctionne mais est LENTE pour de grands nombres. La
méthode d'Euclide est BEAUCOUP plus rapide :
  pgcd(a, b) = pgcd(b, a % b), avec pgcd(a, 0) = a.
Exercice de révision recommandé : réécris pgcd avec cet algorithme
récursif (quelques lignes seulement, complexité logarithmique au lieu
de linéaire).
*/
