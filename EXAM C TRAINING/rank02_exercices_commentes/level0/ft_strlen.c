/*
SUJET : ft_strlen
Retourne la longueur d'une string.
int	ft_strlen(char *str);
*/

int     ft_strlen(char *str)
{
	int		i;
	// i va compter le nombre de caractères AVANT le '\0'.

	i = 0;
	while (str[i] != '\0')
		i++;
	// On avance tant qu'on n'a pas trouvé la fin de la string.
	// Dès qu'on tombe sur '\0', i contient exactement le nombre de
	// caractères parcourus AVANT lui = la longueur de la string.
	return (i);
	// Ex : "abc" -> i=0:'a' i=1:'b' i=2:'c' i=3:'\0' -> stop, i=3.
}

/*
POINT CLÉ : ft_strlen ne compte PAS le '\0' lui-même dans le résultat,
seulement les caractères "utiles" avant.
*/
