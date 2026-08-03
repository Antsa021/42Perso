/*
SUJET : rev_wstr
Affiche les MOTS d'une string dans l'ordre inverse (contrairement à
rev_print qui inverse les CARACTÈRES).
Si arguments != 1, afficher '\n'.
Fonctions autorisées : write, malloc, free
*/

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_strlen(char *str)
{
	int i = 0;
	
	while (str[i])
		i++;
	return (i);
}

int main(int ac, char *av[])
{
	char *tmp;
	char *rev;
	int len;

	if (ac == 2)
	{
		tmp = av[1];
		len = ft_strlen(tmp);
		rev = NULL;
		len--;
		// On part du DERNIER index valide de la string (len-1),
		// pour parcourir à rebours.
		while (tmp[len])
		// tmp[len] est "vrai" tant que len n'a pas atteint une
		// position négative dépassant le début -- ATTENTION, cette
		// condition suppose que tmp[len] reste valide même à
		// l'indice -1... en réalité la boucle s'arrête grâce au
		// test "len == 0" plus bas AVANT que len ne devienne
		// négatif (voir la logique du else if plus bas).
		{
			if (tmp[len - 1] == ' ')
			// Si le caractère JUSTE AVANT la position courante
			// est un espace, ça veut dire qu'on est au DÉBUT
			// d'un mot (le mot commence juste après cet espace).
			{
				rev = &tmp[len];
				while (*rev && *rev != ' ')
				{
					ft_putchar(*rev);
					rev++;
				}
				// On affiche le mot ENTIER en avançant vers la
				// DROITE depuis cette position, jusqu'au
				// prochain espace ou fin de string.
				ft_putchar(' ');
				// Espace séparateur après le mot affiché.
			}
			else if (len == 0)
			// Cas particulier : on est arrivé tout au début de la
			// string (plus d'espace avant), c'est donc le TOUT
			// PREMIER mot -- qui doit être traité même s'il n'y a
			// pas d'espace avant lui.
			{
				rev = &tmp[len];
				while (*rev && *rev != ' ')
				{
					ft_putchar(*rev);
					rev++;
				}
				// Même affichage que ci-dessus, mais SANS
				// espace après (c'est le dernier mot affiché,
				// puisqu'on parcourt à l'envers).
			}
			len--;
			// On recule d'une position pour continuer à chercher
			// les débuts de mots précédents.
		}
	}
	ft_putchar('\n');
}

/*
POINT CLÉ : la logique consiste à PARCOURIR LA STRING À L'ENVERS
(depuis la fin) pour repérer les DÉBUTS de mots (précédés d'un espace,
ou en position 0), puis à chaque fois AFFICHER CE MOT EN LISANT VERS
L'AVANT (de gauche à droite) -- une combinaison "parcours arrière pour
repérage + parcours avant pour affichage" à bien comprendre. Le sujet
suppose qu'il n'y a jamais d'espaces multiples ni en début/fin de
string (entrée "propre" garantie), ce qui simplifie beaucoup cet exo.
*/
