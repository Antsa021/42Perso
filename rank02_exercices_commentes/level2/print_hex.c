/*
SUJET : print_hex
Prend un nombre positif en base 10, l'affiche en base 16 (minuscules),
suivi de '\n'.
Si arguments != 1, afficher '\n'.
Fonctions autorisées : write
*/

#include <unistd.h>

int		ft_atoi(char *str)
// Version simplifiée (pas de gestion de signe/espaces, nombre
// toujours positif selon le sujet).
{
	int n = 0;

	while (*str != '\0')
	{
		n = n * 10;
		n = n + *str - '0';
		++str;
	}
	return (n);
}

void	print_hex(int n)
{
	char hex_digits[] = "0123456789abcdef";
	// Tableau (string) qui sert de "table de correspondance" :
	// hex_digits[0]='0', hex_digits[10]='a', hex_digits[15]='f'...
	// Astuce très pratique pour convertir un chiffre 0-15 directement
	// en son caractère hexadécimal correspondant.

	if (n >= 16)
		print_hex(n / 16);
	// RÉCURSION (même principe que ft_putnbr) : on affiche D'ABORD
	// tous les chiffres de poids fort (n / 16), pour respecter
	// l'ordre de lecture naturel (gauche à droite), AVANT d'afficher
	// le chiffre courant de poids faible.
	write(1, &hex_digits[n % 16], 1);
	// n % 16 donne le chiffre hexadécimal courant (0 à 15), utilisé
	// directement comme INDEX dans le tableau hex_digits pour
	// obtenir le bon caractère ('0'-'9' ou 'a'-'f').
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));

	write(1, "\n", 1);
}

/*
POINT CLÉ : même structure récursive que ft_putnbr/add_prime_sum,
mais en base 16 au lieu de 10 : "n / 16" et "n % 16" remplacent
"n / 10" et "n % 10". La table hex_digits[] évite d'avoir à écrire
un if/else pour distinguer les chiffres (0-9) des lettres (a-f).
Comparer avec ft_atoi_base qui fait l'opération INVERSE (texte en
base N -> entier en base 10).
*/
