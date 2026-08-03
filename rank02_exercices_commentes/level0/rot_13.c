/*
SUJET : rot_13
Affiche une string en remplaçant chaque lettre par celle 13 positions
plus loin dans l'alphabet ('z' -> 'm', 'Z' -> 'M'). Casse inchangée.
Si nombre d'arguments != 1, afficher juste '\n'.
Fonctions autorisées : write
*/

#include <unistd.h>

int main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while(av[1][i] != '\0')
		{
			if ((av[1][i] >= 'a' && av[1][i]<= 'm') || (av[1][i] >= 'A' && av[1][i]<= 'M'))
				av[1][i] = av[1][i] + 13;
			// Pour les lettres de la PREMIÈRE moitié de
			// l'alphabet (a-m ou A-M), on avance de 13 : on
			// reste dans la table ASCII (a=97..m=109, +13
			// donne 110..122 = n..z, toujours des lettres).
			else if ((av[1][i] >= 'n' && av[1][i]<= 'z') || (av[1][i] >= 'N' && av[1][i]<= 'Z'))
				av[1][i] = av[1][i] - 13;
			// Pour la SECONDE moitié (n-z ou N-Z), on RECULE de
			// 13 au lieu d'avancer, car +13 nous ferait sortir
			// de la plage des lettres (dépasserait 'z'/'Z').
			// n(110)-13=97='a', z(122)-13=109='m'. C'est ce qui
			// crée l'effet "miroir" caractéristique de ROT13
			// (appliquer ROT13 deux fois redonne le texte
			// original !).
			write(1, &av[1][i], 1);
			// On écrit le caractère MODIFIÉ (ou inchangé s'il
			// n'est pas une lettre, ex: espace, ponctuation).
			i++;
		}
	}
	write(1, "\n", 1);	
}

/*
ATTENTION (bug potentiel à noter pour l'exam) : la fonction main() ne
fait pas de "return" explicite ici. En C, l'absence de return dans
main() est tolérée par certains compilateurs (la valeur de retour
est alors indéfinie), mais à l'exam 42, avec -Wall -Wextra -Werror,
ça peut lever un warning/erreur de compilation. Ajoute toujours
"return (0);" à la fin de ton main par sécurité.
*/
