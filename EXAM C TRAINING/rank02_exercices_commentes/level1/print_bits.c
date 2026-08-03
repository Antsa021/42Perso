/*
SUJET : print_bits
Affiche un octet en binaire, SANS newline à la fin.
void	print_bits(unsigned char octet);
Ex : print_bits(2) affiche "00000010"
Fonctions autorisées : write
*/

#include <unistd.h>

void print_bits(unsigned char octet)
// unsigned char : un octet (8 bits), valeurs 0 à 255. "unsigned" est
// important ici car on va faire des opérations de décalage de bits
// (>>), et le comportement diffère entre signed/unsigned char.
{
	int	i = 8;
	// Un octet contient exactement 8 bits -> on va les afficher un
	// par un, du bit de poids FORT (le plus à gauche) vers le bit
	// de poids FAIBLE (le plus à droite).
	unsigned char 	bit;
	// bit va contenir '0' ou '1' (le CARACTÈRE, pas juste 0/1) prêt
	// à être affiché avec write.

	while (i--)
	// i-- : POST-décrémentation. La condition du while utilise la
	// valeur de i AVANT décrémentation (donc 8, "vrai"), puis i
	// diminue. On boucle ainsi pour i = 8,7,6,5,4,3,2,1 (8 tours,
	// mais la valeur UTILISÉE dans le corps de la boucle après
	// décrémentation va de 7 à 0, voir ligne suivante).
	{
		bit = (octet >> i & 1) + '0';
		// octet >> i : décalage à droite de i bits. Ça "pousse" le
		// bit qu'on veut examiner jusqu'à la position 0 (la plus à
		// droite).
		// & 1 : opération ET bit à bit avec 1, qui "isole" UNIQUEMENT
		// le bit de poids faible (les autres bits sont mis à 0).
		// Résultat : 0 ou 1 (valeur numérique).
		// + '0' : conversion en caractère ASCII '0' ou '1' (même
		// astuce que pour afficher des chiffres décimaux).
		write(1, &bit, 1);
		// On affiche ce bit, PUIS on recommence pour le bit suivant
		// (i ayant déjà été décrémenté par le i-- de la condition).
	}
}

/*
POINT CLÉ : le trio ">> (décalage) puis & 1 (isolation) puis + '0'
(conversion en caractère)" est LA méthode standard pour extraire et
afficher un bit précis d'un nombre. Indispensable pour print_bits,
reverse_bits, swap_bits.
*/
