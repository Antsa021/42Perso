/*
SUJET : inter
Prend deux strings et affiche, SANS DOUBLONS, les caractères qui
apparaissent dans les DEUX strings, dans l'ordre d'apparition dans
la première. Si nombre d'arguments != 2, afficher '\n'.
Fonctions autorisées : write
*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	// index de parcours de s1 (string 1).
	int k;
	// index de parcours de s2 (string 2).
	int l;
	// index réutilisé pour DEUX vérifications de doublons différentes.
	char *s1;
	char *s2;

	i = 0;
	l = 0;
	if (ac == 3)
	{
		s1 = av[1];
		s2 = av[2];
		while (s1[i] != '\0')
		// Pour chaque caractère de s1...
		{
			k = 0;
			while (s2[k] != '\0')
			// ...on regarde s'il apparaît dans s2.
			{
				if(s1[i] == s2[k])
				{ 
					l = 0;
					while (s1[l] != s1[i])
						l++;
					// PREMIÈRE vérification anti-doublon :
					// on cherche dans s1, à partir du
					// début, la PREMIÈRE occurrence du
					// caractère s1[i]. l va s'arrêter dès
					// qu'il trouve un caractère identique
					// à s1[i] (au minimum à la position i
					// elle-même, si c'est la 1ère fois
					// qu'il apparaît).
					if (l == i)
					// Si l'index de la première occurrence
					// (l) est EXACTEMENT i, ça veut dire
					// que s1[i] est la PREMIÈRE apparition
					// de ce caractère dans s1 (on ne l'a
					// jamais vu avant) -> pas de doublon
					// à gauche.
					{
						l = 0;
						while (s2[l] != s2[k])
							l++;
						// DEUXIÈME vérification : même
						// principe mais côté s2, pour
						// s'assurer qu'on traite bien
						// la PREMIÈRE occurrence de ce
						// caractère dans s2 aussi (évite
						// d'afficher 2 fois le même
						// caractère si s2 le contient
						// plusieurs fois).
						if (l == k)
							write(1, &s1[i], 1);
							// Les deux conditions
							// sont réunies : on
							// affiche le caractère
							// une seule fois.
					}
				}
				k++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}

/*
POINT CLÉ : cet algo est en O(n*m*n) (boucles imbriquées + recherches
de doublons) — pas le plus efficace, mais très pédagogique pour
comprendre comment détecter des doublons "à la main" sans structure
de données auxiliaire (comme un tableau de booléens "déjà vu").
Comparer avec "union" (même famille de problème, logique similaire).
*/
