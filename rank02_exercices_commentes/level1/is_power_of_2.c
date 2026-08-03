/*
SUJET : is_power_of_2
Détermine si un nombre est une puissance de 2. Retourne 1 si oui, 0
sinon.
int	is_power_of_2(unsigned int n);
*/

#include <stdio.h>

int         is_power_of_2(unsigned int n)
// unsigned int : entier NON SIGNÉ (toujours >= 0), cohérent car on
// parle de "puissance de 2" qui n'a de sens que pour des positifs.
{
	if (n == 0)
		return (0);
	// 0 n'est JAMAIS une puissance de 2 (2^k est toujours >= 1),
	// cas particulier à traiter en premier pour éviter une boucle
	// infinie ou un comportement incorrect ci-dessous.
	while (n > 1)
	{
		if (n % 2 == 0)
			n = n / 2;
		// Si n est pair, on peut "retirer" un facteur 2 -> on
		// divise par 2 et on continue. Ex: 8 -> 4 -> 2 -> 1.
		else
			return (0);
		// Dès qu'on tombe sur un nombre IMPAIR (autre que 1), ça
		// veut dire qu'on ne peut plus le diviser proprement par
		// 2 -> ce n'est pas une puissance de 2 pure.
		// Ex: 12 -> 6 -> 3 (impair, différent de 1) -> return 0.
	}
	return (1);
	// Si on sort de la boucle normalement, c'est que n a fini par
	// atteindre exactement 1 en ne divisant que par des 2 -> c'était
	// bien une puissance de 2.
}

/*
POINT CLÉ : il existe une astuce bit à bit beaucoup plus rapide :
"return (n != 0 && (n & (n - 1)) == 0);" — une puissance de 2 n'a
qu'UN SEUL bit à 1 en binaire, et n & (n-1) permet de le vérifier
sans boucle. Bon exercice de révision : comprendre pourquoi ça marche
(lié à print_bits et reverse_bits, sur la manipulation binaire).
*/
