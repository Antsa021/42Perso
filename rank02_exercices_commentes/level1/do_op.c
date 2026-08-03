/*
SUJET : do_op
Prend 3 strings : nombre, opérateur (+ - * / %), nombre.
Affiche le résultat de l'opération suivi d'un '\n'.
Si nombre d'arguments != 3, afficher juste '\n'.
Fonctions autorisées : atoi, printf, write
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	n1 = 0;
	// Initialisation directe à la déclaration (C99), équivalent à
	// "int n1; n1 = 0;" mais en une ligne.
	int n2 = 0;
	int	res = 0;

	if (ac == 4)
	// 4 car av[0] = nom du prog, av[1]=nombre1, av[2]=opérateur,
	// av[3]=nombre2.
	{
		n1 = atoi(av[1]);
		// atoi (déjà fournie par stdlib.h, autorisée ici) convertit
		// une string en int, ex: "42" -> 42.
		n2 = atoi(av[3]);
		if (av[2][0] == '+')
		// On ne regarde QUE le premier caractère de av[2]
		// (l'opérateur), car un opérateur fait toujours 1 seul
		// caractère.
			res = n1 + n2;
		else if (av[2][0] == '-')
			res = n1 - n2;
		else if (av[2][0] == '*')
			res = n1 * n2;
		else if (av[2][0]== '/')
			res = n1 / n2;
		// Division ENTIÈRE en C : 7 / 2 = 3 (pas 3.5), le reste
		// est tronqué. Attention division par zéro non gérée ici
		// (le sujet garantit des entrées valides).
		else if (av[2][0] == '%')
			res = n1 % n2;
		// % = modulo = reste de la division entière.
		printf("%d\n", res);
		// printf est autorisé ici (contrairement à beaucoup
		// d'autres exos du rank02 où seul write l'est).
	}
	else
		write(1, "\n", 1);
}

/*
POINT CLÉ : ce sujet autorise printf ET atoi -> beaucoup plus simple
que de réimplémenter sa propre conversion/affichage comme dans
add_prime_sum ou tab_mult. Toujours vérifier la liste des fonctions
autorisées avant de commencer un exo !
*/
