/*
SUJET : ft_list_remove_if
Retire d'une liste chaînée tout élément dont la data est "égale" à
une donnée de référence (selon une fonction de comparaison fournie).
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
cmp prend deux void* et retourne 0 si les deux sont égaux.
Fonctions autorisées : free
*/

#include <stdlib.h>
#include "ft_list.h"

int cmp(void *a, void *b);
// Prototype de la fonction de comparaison (fournie par l'appelant,
// pas définie ici -- juste annoncée pour que le compilateur
// connaisse sa signature).

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *))
// "t_list **begin_list" : POINTEUR VERS UN POINTEUR. C'est
// nécessaire ici car la fonction doit pouvoir MODIFIER begin_list
// lui-même (par exemple si c'est le TOUT PREMIER élément de la liste
// qu'il faut supprimer -- il faut alors changer À QUI begin_list
// pointe, ce qui exige un double niveau d'indirection).
{
	if (begin_list == NULL || *begin_list == NULL)
		return;
	// Deux vérifications de sécurité : begin_list lui-même ne doit
	// pas être NULL (pointeur invalide), et *begin_list (la liste
	// qu'il désigne) ne doit pas non plus être vide -- rien à
	// supprimer dans ce cas.

	t_list *cur = *begin_list;
	// cur : le maillon COURANT qu'on examine (première fois : le
	// tout premier élément de la liste).

	if (cmp(cur->data, data_ref) == 0)
	// Si cmp retourne 0, ça veut dire "les deux données sont
	// égales" (convention imposée par le sujet).
	{
		*begin_list = cur->next;
		// On fait "sauter" le maillon courant : la liste pointe
		// maintenant directement sur le maillon SUIVANT. C'est ici
		// que le double pointeur est indispensable : on modifie
		// VRAIMENT begin_list (via *begin_list), pas juste une
		// copie locale.
		free(cur);
		// On libère la mémoire du maillon supprimé (évite une fuite
		// mémoire).
		ft_list_remove_if(begin_list, data_ref, cmp);
		// RÉCURSION sur la MÊME position (begin_list), car après
		// suppression, il faut re-tester le NOUVEAU premier élément
		// (qui pourrait, lui aussi, correspondre au critère de
		// suppression).
	}
	else
		ft_list_remove_if(&cur->next, data_ref, cmp);
	// Si le maillon courant ne correspond pas, on avance : on
	// rappelle la fonction sur "&cur->next" (l'ADRESSE du pointeur
	// next du maillon courant), ce qui permet à l'appel récursif
	// suivant de, lui aussi, pouvoir MODIFIER ce lien si besoin
	// (même truc de double pointeur, mais appliqué au maillon
	// suivant plutôt qu'au tout début de la liste).
}

/*
POINT CLÉ : l'usage d'un DOUBLE POINTEUR (t_list **) pour manipuler
une liste chaînée est une technique avancée mais essentielle -- elle
évite d'avoir à écrire un cas spécial pour "si c'est le premier
élément qu'il faut supprimer" (souvent source de bugs dans les
implémentations naïves de listes chaînées).
*/
