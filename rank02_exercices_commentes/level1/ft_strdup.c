/*
SUJET : ft_strdup
Reproduit le comportement de strdup (man strdup).
char    *ft_strdup(char *src);
-> alloue et retourne une COPIE de src.
Fonctions autorisées : malloc
*/

#include <stdlib.h>
#include <stdio.h>

char    *ft_strdup(char *src)
{
	int	i;
	char *dest;
	// dest : pointeur vers le buffer qu'on va allouer nous-mêmes.

	i = 0;
	while (src[i] != '\0')
		i++;
	// Première boucle : on calcule la longueur de src (comme
	// ft_strlen), pour savoir combien de mémoire allouer.

	dest = malloc(sizeof (char) * (i + 1));
	// malloc alloue dynamiquement de la mémoire sur le "tas" (heap),
	// contrairement aux variables classiques qui vivent sur la pile
	// (stack) et disparaissent à la fin de la fonction.
	// sizeof(char) vaut 1 (par définition en C), donc ici ça alloue
	// (i + 1) octets.
	// +1 : IMPORTANT, il faut de la place pour le '\0' final EN PLUS
	// des i caractères de la string (piège très classique : oublier
	// le +1 provoque un dépassement mémoire/heap-overflow).
	if (dest == NULL)
		return (NULL);
	// malloc peut échouer (mémoire insuffisante) et retourner NULL.
	// Il FAUT toujours vérifier ce cas avant d'utiliser dest, sinon
	// on risque un crash (déréférencement de pointeur NULL).
	i = 0;
	// On repart de 0 : cette fois pour COPIER les caractères (le i
	// précédent avait servi juste à mesurer la longueur).
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	// Astuce ici : au lieu d'écrire "dest[i] = '\0';" explicitement,
	// on copie src[i] qui, à la sortie de la boucle, vaut justement
	// '\0' (puisque la boucle s'est arrêtée quand src[i] == '\0').
	// Résultat identique, mais moins lisible qu'un simple
	// "dest[i] = '\0';" — les deux sont corrects.
	return (dest);
}

/*
POINT CLÉ : TOUJOURS vérifier le retour de malloc (NULL possible).
Et ne jamais oublier le "+1" pour le '\0' lors de l'allocation d'une
string. C'est l'erreur n°1 en C sur les exos de manipulation de
strings avec allocation dynamique.
*/
