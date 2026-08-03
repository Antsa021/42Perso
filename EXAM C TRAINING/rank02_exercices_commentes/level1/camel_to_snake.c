/*
SUJET : camel_to_snake
Convertit une string lowerCamelCase en snake_case.
"helloWorld" -> "hello_world"
Fonctions autorisées : malloc, free, realloc, write
*/

#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		for (int i = 0; argv[1][i]; i += 1)
		// Déclaration de i DANS le for (C99) : i n'existe que dans
		// la portée de cette boucle. "argv[1][i]" comme condition
		// = équivalent de "argv[1][i] != '\0'".
		{
			if (argv[1][i] >= 'A' 
			&& argv[1][i] <= 'Z')
			// Si on rencontre une majuscule (= début d'un
			// nouveau mot en camelCase)...
			{
				write(STDOUT_FILENO, "_", 1);
				// ...on insère d'abord un underscore avant.
				// STDOUT_FILENO est une constante (valeur 1)
				// définie dans unistd.h, plus lisible/portable
				// que le "1" écrit en dur.
				argv[1][i] += 32;
				// ...puis on la convertit en minuscule (+32,
				// même astuce ASCII que dans ulstr).
				// ATTENTION : on modifie argv[1] directement
				// EN PLACE. C'est autorisé ici car argv est
				// modifiable, mais ce n'est pas toujours le
				// cas (attention aux "const char *" ailleurs).
			}
			write(STDOUT_FILENO, &argv[1][i], 1);
			// On écrit le caractère (déjà converti en minuscule
			// juste au-dessus si c'était une majuscule, ou
			// inchangé sinon).
		}
	}
	write(STDOUT_FILENO, "\n", 1);
	return EXIT_SUCCESS;
	// EXIT_SUCCESS est une constante (valeur 0) de stdlib.h, plus
	// explicite que "return (0);" mais strictement équivalente.
}

/*
POINT CLÉ : malloc/free/realloc sont autorisés dans le sujet mais
PAS utilisés ici, car cette solution modifie argv EN PLACE (la
conversion camelCase -> snake_case ne fait qu'insérer des '_' avant
les majuscules, elle n'a pas besoin d'allouer un buffer plus grand
puisqu'on n'ajoute qu'un caractère par majuscule rencontrée, écrit
directement avec write() au fur et à mesure, sans le stocker).
*/
