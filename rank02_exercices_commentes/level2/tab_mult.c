/*
SUJET : tab_mult
Affiche la table de multiplication d'un nombre (1x9 lignes).
Si aucun argument, afficher '\n'.
Fonctions autorisées : write
*/

// Passed Moulinette 2019.09.02
// (commentaire laissé par l'auteur d'origine -- indique juste que ce
// code a déjà été validé par le testeur automatique de 42 à cette
// date, aucune incidence sur le fonctionnement du programme.)

#include <unistd.h>

int		ft_atoi(char *str)
{
	int n = 0;

	while (*str >= '0' && *str <= '9')
	{
		n = n * 10;
		n = n + *str - '0';
		++str;
	}
	return (n);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);

	char c = (n % 10) + '0';
	write(1, &c, 1);
}
// Encore une fois, ft_atoi et ft_putnbr sont réimplémentées ici --
// chaque exo étant compilé/testé indépendamment, il n'y a pas de
// "bibliothèque partagée" entre les fichiers de l'exam.

void	tab_mult(char *str)
{
	int n;
	int i = 1;

	n = ft_atoi(str);
	while (i <= 9)
	// Boucle de 1 à 9 inclus -> 9 lignes de table de multiplication.
	{
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(n);
		write(1, " = ", 3);
		ft_putnbr(i * n);
		write(1, "\n", 1);
		// Affichage ligne par ligne : "i x n = i*n", chaque
		// morceau (nombre ou texte fixe) affiché séparément avec
		// write, puisqu'on n'a pas printf pour faire ça en une
		// seule instruction formatée.
		++i;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		tab_mult(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}

/*
POINT CLÉ : ce fichier illustre bien comment reconstituer un
affichage "formaté" (comme le ferait printf("%d x %d = %d\n", ...))
à la main avec seulement write() et une fonction d'affichage de
nombre (ft_putnbr) -- pattern qu'on retrouve dans plusieurs exos de
ce rank quand printf n'est pas autorisé.
*/
