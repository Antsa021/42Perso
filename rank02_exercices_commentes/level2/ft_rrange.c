/*
SUJET : ft_rrange
Comme ft_range, mais dans l'ordre INVERSE : de end à start.
int	*ft_rrange(int start, int end);
Ex: (1,3) -> [3,2,1]. (0,-3) -> [-3,-2,-1,0].
Fonctions autorisées : malloc
*/

#include <stdlib.h>

int		absolute_value(int n);
// DÉCLARATION anticipée (prototype) sans définition ici -- le
// compilateur sait juste que cette fonction EXISTE quelque part
// (probablement dans un autre fichier fourni par le testeur), donc
// il peut compiler ft_rrange sans connaître son contenu exact.

int		*ft_rrange(int start, int end)
{
	int number_of_ints;
	int *array;
	int step;
	// step : de combien on avance à CHAQUE tour (+1 ou -1), permet
	// une seule boucle au lieu de deux (contrairement à ft_range).
	int i;

	number_of_ints = 1 + absolute_value(end - start);
	array = malloc(sizeof(int) * number_of_ints);
	// ATTENTION : ici, contrairement à ft_range, il n'y a pas de
	// vérification "if (!array) return NULL" après le malloc --
	// un oubli à corriger si tu dois rendre un code robuste à
	// l'exam (toujours vérifier le retour de malloc !).

	if (start > end)
		step = 1;
	// Si start > end, on va afficher de end vers start EN
	// AUGMENTANT (ex: start=3,end=1 -> on part de 1, on monte
	// jusqu'à 3, résultat [3,2,1] car on REMPLIT à l'envers, voir
	// la boucle plus bas).
	else
		step = -1;
	// Sinon, on avance en DIMINUANT.

	i = 0;
	while (i < number_of_ints)
	{
		array[i] = end;
		// On remplit le tableau en partant de "end" (pas "start" !)
		// -- c'est ÇA qui inverse l'ordre par rapport à ft_range.
		end = end + step;
		++i;
	}
	return (array);
}

/*
POINT CLÉ : la variable "step" (+1 ou -1 selon le sens) permet de
n'écrire QU'UNE SEULE boucle qui marche dans les deux directions
(croissant ou décroissant), contrairement à ft_range qui duplique
la logique en deux blocs if/else. C'est une technique plus concise et
élégante à retenir. Attention cependant au malloc non vérifié ici --
bug à corriger si on te le demande à l'exam.
*/
