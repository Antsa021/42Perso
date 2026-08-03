/*
SUJET : max
Retourne le plus grand nombre d'un tableau d'int. Si le tableau est
vide, retourne 0.
int	max(int* tab, unsigned int len);
*/

int	max(int* tab, unsigned int len)
// tab : tableau (en C, un tableau passé en paramètre "dégénère" en
// pointeur vers son premier élément).
// len : nombre d'éléments du tableau (unsigned car une taille ne
// peut pas être négative).
{
	if (len == 0)
		return (0);
	// Cas particulier explicite demandé par le sujet : tableau vide.
	int res = tab[0];
	// On initialise le résultat avec le PREMIER élément du tableau
	// (pas avec 0 ou une valeur arbitraire, sinon on risquerait de
	// rater le vrai maximum si tous les éléments étaient négatifs).
	for (unsigned int i = 0; i < len; i += 1)
	// Boucle for classique : i va de 0 à len-1 inclus.
	{
		if (res < tab[i])
			res = tab[i];
		// Si l'élément courant est plus grand que le max trouvé
		// jusqu'ici, on met à jour res.
	}
	return (res);
}

/*
POINT CLÉ : "initialiser le max avec le premier élément du tableau"
(et pas avec 0 ou INT_MIN) est le réflexe à avoir sur TOUT algo de
recherche de max/min sur un tableau qui peut contenir des valeurs
négatives.
*/
