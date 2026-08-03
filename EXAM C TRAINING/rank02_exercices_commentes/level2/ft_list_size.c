/*
SUJET : ft_list_size
Retourne le nombre d'éléments d'une liste chaînée.
int	ft_list_size(t_list *begin_list);
Structure imposée :
typedef struct s_list
{
    struct s_list *next;
    void          *data;
} t_list;
*/

#include "ft_list.h"
// On inclut le header qui définit la structure t_list (liste
// chaînée : chaque maillon a un pointeur "next" vers le suivant, et
// une donnée générique "data").

int	ft_list_size(t_list *begin_list)
{
	if (begin_list == 0)
	// begin_list == 0 est équivalent à begin_list == NULL (NULL est
	// littéralement défini comme 0, ou (void*)0). Ici on teste si la
	// liste est VIDE (plus aucun maillon).
		return (0);
	// Cas de base de la récursion : une liste vide a 0 élément.
	else
		return (1 + ft_list_size(begin_list->next));
	// RÉCURSION : la taille de la liste = 1 (pour le maillon
	// courant) + la taille du RESTE de la liste (à partir de
	// begin_list->next).
	// "->" (flèche) : opérateur d'accès à un champ d'une structure
	// À TRAVERS UN POINTEUR. "begin_list->next" est un raccourci
	// pour "(*begin_list).next" (déréférencer le pointeur PUIS
	// accéder au champ next).
}

/*
POINT CLÉ : c'est LA récursion la plus simple sur liste chaînée --
un modèle à connaître par cœur : "cas de base (liste vide -> 0)" +
"cas récursif (1 + taille du reste)". On la retrouve partout dans les
exos sur les listes (ft_list_foreach, ft_list_remove_if...).
*/
