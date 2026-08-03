/*
SUJET : rotone
Affiche une string en remplaçant chaque lettre par la SUIVANTE dans
l'alphabet ('z' -> 'a', 'Z' -> 'A'). Casse inchangée.
Si nombre d'arguments != 1, afficher juste '\n'.
Fonctions autorisées : write
*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i]!= '\0')
		{
			if ((av[1][i] >= 'a' && av[1][i] <= 'y') || (av[1][i] >= 'A' && av[1][i] <= 'Y'))
				av[1][i] = av[1][i] + 1;
			// Pour toutes les lettres SAUF 'z'/'Z' (donc a-y ou
			// A-Y), on avance simplement d'1 dans la table ASCII
			// -> c'est bien la lettre suivante.
			else if (av[1][i] == 'z' || av[1][i] == 'Z')
				av[1][i] = av[1][i] - 25;
			// Cas particulier pour 'z'/'Z' : on ne peut pas faire
			// +1 (ça donnerait '{' qui n'est pas une lettre) donc
			// on "boucle" en revenant à 'a'/'A'. z(122)-25=97='a'
			// Z(90)-25=65='A'. C'est l'équivalent de "+1 modulo
			// 26 lettres", fait manuellement avec -25.
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n",1);
}

/*
POINT CLÉ : même remarque que rot_13 -> pas de "return (0);" explicite
à la fin de main, à corriger pour un code propre/robuste.
Comparer avec alpha_mirror et rot_13 : trois exos qui manipulent
l'alphabet différemment (décalage +1, décalage +13, symétrie), bon
combo à réviser ensemble.
*/
