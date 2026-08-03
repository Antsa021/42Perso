/*
SUJET : ft_strcmp
Reproduit le comportement de strcmp (man strcmp).
int    ft_strcmp(char *s1, char *s2);
-> retourne 0 si égales, une valeur < 0 si s1 < s2, > 0 si s1 > s2.
*/

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	// On avance TANT QUE les deux strings ont le même caractère à
	// la position i, ET qu'aucune des deux n'est terminée.
	// La boucle s'arrête donc dès qu'on trouve une différence, OU
	// qu'on atteint la fin d'au moins une des deux strings.
		i++;
	return (s1[i] - s2[i]);
	// Le résultat est la DIFFÉRENCE des codes ASCII des premiers
	// caractères différents (ou des '\0' si une string est un
	// préfixe de l'autre, ex: "abc" vs "abcd").
	// - Si s1[i] == s2[i] (les deux valent '\0', strings identiques)
	//   -> résultat = 0.
	// - Si s1[i] > s2[i] (ex: 'c' > 'b') -> résultat positif.
	// - Si s1[i] < s2[i] -> résultat négatif.
}

/*
POINT CLÉ : strcmp ne retourne PAS forcément -1/0/1, mais bien la
DIFFÉRENCE entre les caractères (qui peut être n'importe quelle
valeur non nulle). Ne jamais faire un test "== -1" ou "== 1" sur le
retour de strcmp, toujours tester par rapport à 0 (<0, >0, ==0).
*/
