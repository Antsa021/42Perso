/*
SUJET : ft_list_foreach
Applique une fonction à CHAQUE élément d'une liste chaînée.
void	ft_list_foreach(t_list *begin_list, void (*f)(void *));
La fonction pointée par f sera utilisée comme : (*f)(list_ptr->data);
*/

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
// "void (*f)(void *)" : f est un POINTEUR DE FONCTION. Ça veut dire
// que f ne contient pas une donnée classique, mais l'ADRESSE d'une
// fonction qui prend un "void *" en paramètre et ne retourne rien
// (void). Ça permet d'appliquer N'IMPORTE QUELLE fonction (fournie
// par l'appelant) à chaque élément, sans que ft_list_foreach ait
// besoin de savoir laquelle à l'avance -- très puissant pour du code
// générique/réutilisable.
{
	t_list *list_ptr;
	// Pointeur "curseur" qu'on va faire avancer dans la liste, SANS
	// jamais modifier begin_list lui-même (qui reste la référence
	// vers le tout premier élément).

	list_ptr = begin_list;
	while (list_ptr)
	// Équivalent de "while (list_ptr != NULL)" -- tant qu'il reste
	// des maillons à traiter.
	{
		(*f)(list_ptr->data);
		// Appel de la fonction pointée par f, avec comme argument
		// la donnée du maillon courant. "(*f)(...)" déréférence le
		// pointeur de fonction pour l'APPELER (note : l'écriture
		// "f(list_ptr->data)" sans le "*" fonctionnerait aussi,
		// les deux syntaxes sont équivalentes en C).
		list_ptr = list_ptr->next;
		// On avance au maillon SUIVANT.
	}
}

/*
POINT CLÉ : les pointeurs de fonction sont un concept clé du C --
ils permettent de passer du "comportement" en paramètre (comme des
callbacks en JavaScript, ou des lambdas). Le motif "while (list_ptr)
{ traiter list_ptr->data; list_ptr = list_ptr->next; }" est LE
parcours de liste chaînée de base, à savoir écrire les yeux fermés.
*/
