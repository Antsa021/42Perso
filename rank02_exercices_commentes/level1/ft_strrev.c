/*
SUJET : ft_strrev
Inverse une string EN PLACE (sans copie) et la retourne.
char    *ft_strrev(char *str);
*/

char *ft_strrev(char *str)
{
	int i = -1;
	// On commence à -1 volontairement (voir la boucle "++i" plus
	// bas qui va d'abord l'incrémenter à 0 avant la première
	// utilisation).
	int length = 0;
	char temporary;
	// Variable temporaire nécessaire pour l'échange (swap), même
	// principe que dans ft_swap.

	while (str[length])
		length++;
	// Calcule la longueur de la string (identique à ft_strlen).

	while (++i < length / 2)
	// ++i : PRÉ-incrémentation, donc i passe à 0 AVANT le test de
	// la condition. On ne boucle que sur la MOITIÉ de la string :
	// pas besoin d'aller jusqu'au bout, sinon on inverserait deux
	// fois chaque paire de caractères (annulant l'effet).
	// Ex: pour "abcd" (length=4), on boucle pour i=0 et i=1
	// seulement (length/2 = 2).
	{
		temporary = str[i];
		// On sauvegarde le caractère de GAUCHE (position i).
		str[i] = str[length - 1 - i];
		// On met à sa place le caractère MIROIR côté droit.
		// length - 1 : dernier index valide de la string (ex: pour
		// length=4, le dernier index est 3). "- i" : on recule
		// symétriquement depuis la fin à mesure que i augmente.
		str[length - 1 - i] = temporary;
		// Et on place l'ancien caractère de gauche (sauvegardé) à
		// la position miroir de droite -> l'échange est complet.
	}
	return (str);
	// On retourne le MÊME pointeur str, maintenant modifié en place.
}

/*
POINT CLÉ : technique "deux pointeurs qui se rapprochent du centre"
(ici i et length-1-i), très courante pour inverser un tableau/string
en place, en ne parcourant que la moitié des éléments. La comparer
avec rev_print qui fait un affichage à l'envers SANS modifier la
string (différence importante : ici on MODIFIE str directement).
*/
