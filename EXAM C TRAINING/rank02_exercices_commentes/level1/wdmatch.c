/*
SUJET : wdmatch
Prend deux strings, vérifie s'il est possible d'écrire la 1ère en
utilisant les caractères de la 2ème DANS L'ORDRE où ils apparaissent.
Si possible, affiche la string 1 + '\n', sinon juste '\n'.
Fonctions autorisées : write
*/

#include <unistd.h>

void ft_putstr(char const *str)
// "char const *str" = équivalent de "const char *str" (l'ordre des
// mots-clés const/type n'a pas d'importance ici) : promesse de ne
// pas modifier str.
{
	int i = 0;

	while (str[i])
		write(1, &str[i++], 1);
	// str[i++] : on utilise i (valeur AVANT incrémentation) pour
	// indexer, PUIS on incrémente. Équivalent à écrire
	// "write(1, &str[i], 1); i++;" mais en une seule ligne compacte.
}

int	main(int argc, char const *argv[])
{
	int i = 0;
	// index dans argv[1] (le mot qu'on veut "matcher").
	int j = 0;
	// index dans argv[2] (la string source dans laquelle chercher).

	if (argc == 3)
	{
		while (argv[2][j])
			if (argv[2][j++] == argv[1][i])
				i += 1;
		// Pour CHAQUE caractère de argv[2] (parcouru en entier une
		// seule fois, dans l'ordre), on vérifie s'il correspond au
		// caractère COURANT qu'on cherche dans argv[1] (à la
		// position i). Si oui, on avance i (on cherche maintenant
		// le caractère SUIVANT de argv[1]).
		// C'est un algo "glouton" à deux pointeurs classique pour
		// vérifier une "sous-séquence" (pas besoin que les
		// caractères soient consécutifs, juste dans le bon ordre).
		if (!argv[1][i])
		// Si à la fin, i a atteint le '\0' de argv[1], ça veut dire
		// qu'on a réussi à faire avancer i jusqu'au bout -> TOUS
		// les caractères de argv[1] ont été trouvés dans l'ordre
		// dans argv[2] -> match réussi.
			ft_putstr(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}

/*
POINT CLÉ : le pattern "double pointeur, un qui avance toujours (j),
l'autre qui n'avance QUE sur un match (i)" est l'algo classique de
recherche de sous-séquence (subsequence matching). Très différent
d'une recherche de SOUS-CHAÎNE (substring) qui exigerait des
caractères consécutifs.
*/
