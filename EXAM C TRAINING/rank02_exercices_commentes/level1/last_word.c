/*
SUJET : last_word
Affiche le dernier mot d'une string, suivi de '\n'.
Si nombre d'arguments != 1, ou pas de mot, afficher '\n'.
Fonctions autorisées : write
*/

#include <unistd.h>

void	last_word(char *str)
{
	int	j = 0;
	// j : va mémoriser le DÉBUT du dernier mot trouvé jusqu'ici.
	int i = 0;
	// i : parcourt toute la string à la recherche des séparateurs.

	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] >= 33 && str[i + 1] <= 126)
		// Si le caractère courant est un espace, ET que le
		// caractère JUSTE APRÈS est "imprimable" (codes ASCII
		// 33 à 126 = tous les caractères visibles, hors espace(32)
		// et caractères de contrôle), alors on vient de trouver le
		// début d'un NOUVEAU mot.
			j = i + 1;
			// On met à jour j : "le dernier mot commence ICI".
			// Comme on parcourt TOUTE la string, la DERNIÈRE
			// fois que cette condition sera vraie correspondra
			// forcément au début du DERNIER mot.
		i++;
	}
	while (str[j] >= 33 && str[j] <= 126)
	// On affiche maintenant le mot qui commence à la position j,
	// tant qu'on reste sur des caractères imprimables.
	{
		write(1, &str[j], 1);
		j++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}

/*
POINT CLÉ : au lieu de tester "!= ' ' && != '\t'" comme dans d'autres
exos, ce code utilise directement les codes ASCII 33-126 pour définir
"caractère imprimable/visible". C'est une approche différente mais
valable pour définir ce qu'est un "mot". Attention : si j reste à 0
(cas "un seul mot" ou "pas d'espace du tout"), la 2e boucle affichera
quand même correctement toute la string depuis le début.
*/
