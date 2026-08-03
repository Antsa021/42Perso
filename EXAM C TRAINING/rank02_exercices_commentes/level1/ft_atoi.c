/*
SUJET : ft_atoi
Convertit une string en int (réimplémentation de atoi).
int	ft_atoi(const char *str);
Fonctions autorisées : aucune
*/

#include <stdio.h>

int     ft_atoi(const char *str)
// "const char *str" : on promet au compilateur qu'on ne va JAMAIS
// modifier le contenu pointé par str (bonne pratique quand on n'a
// pas besoin de modifier la string reçue).
{
	int	nbr;
	// nbr : le résultat numérique qu'on construit au fur et à mesure.
	int sig;
	// sig : le signe du résultat final (1 ou -1).
	int	i;
	// i : index de parcours de la string.

	nbr = 0;
	sig = 1;
	// Par défaut, on suppose un nombre positif.
	i = 0;
	if (str[0] == '-' || str[0] == '+')
	// atoi tolère un signe explicite au tout début de la string.
	{
		if (str[0] == '-')
			sig = -1;
		// Si le signe est '+', on ne fait rien (sig reste 1) : un
		// "+42" doit donner le même résultat que "42".
		i += 1;
		// On avance l'index pour "sauter" le caractère de signe et
		// commencer la lecture des chiffres juste après.
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	// On continue tant que : le caractère n'est pas '\0' (donc
	// str[i] est "vrai"), ET que c'est bien un chiffre ('0' à '9').
	// Dès qu'on rencontre un caractère non-numérique, on s'arrête
	// (comportement standard de atoi : "42abc" -> 42, on ignore le
	// reste).
		nbr = (nbr * 10) + (str[i++] - '0');
		// Construction du nombre chiffre par chiffre :
		// - nbr * 10 : on "décale" le nombre déjà construit d'un
		//   rang (ex: 4 devient 40 pour accueillir le chiffre
		//   suivant).
		// - str[i++] - '0' : on lit le chiffre ASCII courant, on le
		//   convertit en valeur numérique (ex: '2' - '0' = 2), ET
		//   on incrémente i APRÈS l'avoir utilisé (post-incrément).
		// Ex pour "42" : itération 1 -> nbr = 0*10 + 4 = 4, i passe
		// à 1. Itération 2 -> nbr = 4*10 + 2 = 42, i passe à 2.
	return (nbr * sig);
	// On applique le signe à la toute fin, sur le nombre complet.
}

/*
POINT CLÉ : le pattern "nbr = nbr * 10 + (chiffre)" pour construire un
nombre à partir de ses chiffres ASCII est fondamental — tu le
retrouveras dans ft_atoi_base, print_hex, tab_mult, etc. Pense aussi
à gérer le signe AVANT de lire les chiffres, mais à ne l'appliquer
qu'à la fin.
*/
