/*
SUJET : lcm
Calcule le PPCM (plus petit commun multiple / LCM en anglais) de deux
unsigned int.
unsigned int lcm(unsigned int a, unsigned int b);
*/

unsigned int lcm(unsigned int a, unsigned int b)
{
	unsigned int n;	

	if (a == 0 || b == 0)
		return (0);
	// Cas particulier : le PPCM n'a pas de sens si l'un des deux
	// nombres est 0 (aucun multiple commun non-nul).
	if (a > b)
		n = a;
	else
		n = b;
	// On initialise n avec le PLUS GRAND des deux nombres : c'est
	// LE candidat minimum possible pour un multiple commun (aucun
	// nombre plus petit que max(a,b) ne peut être divisible par les
	// deux si l'un des deux est déjà > lui).
	while (1)
	// Boucle infinie volontaire (le "return" à l'intérieur est la
	// SEULE façon d'en sortir) -- pattern courant en C pour "boucler
	// jusqu'à trouver la réponse, sans condition d'arrêt évidente à
	// l'avance".
	{
		if (n % a == 0 && n % b == 0)
			return (n);
		// Dès que n est divisible par a ET par b en même temps,
		// c'est le premier (donc le plus petit) multiple commun
		// trouvé -- puisqu'on teste dans l'ordre croissant depuis
		// max(a,b).
		++n;
	}
}

/*
POINT CLÉ : cette méthode "brute force" (tester chaque multiple un
par un) fonctionne mais peut être lente pour de grands nombres. La
méthode mathématique donnée dans le sujet -- LCM(x,y) = |x*y| / PGCD
(x,y) -- est bien plus rapide, mais nécessite d'implémenter PGCD
d'abord (voir pgcd.c). Bon exercice : réécrire lcm en utilisant cette
formule et une fonction pgcd().
*/
