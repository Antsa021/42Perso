/*
SUJET : fprime
Affiche les facteurs premiers d'un entier positif, séparés par '*',
suivi de '\n'.
Si arguments != 1, afficher '\n'.
Fonctions autorisées : printf, atoi
*/

#include <stdio.h>
#include <stdlib.h>

int		is_prime(int n)
{
	int i = 2;

	while (i < n)
	{
		if (n % i == 0)
			return (0);
		++i;
	}
	return (1);
}

void	fprime(char *str)
{
	int n = atoi(str);
	int factor = 2;
	// factor : le diviseur qu'on teste actuellement, en partant du
	// plus petit nombre premier possible.
	int first = 1;
	// first : flag pour savoir si c'est le PREMIER facteur affiché
	// (pas de '*' avant le tout premier).

	if (n == 1)
		printf("1");
	// Cas particulier : 1 n'a pas de facteur premier, mais le sujet
	// veut qu'on affiche "1" quand même dans ce cas.

	while (factor <= n)
	{
		if (n % factor == 0 && is_prime(factor))
		// Si "factor" divise n ET que factor est lui-même premier,
		// alors factor est un FACTEUR PREMIER de n.
		{
			if (first == 1)
				printf("%d", factor);
			else
				printf("*%d", factor);
			// On ajoute le séparateur '*' AVANT chaque facteur
			// SAUF le tout premier.
			first = 0;
			n = n / factor;
			// TRÈS IMPORTANT : on DIVISE n par le facteur trouvé
			// et on continue de tester le MÊME "factor" (le while
			// externe ne change pas factor ici) au prochain tour.
			// Ça permet de gérer les facteurs premiers RÉPÉTÉS
			// (ex: 12 = 2*2*3, on doit trouver le facteur 2 DEUX
			// fois).
		}
		else
			++factor;
		// Si factor ne divise pas n (proprement) ou n'est pas
		// premier, on passe au facteur suivant.
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		fprime(argv[1]);

	printf("\n");
	return (0);
}

/*
POINT CLÉ : l'astuce "diviser n par le facteur trouvé et RETESTER LE
MÊME facteur" (au lieu de toujours avancer factor) est indispensable
pour gérer les facteurs premiers qui apparaissent plusieurs fois (ex:
8 = 2*2*2). Sans cette division progressive de n, l'algo ne
détecterait qu'une seule fois chaque facteur.
*/
