/*
SUJET : snake_to_camel
Convertit une string snake_case en lowerCamelCase (inverse de
camel_to_snake).
"hello_world" -> "helloWorld"
Fonctions autorisées : malloc, free, realloc, write
*/

#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		for (int i = 0; argv[1][i]; i += 1)
		{
			if (argv[1][i] == '_')
			// Si on rencontre un underscore (séparateur de mot
			// en snake_case)...
			{
				i += 1;
				// ...on saute directement l'underscore lui-
				// même (il ne doit PAS apparaître dans le
				// résultat)...
				argv[1][i] -= 32;
				// ...et on met en majuscule le caractère qui
				// SUIT immédiatement l'underscore (début du
				// nouveau mot en camelCase). -32 = même
				// astuce ASCII inversée que dans
				// camel_to_snake (minuscule -> majuscule).
			}
			write(STDOUT_FILENO, &argv[1][i], 1);
			// On écrit le caractère courant (déjà transformé en
			// majuscule juste au-dessus si besoin).
		}
	}
	write(STDOUT_FILENO, "\n", 1);
	return EXIT_SUCCESS;
}

/*
POINT CLÉ : exercice miroir de camel_to_snake ! Comparer les deux
côte à côte est un excellent exercice de révision : l'un INSÈRE un
caractère ('_') avant chaque majuscule, l'autre SUPPRIME un caractère
('_') et met la lettre suivante en majuscule. Même logique de base
(parcours + transformation ASCII +/-32), sens inverse.
ATTENTION (bug potentiel) : si l'argument se termine PAR un '_' (ex:
"hello_"), alors "i += 1" fait pointer i sur le '\0' final, et
"argv[1][i] -= 32" modifierait le caractère nul lui-même (comportement
indéfini/risqué). Le sujet suppose des entrées valides, mais c'est le
genre de edge case à repérer à l'exam.
*/
