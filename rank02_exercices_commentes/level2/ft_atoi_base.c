/*
SUJET : ft_atoi_base
Convertit une string dans une base N (<=16) en un int base 10.
Caractères reconnus : 0123456789abcdef, majuscules acceptées.
'-' interprété seulement en tout premier caractère.
int	ft_atoi_base(const char *str, int str_base);
*/

char	to_lower(char c)
// Convertit une lettre majuscule en minuscule (caractères non-lettres
// inchangés).
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	// ('a' - 'A') vaut 32 (calculé au lieu d'être écrit en dur --
	// plus lisible/explicite que "+ 32").
	return (c);
}

int get_digit(char c, int digits_in_base)
// Convertit un caractère en sa valeur numérique dans la base donnée,
// ou retourne -1 s'il n'est pas valide dans cette base.
{
	int max_digit;
	if (digits_in_base <= 10)
		max_digit = digits_in_base + '0';
	// Pour une base <= 10 (ex: base 8), le "chiffre max autorisé"
	// est un CHIFFRE (ex: base 8 -> chiffres 0 à 7, donc max_digit
	// = 7 + '0' = caractère '7').
	else
		max_digit = digits_in_base - 10 + 'a';
	// Pour une base > 10 (ex: base 16), le chiffre max devient une
	// LETTRE (ex: base 16 -> jusqu'à 'f', car 16-10='6', '6'+'a'
	// décalé... en fait 16-10=6, 'a'+6='g' ? Attention : ici pour
	// base=16, digits_in_base-10=6, donc max_digit='a'+6='g' — mais
	// en pratique le code limite déjà les lettres à 'a'-'f' juste en
	// dessous, donc ce calcul sert de plafond mais la vraie limite
	// vient des tests suivants.

	if (c >= '0' && c <= '9' && c <= max_digit)
		return (c - '0');
	// Chiffre valide ET dans la plage autorisée par la base.
	else if (c >= 'a' && c <= 'f' && c <= max_digit)
		return (10 + c - 'a');
	// Lettre a-f valide : 'a' vaut 10, 'b' vaut 11... 'f' vaut 15.
	else
		return (-1);
	// Caractère invalide dans cette base (ou fin de string) -> -1
	// sert de "signal d'arrêt" pour la boucle principale.
}

int ft_atoi_base(const char *str, int str_base)
{
	int result = 0;
	int sign = 1;
	int digit;

	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	// Gestion du signe négatif, uniquement en tout premier caractère
	// (comme demandé par le sujet).

	while ((digit = get_digit(to_lower(*str), str_base)) >= 0)
	// Astuce : on assigne ET on teste dans la même expression.
	// to_lower(*str) : on normalise la casse avant de tester.
	// get_digit(...) retourne -1 si le caractère n'est pas un
	// chiffre valide dans la base -> la boucle s'arrête là (ce qui
	// gère naturellement le '\0' final aussi, puisque '\0' n'est
	// un chiffre valide dans aucune base).
	{
		result = result * str_base;
		// On "décale" le résultat d'un rang dans LA BASE demandée
		// (pas forcément *10 comme en décimal -- ici *str_base,
		// ex: *16 pour de l'hexadécimal).
		result = result + (digit * sign);
		// On applique le signe À CHAQUE chiffre (équivalent à
		// l'appliquer une fois à la fin, mais fait ici chiffre par
		// chiffre).
		++str;
	}
	return (result);
}

/*
POINT CLÉ : c'est une généralisation de ft_atoi qui fonctionne pour
n'importe quelle base (pas seulement 10). Le principe "result =
result * base + chiffre" reste identique, seule la BASE change.
Comparer avec print_hex (qui fait l'opération INVERSE : décimal vers
hexadécimal).
*/
