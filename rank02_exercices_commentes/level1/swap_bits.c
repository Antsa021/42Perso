/*
SUJET : swap_bits
Échange les deux moitiés (4 bits + 4 bits, appelés "nibbles") d'un
octet et retourne le résultat.
unsigned char	swap_bits(unsigned char octet);
Ex : 0100 0001 devient 0001 0100
*/

#include <unistd.h>

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
	// octet >> 4 : décale tout l'octet de 4 bits vers la DROITE.
	// Ça envoie les 4 bits de POIDS FORT (la moitié gauche) vers
	// la moitié droite, en perdant les bits originaux de droite
	// (remplacés par des 0 en tête).
	// octet << 4 : décale de 4 bits vers la GAUCHE. Ça envoie les
	// 4 bits de poids FAIBLE (moitié droite) vers la moitié gauche.
	// | (OR bit à bit) : combine les deux résultats. Comme chaque
	// décalage a "vidé" l'autre moitié avec des zéros, le OR permet
	// de fusionner proprement les deux moitiés échangées sans
	// qu'elles se marchent dessus.
	// Note : en toute rigueur, octet << 4 devrait être casté en
	// unsigned char pour éviter une promotion implicite en int,
	// mais le résultat final reste correct ici car on retourne un
	// unsigned char (les bits en trop sont tronqués à la conversion).
}

/*
POINT CLÉ : ce genre de manipulation "décaler + OR pour fusionner"
est une technique bit à bit très efficace (pas besoin de boucle !),
à comparer avec reverse_bits qui elle a besoin d'une boucle car
l'ordre des 8 bits change individuellement (pas juste 2 blocs de 4).
*/
