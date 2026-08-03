/*
SUJET : sort_int_tab
Trie (en place) un tableau d'int en ordre croissant.
void sort_int_tab(int *tab, unsigned int size);
Les doublons doivent être conservés.
*/

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i = 0;
	int	temp;
	// Variable pour l'échange (swap), même principe que ft_swap.

	while (i < (size - 1))
	// On compare toujours tab[i] avec tab[i+1] -> on s'arrête à
	// size-1 pour ne jamais dépasser la fin du tableau (i+1
	// resterait valide jusqu'à i = size-2 inclus).
	{
		if (tab[i] > tab[i + 1])
		// Si deux éléments ADJACENTS sont dans le mauvais ordre...
		{
			temp = tab[i];
			tab[i] = tab[i+ 1];
			tab[i + 1] = temp;
			// ...on les échange (swap classique).
			i = 0;
			// ASTUCE (mais peu efficace) : après CHAQUE échange,
			// on RECOMMENCE depuis le tout début du tableau
			// (i = 0) au lieu de continuer à i+1. Ça garantit
			// la correction de l'algo (une sorte de "bubble sort"
			// très naïf), mais c'est nettement plus lent qu'un
			// tri à bulles classique (qui n'aurait besoin que de
			// revenir en arrière d'un cran, ou continuer d'avancer).
		}
		else
			i++;
	}
}

/*
POINT CLÉ : cet algo fonctionne (c'est une variante très inefficace
du tri à bulles/"bubble sort"), mais sa complexité est mauvaise à
cause du "i = 0" qui relance tout depuis le début à chaque échange.
Bon exercice de révision : réécrire un VRAI tri à bulles optimisé
(deux boucles imbriquées classiques, sans jamais revenir à i=0), ou
même un tri par sélection/insertion pour comparer les approches.
*/
