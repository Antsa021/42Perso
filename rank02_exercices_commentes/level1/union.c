/*
SUJET : union
Prend deux strings et affiche, SANS DOUBLONS, tous les caractères qui
apparaissent dans L'UNE OU L'AUTRE des strings, dans l'ordre
d'apparition en ligne de commande.
Si nombre d'arguments != 2, afficher '\n'.
Fonctions autorisées : write
*/

#include <unistd.h>

int check(int c, char *str, int index)
// Fonction utilitaire : vérifie si le caractère c apparaît DÉJÀ dans
// str AVANT la position index (donc si c'est un doublon).
// c est un "int" ici (pas un char) : convention C classique pour les
// fonctions qui manipulent des caractères un par un (comme getchar).
{
	int i = 0;
	
	while(i < index)
	{
		if (str[i] == c)
			return 0;
		// Trouvé une occurrence antérieure -> c'est un doublon,
		// donc "check" retourne 0 (faux, ce n'est PAS une nouvelle
		// apparition).
		i++;
	}
	return  1;
	// Aucune occurrence antérieure trouvée -> c'est la première
	// apparition de ce caractère -> on retourne 1 (vrai).
}

int main(int argc, char **argv)
{	
	int i = 0;
	// va servir de fin de argv[1] puis de curseur d'écriture global.
	int j = 0;
	// parcourt argv[2] pour le fusionner à la suite de argv[1].
	int k = 0;
	// parcourt le résultat fusionné pour filtrer les doublons.
	
	if (argc == 3)
	{
		while(argv[1][i] != '\0')
		{
			i++;
		}
		// On avance i jusqu'à la fin de argv[1] -> i devient la
		// LONGUEUR de argv[1] (position du '\0').
		while(argv[2][j] != '\0')
		{
			argv[1][i] = argv[2][j];
			// ASTUCE (et un peu risquée) : on écrit les
			// caractères de argv[2] DIRECTEMENT à la suite de
			// argv[1], EN MÉMOIRE, en écrasant l'espace qui
			// suit argv[1] dans le tableau argv. Ça ne provoque
			// pas de crash car av[] est stocké de façon
			// contiguë en mémoire dans ce contexte précis, mais
			// c'est une pratique fragile/non portable à connaître
			// mais À ÉVITER en conditions réelles (dépend de
			// l'implémentation, pas garanti par le C standard).
			i++;
			j++;
		}
		i--;
		// On recule d'1 : i pointait juste après le dernier
		// caractère copié (donc sur ce qui serait un '\0' ou une
		// zone indéfinie), on veut qu'il pointe sur le DERNIER
		// caractère valide.
		while(k <= i)
		{
			if(check(argv[1][k], argv[1], k) == 1) 
			// On vérifie si argv[1][k] est bien la PREMIÈRE
			// apparition de ce caractère dans le buffer fusionné
			// (de 0 à k-1).
				write (1, &argv[1][k], 1); 
			k++;
		}
	}
	write (1, "\n", 1);
}

/*
POINT CLÉ : la fusion "en mémoire brute" de argv[2] à la suite de
argv[1] est une technique à comprendre mais PAS à reproduire telle
quelle à l'exam sans réfléchir — mieux vaut utiliser un buffer local
alloué proprement (malloc) si tu dois fusionner deux strings. Compare
avec "inter" (même famille de logique anti-doublon avec la fonction
check/l==i, mais opération ET au lieu de OU sur les strings).
*/
