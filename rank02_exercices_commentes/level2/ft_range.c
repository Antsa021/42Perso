/*
SUJET : ft_range
Alloue (malloc) et remplit un tableau d'int avec les valeurs
consécutives de start à end INCLUS (dans les deux sens).
int	*ft_range(int start, int end);
Ex: (1,3) -> [1,2,3]. (0,-3) -> [0,-1,-2,-3].
Fonctions autorisées : malloc
*/

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int	size;
	int	*res;
	int	i;

	size = abs((end - start)) + 1;
	// abs() : valeur absolue (fournie par stdlib.h). On calcule le
	// nombre d'éléments nécessaires. Ex: start=1,end=3 -> abs(2)+1=3
	// éléments (1,2,3). start=0,end=-3 -> abs(-3)+1=4 (0,-1,-2,-3).
	res = malloc(size * sizeof(int));
	// sizeof(int) : taille en octets d'un int sur cette machine
	// (généralement 4). On alloue assez de mémoire pour "size"
	// entiers CONTIGUS -> ça crée un vrai tableau dynamique.
	if (!res)
		return (NULL);
	// "!res" est équivalent à "res == NULL" : vérification
	// obligatoire après tout malloc.
	i = 0;
	if (start < end)
	// Cas "range croissant" (ex: 1 à 3).
	{
		while (start <= end)
		{
			res[i] = start;
			start += 1;
			i += 1;
		}
	}
	else
	// Cas "range décroissant ou égal" (ex: 3 à 1, ou 0 à 0).
	{
		while (start >= end)
		{
			res[i] = start;
			start -= 1;
			i += 1;
		}
	}
	return (res);
	// On retourne le pointeur vers le PREMIER élément du tableau
	// alloué -- c'est à l'appelant de faire free(res) plus tard
	// pour éviter une fuite mémoire (malloc sans free correspondant).
}

/*
POINT CLÉ : dès qu'on utilise malloc, il FAUT prévoir un free côté
appelant (pas dans cet exo précis, mais c'est un réflexe à avoir en
tête pour l'exam et en général). Comparer avec ft_rrange qui résout
un problème quasi identique mais avec une SEULE boucle au lieu de
deux (technique plus élégante, voir ce fichier).
*/
