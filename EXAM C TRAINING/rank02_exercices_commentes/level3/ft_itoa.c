/*
SUJET : ft_itoa
Convertit un int en string allouée dynamiquement (opération INVERSE
de ft_atoi).
char	*ft_itoa(int nbr);
Fonctions autorisées : malloc
*/

#include <stdlib.h>

int		absolute_value(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int		get_len(int nbr)
// Calcule le nombre de caractères nécessaires pour représenter nbr
// en string (SANS compter le '\0' final).
{
	int len = 0;
	if (nbr <= 0)
		++len;
	// Si nbr <= 0, on prévoit un caractère EN PLUS : soit pour le
	// signe '-' (nombre négatif), soit pour le seul chiffre '0'
	// (car la boucle ci-dessous, "while (nbr != 0)", ne compterait
	// JAMAIS de chiffre si nbr vaut exactement 0 -- piège classique
	// à anticiper !).
	while (nbr != 0)
	{
		++len;
		nbr = nbr / 10;
		// On "consomme" un chiffre à chaque tour (division entière
		// par 10), jusqu'à ce qu'il ne reste plus rien.
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char *result;
	int len;

	len = get_len(nbr);
	result = malloc(sizeof(char) * (len + 1));
	// +1 pour le '\0' final -- toujours penser à cet octet
	// supplémentaire lors d'une allocation de string.
	// ATTENTION : pas de vérification "if (!result) return NULL"
	// ici -- à corriger pour un code robuste (voir remarque en bas).
	result[len] = '\0';
	// On place le '\0' à la fin en premier (avant même de remplir
	// les chiffres), pratique car on va remplir le tableau DE LA FIN
	// VERS LE DÉBUT juste après.

	if (nbr < 0)
		result[0] = '-';
	// Le signe, s'il y en a un, est TOUJOURS en première position.
	else if (nbr == 0)
		result[0] = '0';
	// Cas particulier : nbr == 0 n'entrera jamais dans la boucle
	// suivante (qui teste "nbr != 0"), donc il faut écrire le '0'
	// explicitement ici.

	while (nbr != 0)
	{
		--len;
		// On recule len AVANT de l'utiliser comme index -> on
		// remplit le tableau de DROITE À GAUCHE (dernier chiffre
		// en premier), car c'est le seul ordre dans lequel on peut
		// naturellement extraire les chiffres d'un nombre (via %10).
		result[len] = absolute_value(nbr % 10) + '0';
		// absolute_value() : nécessaire car nbr peut être négatif,
		// et le résultat de "%10" sur un négatif est aussi négatif
		// en C (ex: -42 % 10 = -2, pas 8) -- il faut donc prendre
		// la valeur absolue avant de convertir en caractère.
		nbr = nbr / 10;
	}
	return (result);
}

/*
POINT CLÉ : ft_itoa remplit son tableau de DROITE À GAUCHE (contrairement
à ft_putnbr qui affiche récursivement de GAUCHE à droite), car ici on
a besoin de connaître la longueur totale À L'AVANCE pour allouer le
bon nombre d'octets -- donc on calcule d'abord get_len(), PUIS on
remplit depuis la fin.
ATTENTION : pas de vérification du retour de malloc ici -- à ajouter
si on te demande un code "propre" pour l'exam (if (!result) return NULL;).
*/
