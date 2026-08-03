/*
SUJET : rev_print
Affiche une string à l'envers, suivie d'un '\n'.
Si nombre d'arguments != 1, afficher juste '\n'.
Fonctions autorisées : write
*/

#include <unistd.h>

int	main(int argc, char *argv[])
// char *argv[] est une autre écriture STRICTEMENT équivalente à
// char **argv (tableau de pointeurs = pointeur de pointeurs). Les
// deux notations sont interchangeables pour ce paramètre.
{
	int	i = 0;
	// Déclaration ET initialisation en une seule ligne (C99),
	// équivalent à "int i; i = 0;" séparément.

	if (argc == 2)
	{
		while (argv[1][i])
		// "while (argv[1][i])" est un raccourci pour
		// "while (argv[1][i] != '\0')" : en C, tout ce qui n'est
		// pas 0 est considéré "vrai" dans un test. Le caractère
		// '\0' vaut 0, donc quand on l'atteint, la boucle s'arrête.
			i += 1;
		// PREMIÈRE boucle : on avance jusqu'à la fin de la string
		// pour calculer sa longueur (i devient égal à cette
		// longueur une fois la boucle terminée).
		while (i)
		// DEUXIÈME boucle : tant que i n'est pas revenu à 0.
			write(1, &argv[1][--i], 1);
			// --i : PRÉ-décrémentation. On décrémente i D'ABORD,
			// PUIS on utilise sa nouvelle valeur pour indexer.
			// Donc si i valait 3 (longueur de "abc"), --i le
			// passe à 2 AVANT l'accès -> on lit argv[1][2] = 'c'
			// (le DERNIER caractère), pas '\0'.
			// On répète : i passe à 1 -> lit 'b', puis 0 -> lit
			// 'a'. On affiche donc bien la string à l'envers,
			// sans jamais utiliser de tableau intermédiaire.
	}
	write(1, "\n", 1);
	return (0);
}

/*
POINT CLÉ : ce code montre une technique élégante pour inverser
l'affichage SANS créer de copie de la string : calculer la longueur,
puis parcourir à rebours avec --i (pré-décrémentation) directement
dans l'accès au tableau.
*/
