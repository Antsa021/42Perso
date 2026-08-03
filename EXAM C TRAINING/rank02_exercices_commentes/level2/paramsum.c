/*
SUJET : paramsum
Affiche le nombre d'arguments passés au programme, suivi de '\n'.
Si aucun argument, afficher 0.
Fonctions autorisées : write
*/

#include <unistd.h>

void	ft_putnbr(int n)
{
	char digit;

	if (n >= 10)
		ft_putnbr(n / 10);

	digit = (n % 10) + '0';
	write(1, &digit, 1);
	// Même fonction récursive "afficher un int" que dans
	// add_prime_sum, réécrite ici (chaque exo est indépendant,
	// donc les fonctions utilitaires sont souvent dupliquées d'un
	// fichier à l'autre plutôt que partagées).
}

int		main(int argc, char **argv)
{
	(void)argv;		// Silence 'unused parameter' error
	// "(void)argv;" est une INSTRUCTION à part entière qui ne fait
	// RIEN d'utile à l'exécution, mais indique explicitement au
	// compilateur "je sais que je n'utilise pas argv, c'est fait
	// exprès". Sans ça, avec -Wall -Wextra, le compilateur
	// afficherait un warning "unused parameter 'argv'" (qui devient
	// une ERREUR bloquante avec -Werror, souvent utilisé par les
	// testeurs 42). Réflexe à avoir dès qu'un paramètre de fonction
	// n'est jamais utilisé dans son corps.

	ft_putnbr(argc - 1);
	// argc COMPREND le nom du programme (argv[0]), donc le nombre
	// de VRAIS arguments passés par l'utilisateur est argc - 1.
	write(1, "\n", 1);

	return (0);
}

/*
POINT CLÉ : le pattern "(void)variable;" pour désactiver un warning
de paramètre inutilisé est TRÈS utile à connaître pour l'exam 42 --
les testeurs compilent souvent avec -Wall -Wextra -Werror, qui
transforme ce warning en erreur bloquante.
*/
