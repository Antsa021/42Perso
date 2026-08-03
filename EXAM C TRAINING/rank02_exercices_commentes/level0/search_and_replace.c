/*
SUJET : search_and_replace
Prend 3 arguments : une string, une lettre à chercher, une lettre de
remplacement. Remplace la 1ère lettre (arg 2) par la 2ème (arg 3)
dans la string (arg 1). Si nombre d'arguments != 3, afficher '\n'.
Fonctions autorisées : write, exit
*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 4)
	// 4 car av[0]=nom du programme, av[1..3] = les 3 vrais arguments.
	{
		if(((av[2][0] >= 'a' && av[2][0]<= 'z') || (av[2][0] >= 'A' && av[2][0]<= 'Z')) && av[2][1] == '\0')
		// On vérifie que av[2] est bien UNE SEULE lettre :
		// - av[2][0] est un caractère alphabétique
		// - av[2][1] == '\0' -> il n'y a rien après ce caractère,
		//   donc la string av[2] fait exactement 1 caractère.
			if (((av[3][0] >= 'a' && av[2][0]<= 'z') || (av[3][0] >= 'A' && av[3][0]<= 'Z')) && av[3][1] == '\0')
			// ATTENTION, bug subtil ici : on veut vérifier que
			// av[3][0] est bien minuscule ou majuscule, mais la
			// comparaison "av[3][0]<= 'z'" utilise par erreur
			// av[2][0] au lieu de av[3][0] ! C'est une coquille
			// de copier-coller. En pratique ça fonctionne souvent
			// quand même (car av[2][0] est déjà validé comme
			// lettre juste au-dessus), mais c'est techniquement
			// incorrect et un bon correcteur/toi-même à l'exam
			// devrait repérer et corriger ce genre d'erreur.
			// Même vérification "1 seul caractère" que pour av[2].
			{
				while (av[1][i] != '\0')
				{
					if (av[1][i] == av[2][0])
					// Si le caractère courant de la string
					// correspond à la lettre cherchée...
							av[1][i] = av[3][0];
							// ...on le remplace par la
							// lettre de remplacement.
					write(1, &av[1][i], 1);
					// On écrit le caractère (modifié ou
					// non selon le cas ci-dessus).
					i++;
				}
			}
	}
	write(1, "\n", 1);
}

/*
POINT CLÉ : bien vérifier qu'un argument censé être "une seule lettre"
fait vraiment 1 seul caractère avec le test "av[x][1] == '\0'". C'est
un piège classique de l'exam : oublier cette vérification et planter
sur des arguments invalides (ex: "ab" au lieu de "a").
Ce fichier contient aussi une coquille de copier-coller (voir
commentaire ci-dessus) — bon exercice de relecture !
*/
