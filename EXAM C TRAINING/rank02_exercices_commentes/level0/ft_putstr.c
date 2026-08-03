/*
SUJET : ft_putstr
Écrire une fonction qui affiche une string sur la sortie standard.
void	ft_putstr(char *str);
Fonctions autorisées : write
*/

#include <unistd.h>

void    ft_putstr(char *str)
// str : pointeur vers le premier caractère de la string à afficher.
{
	int	i;
	// i : index qui parcourt la string caractère par caractère.

	i = 0;
	while (str[i] != '\0')
	// '\0' (caractère nul, valeur 0) marque TOUJOURS la fin d'une
	// string en C. Tant qu'on ne l'a pas rencontré, il reste des
	// caractères à afficher.
	{
		write(1, &str[i], 1);
		// &str[i] : adresse du caractère courant (write veut un
		// pointeur car il travaille sur des buffers/tableaux
		// d'octets, même pour écrire un seul caractère).
		i++;
	}
}

/*
POINT CLÉ : c'est la brique de base réutilisée dans énormément
d'autres exos (wdmatch, union...). Le pattern est toujours le même :
"tant que pas '\0', écrire le caractère, avancer l'index".
*/
