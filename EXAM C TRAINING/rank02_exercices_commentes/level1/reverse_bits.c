/*
SUJET : reverse_bits
Inverse l'ordre des bits d'un octet et retourne le résultat.
unsigned char	reverse_bits(unsigned char octet);
Ex : 0010 0110 devient 0110 0100
*/

unsigned char	reverse_bits(unsigned char octet)
{
	int		i = 8;
	// On va traiter les 8 bits de l'octet un par un.
	unsigned char	res = 0;
	// res : le résultat qu'on construit bit par bit, en partant de 0.

	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		// "res * 2" décale tous les bits de res d'une position vers
		// la GAUCHE (équivalent binaire de "* 10" en décimal, mais
		// en base 2). Ça fait de la place pour accueillir un
		// nouveau bit à droite.
		// "octet % 2" récupère le bit de poids FAIBLE (le plus à
		// droite) de octet actuel : reste de la division par 2
		// donne 0 ou 1.
		// On ajoute ce bit tout à droite de res.
		octet = octet / 2;
		// On "consomme" le bit qu'on vient de traiter en décalant
		// octet vers la DROITE (division entière par 2 = décalage
		// binaire vers la droite).
		i--;
	}
	return (res);
	// Effet global : chaque bit lu depuis la droite de "octet" est
	// replacé successivement à droite de "res", mais comme res est
	// décalé à gauche AVANT chaque ajout, l'ORDRE des bits se
	// retrouve inversé au final.
}

/*
POINT CLÉ : ici on utilise l'arithmétique classique (* 2, % 2, / 2)
plutôt que les opérateurs bit à bit (<<, >>, &) comme dans print_bits
-- mathématiquement c'est rigoureusement équivalent en base 2, mais
bon à savoir reconnaître les deux styles d'écriture pour l'exam.
*/
