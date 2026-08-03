/*
SUJET : alpha_mirror
Remplace chaque lettre par son "opposé" alphabétique : 'a'<->'z',
'b'<->'y', 'M'<->'N'. Casse inchangée.
Si nombre d'arguments != 1, afficher juste '\n'.
Fonctions autorisées : write
*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i] != '\0')
		{
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
				av[1][i] = 219 - av[1][i];
			// Astuce mathématique : on veut que 'a'(97)<->'z'(122)
			// et 'b'(98)<->'y'(121), etc. La somme d'une lettre et
			// de son opposé est toujours 97 + 122 = 219 (constant
			// !). Donc "opposé = 219 - lettre" fonctionne pour
			// n'importe quelle lettre minuscule.
			// Vérif : 'a' -> 219-97=122='z'. 'z' -> 219-122=97='a'.
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				av[1][i] = 155 - av[1][i];
			// Même principe pour les majuscules : 'A'(65) +
			// 'Z'(90) = 155.
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}

/*
POINT CLÉ : la technique "somme constante" (min + max de la plage)
est plus élégante que de faire un tas de if/else lettre par lettre.
Utile à retenir pour tout exo de "miroir"/symétrie sur une plage de
valeurs ASCII.
*/
