/*
SUJET : ft_strcpy
Reproduire le comportement de strcpy (man strcpy).
char    *ft_strcpy(char *s1, char *s2);
-> copie s2 dans s1, et retourne s1.
*/

#include <unistd.h>

char	*ft_strcpy(char *s1, char *s2)
// s1 : destination (là où on copie)
// s2 : source (ce qu'on copie)
// ATTENTION : c'est l'INVERSE de l'ordre naturel qu'on pourrait
// imaginer ("copier s1 vers s2"), mais c'est bien l'ordre officiel
// de strcpy : dest en premier, source en second. Toujours vérifier
// le sujet/le man, ne jamais deviner l'ordre des paramètres.
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	// On parcourt la source tant qu'on n'a pas atteint sa fin.
	{
		s1[i] = s2[i];
		// On copie le caractère de la source vers la destination,
		// à la même position i.
		i++;
	}
	s1[i] = '\0';
	// IMPORTANT : la boucle s'arrête DÈS QUE s2[i] == '\0', donc ce
	// '\0' n'a jamais été copié dans la boucle elle-même ! Il faut
	// donc l'ajouter manuellement à la fin, sinon s1 ne serait pas
	// une string valide (elle n'aurait pas de terminaison).
	return (s1);
	// strcpy retourne TOUJOURS le pointeur vers la destination
	// (s1), pas la source. C'est une convention utile qui permet
	// de chaîner des appels, ex: printf("%s", ft_strcpy(buf, "x"));
}
