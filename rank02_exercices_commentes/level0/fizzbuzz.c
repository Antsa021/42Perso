/*
SUJET : fizzbuzz
Afficher les nombres de 1 à 100, un par ligne.
- Multiple de 3       -> "fizz"
- Multiple de 5       -> "buzz"
- Multiple de 3 ET 5  -> "fizzbuzz"
- Sinon               -> le nombre lui-même
Fonctions autorisées : write
*/

#include <unistd.h>

int	main(void)
{
	int	i;
	// i : le compteur qui va parcourir 1 à 100 (le nombre courant).
	int k;
	// k : va contenir le chiffre des DIZAINES du nombre (converti en
	// caractère ASCII), utilisé seulement si le nombre a 2 chiffres.
	int l;
	// l : va contenir le chiffre des UNITÉS du nombre (idem).

	i = 1;
	// On commence à 1 (pas 0), car le sujet demande "de 1 à 100".
	while (i <= 100)
	// Boucle principale : tant qu'on n'a pas dépassé 100.
	{
		if ((i % 3 == 0) && (i % 5 == 0))
		// % = modulo = reste de la division. i % 3 == 0 signifie
		// "i est divisible par 3 sans reste" = multiple de 3.
		// On teste D'ABORD le cas "multiple des deux" car il faut
		// bien le traiter avant les cas isolés (sinon on afficherait
		// juste "fizz" ou "buzz" et jamais "fizzbuzz").
			write(1, "fizzbuzz", 8);
			// "fizzbuzz" fait 8 caractères -> on écrit 8 octets.
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else if (i > 10)
		// Ici, i n'est multiple ni de 3 ni de 5 : il faut afficher
		// le nombre lui-même. Comme on n'a pas le droit à printf,
		// on doit convertir "à la main" chaque chiffre en caractère.
		// Ce cas gère les nombres à 2 chiffres (11 à 100, sauf 10
		// qui est capturé par la condition précédente sur les
		// multiples de 5... en fait ce test i > 10 gère 11-100,
		// SAUF ceux déjà filtrés par fizz/buzz/fizzbuzz au-dessus).
		{
			k = i / 10 + '0';
			// i / 10 : division ENTIÈRE en C, donc pour i = 42,
			// 42 / 10 = 4 (le chiffre des dizaines).
			// + '0' : on convertit ce chiffre (0-9) en son
			// caractère ASCII correspondant. '0' vaut 48 en
			// ASCII, donc 4 + '0' = 4 + 48 = 52 = caractère '4'.
			l = i % 10 + '0';
			// i % 10 : le reste de la division par 10, donc le
			// chiffre des UNITÉS. Pour i = 42 : 42 % 10 = 2.
			// Même conversion en caractère ASCII.
			write (1, &k, 1);
			// On écrit le chiffre des dizaines en premier.
			write (1, &l, 1);
			// Puis celui des unités -> ex: "4" puis "2" = "42".
		}
		else
		// Cas restant : i est un nombre à 1 seul chiffre (1 à 9,
		// hors multiples de 3/5 déjà traités : donc 1,2,4,7,8).
		{
			k = i + '0';
			// Conversion directe du chiffre unique en caractère.
			write(1, &k, 1);
		}
		write(1,"\n", 1);
		// Newline après CHAQUE nombre/mot affiché, quel que soit
		// le cas rencontré ci-dessus.
		i++;
		// On passe au nombre suivant.
	}
}

/*
POINT CLÉ : le pattern "chiffre des dizaines / unités" via / 10 et % 10
+ '0' est LE classique pour afficher un int sans printf. Tu le
retrouveras partout (ft_putnbr, tab_mult, add_prime_sum...).
Attention : ce fizzbuzz ne gère que jusqu'à 2 chiffres (100 inclus,
qui est un cas particulier à vérifier : 100 est multiple de 5 donc
"buzz" s'affiche avant qu'on ait besoin de gérer 3 chiffres).
*/
