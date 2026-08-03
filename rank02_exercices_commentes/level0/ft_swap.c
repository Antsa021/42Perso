/*
SUJET : ft_swap
Échange le contenu de deux entiers dont les ADRESSES sont passées en
paramètre.
void	ft_swap(int *a, int *b);
*/

#include <unistd.h>
#include <stdio.h>

void    ft_swap(int *a, int *b)
// a et b sont des POINTEURS (des adresses mémoire), pas des valeurs
// directes. C'est indispensable ici : si on prenait des int normaux,
// on ne swaperait que des COPIES locales à la fonction, et les
// variables d'origine de l'appelant ne seraient jamais modifiées.
{
	int	temp;
	// Variable temporaire indispensable : si on faisait juste
	// *a = *b; *b = *a; on écraserait la valeur de *a AVANT de
	// l'avoir sauvegardée, et on perdrait la donnée d'origine.

	temp = *a;
	// *a : on "déréférence" le pointeur a, c'est-à-dire qu'on va
	// lire la VALEUR stockée à l'adresse a. On sauvegarde cette
	// valeur dans temp avant de la perdre.
	*a = *b;
	// On écrit la valeur de b à l'adresse a.
	*b = temp;
	// On écrit l'ancienne valeur de a (sauvegardée dans temp) à
	// l'adresse b. L'échange est terminé.
}

/*
POINT CLÉ : le pattern "pointeur + variable temporaire" est LE
classique du swap en C, à connaître par cœur. On le retrouve dans
tous les algos de tri (sort_int_tab, sort_list...).
*/
