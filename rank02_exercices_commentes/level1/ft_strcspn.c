/*
SUJET : ft_strcspn
Reproduit exactement strcspn (man strcspn).
size_t	ft_strcspn(const char *s, const char *reject);
-> retourne la longueur du préfixe initial de s qui NE CONTIENT
   AUCUN caractère de reject.
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>

size_t  ft_strcspn(const char *s, const char *reject)
// size_t : type entier NON SIGNÉ, utilisé par convention pour
// représenter des tailles/longueurs (toujours >= 0). C'est le type
// de retour standard de fonctions comme strlen, strcspn...
{
	size_t	i;
	// i : position courante dans s.
	size_t	k;
	// k : position courante dans reject (pour la recherche interne).

	i = 0;
	k = 0;
	while (s[i] != '\0')
	// On parcourt s caractère par caractère...
	{
		while (reject[k] != '\0')
		// ...et pour CHAQUE caractère de s, on vérifie s'il
		// apparaît QUELQUE PART dans reject.
		{
			if (reject[k] == s[i])
				return (i);
			// Dès qu'on trouve une correspondance, on retourne
			// IMMÉDIATEMENT i : c'est la longueur du préfixe
			// de s qui ne contenait aucun caractère "interdit".
			k++;
		}
		k = 0;
		// IMPORTANT : on réinitialise k à 0 avant de passer au
		// caractère suivant de s, sinon la boucle interne ne
		// scannerait plus reject depuis le début pour les
		// caractères suivants (bug classique à surveiller).
		i++;
	}
	return (i);
	// Si on a parcouru TOUTE la string s sans jamais trouver de
	// caractère de reject, on retourne la longueur totale de s.
}

/*
POINT CLÉ : structure "boucle imbriquée" typique -> boucle externe
sur s, boucle interne sur reject à CHAQUE itération externe. Ne pas
oublier de réinitialiser l'index interne (k = 0) entre deux passages,
sinon le résultat est faux dès le 2e caractère.
*/
