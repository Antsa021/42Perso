/*
SUJET : add_prime_sum
Prend un entier positif, affiche la somme de tous les nombres premiers
inférieurs ou égaux à lui, suivie d'un '\n'.
Si arguments invalides, afficher 0 puis '\n'.
Fonctions autorisées : write, exit
*/

#include <unistd.h>

int		ft_atoi(char *str)
// Version SIMPLIFIÉE de ft_atoi (pas de gestion du signe -/+ ici,
// car le sujet garantit un entier POSITIF).
{
	int n = 0;

	while (*str >= '0' && *str <= '9')
	// *str : on déréférence le pointeur DIRECTEMENT au lieu d'écrire
	// str[0] — équivalent, mais notation par pointeur.
	{
		n *= 10;
		n += *str - '0';
		// Même construction chiffre par chiffre que ft_atoi.
		++str;
		// ++str (PRÉ-incrément) : on avance le POINTEUR lui-même
		// vers le caractère suivant (au lieu d'incrémenter un index
		// séparé i). Deux façons équivalentes de parcourir une
		// string : avec un index (str[i], i++) ou en déplaçant le
		// pointeur directement (*str, str++).
	}
	return (n);
}

void	ft_putnbr(int n)
// Affiche un entier positif (récursivement) sans printf.
{
	if (n >= 10)
		ft_putnbr(n / 10);
	// RÉCURSION : si n a plusieurs chiffres, on affiche D'ABORD
	// tous les chiffres SAUF le dernier (n / 10), en s'appelant
	// soi-même. Ça permet d'afficher les chiffres de GAUCHE à DROITE
	// (l'ordre naturel), alors qu'on ne peut naturellement extraire
	// que le chiffre de DROITE (n % 10) en premier.
	char c = (n % 10) + '0';
	// Une fois la récursion "redescendue", on affiche le DERNIER
	// chiffre restant (celui de poids faible).
	write(1, &c, 1);
}

int		is_prime(int n)
{
	int i = 2;
	// On teste la divisibilité à partir de 2 (le plus petit facteur
	// premier possible).

	while (i < n)
	{
		if (n % i == 0)
			return (0);
		// Si n est divisible par un nombre entre 2 et n-1 (autre
		// que 1 et lui-même), alors n n'est PAS premier.
		++i;
	}
	return (1);
	// Si on n'a trouvé aucun diviseur, n est premier.
	// Note : cette version ne s'arrête pas à sqrt(n), elle teste
	// jusqu'à n-1 -> correct mais moins optimisé que possible
	// (suffisant pour cet exo).
}

int		add_prime_sum(int n)
{
	int sum = 0;
	int i = 2;

	while (i <= n)
	{
		if (is_prime(i) == 1)
			sum += i;
		// On additionne i à la somme SEULEMENT s'il est premier.
		++i;
	}
	return (sum);
}

int		main(int argc, char **argv)
{
	int n;

	if (argc == 2 && (n = ft_atoi(argv[1])))
	// Astuce (et piège potentiel) : "(n = ft_atoi(argv[1]))" fait
	// DEUX choses en même temps : ASSIGNE le résultat de ft_atoi à
	// n, ET utilise cette valeur comme condition du if (0 = faux,
	// tout le reste = vrai).
	// ATTENTION : si l'utilisateur passe "0" en argument, cette
	// condition sera FAUSSE (car n vaudrait 0), et on tombera dans
	// le else -> affichage de 0 quand même, donc le résultat reste
	// correct dans ce cas précis, mais c'est un raccourci un peu
	// fragile à bien comprendre.
		ft_putnbr(add_prime_sum(n));
	else
		ft_putnbr(0);
	write(1, "\n", 1);
	return (0);
}

/*
POINT CLÉ : le pattern récursif de ft_putnbr (afficher d'abord n/10,
puis le dernier chiffre) est LE classique pour afficher un nombre
sans printf, à connaître par cœur — il revient dans paramsum,
tab_mult, print_hex (avec base 16 au lieu de 10).
*/
