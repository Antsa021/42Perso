/*
SUJET : sort_list
Trie une liste chaînée en utilisant un pointeur de fonction cmp pour
définir l'ordre.
t_list	*sort_list(t_list* lst, int (*cmp)(int, int));
Les doublons doivent être conservés. Retourne le premier élément trié.
*/

#include "ft_list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
// cmp : pointeur de fonction fourni par l'appelant, qui définit le
// CRITÈRE d'ordre (croissant, décroissant, etc.) -- même principe
// que ft_list_foreach, mais ici cmp COMPARE deux données au lieu de
// simplement les traiter une par une.
{
	int	swap;
	t_list	*tmp;
	// tmp : va servir à mémoriser le DÉBUT de la liste, pour pouvoir
	// y revenir après chaque échange.

	tmp = lst;
	while(lst->next != NULL)
	// Tant qu'il reste un élément SUIVANT à comparer (on s'arrête au
	// dernier maillon, qui n'a pas de "next").
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		// cmp compare la donnée du maillon COURANT avec celle du
		// SUIVANT. Convention ici (définie par la fonction cmp
		// fournie par l'appelant, pas visible dans ce fichier) :
		// 0 signifie "il faut échanger ces deux éléments" (ils sont
		// dans le mauvais ordre selon le critère voulu).
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			// On échange les DONNÉES (pas les maillons eux-mêmes)
			// entre les deux positions -- plus simple que de
			// réorganiser les pointeurs next de la liste.
			lst = tmp;
			// Après un échange, on REVIENT AU DÉBUT de la liste
			// (via tmp) pour tout re-comparer depuis le début --
			// même logique "bubble sort naïf" que sort_int_tab
			// (recommencer depuis le début après chaque échange).
		}
		else
			lst = lst->next;
			// Pas d'échange nécessaire : on avance simplement au
			// maillon suivant.
	}
	lst = tmp;
	// À la toute fin, on s'assure de retourner le DÉBUT de la liste
	// (lst pourrait être n'importe où après la dernière itération
	// de la boucle, donc on le réinitialise explicitement avec tmp).
	return (lst);
}

/*
POINT CLÉ : même stratégie "bubble sort naïf avec retour au début
après chaque échange" que sort_int_tab, mais appliquée à une LISTE
CHAÎNÉE plutôt qu'à un tableau -- notez que sur une liste, on échange
les DONNÉES (lst->data) plutôt que les MAILLONS eux-mêmes (ce qui
serait beaucoup plus complexe à cause des pointeurs next à réorganiser).
Comparer les deux fichiers pour bien voir l'adaptation du même
principe entre tableau et liste chaînée.
*/
