/*
SUJET : ft_split
Découpe une string en mots, retourne un tableau de strings terminé
par NULL.
char	**ft_split(char *str);
Fonctions autorisées : malloc
*/

#include <stdlib.h>

int	ft_wordlen(char *str)
{
	int i = 0;

	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		++i;
	return (i);
}

char	*word_dupe(char *str)
// Alloue et copie UN mot (jusqu'au prochain séparateur ou fin).
{
	int i = 0;
	int len = ft_wordlen(str);
	char *word = malloc(sizeof(char) * (len + 1));
	// +1 pour le '\0' final, comme toujours.
	
	word[len] = '\0';
	while (i < len)
	{
		word[i] = str[i];
		++i;
	}
	return (word);
}

void	fill_words(char **array, char *str)
// Remplit le tableau "array" (déjà alloué) avec un pointeur vers
// chaque mot dupliqué.
{
	int word_index = 0;
	
	while (*str == ' ' || *str == '\t' || *str == '\n')
		++str;
	// On saute les séparateurs éventuels avant le premier mot.
	while (*str != '\0')
	{
		array[word_index] = word_dupe(str);
		// On alloue et copie le mot COURANT, et on stocke le
		// pointeur résultant dans le tableau.
		++word_index;
		while (*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n')
			++str;
		// On avance str jusqu'à la fin du mot qu'on vient de copier.
		while (*str == ' ' || *str == '\t' || *str == '\n')
			++str;
		// Puis on saute les séparateurs avant le mot suivant.
	}
}

int		count_words(char *str)
// Compte le nombre de mots dans str, SANS rien allouer -- juste pour
// savoir la taille du tableau à créer ensuite.
{
	int num_words = 0;
	
	while (*str == ' ' || *str == '\t' || *str == '\n')
		++str;
	while (*str != '\0')
	{
		++num_words;
		while (*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n')
			++str;
		while (*str == ' ' || *str == '\t' || *str == '\n')
			++str;
	}
	return (num_words);
	// Remarquer que cette fonction a EXACTEMENT la même structure
	// de boucles que fill_words, sauf qu'au lieu de dupliquer le mot
	// elle se contente de compter -- c'est volontaire : il faut
	// D'ABORD savoir combien de mots il y a (pour allouer le
	// tableau à la bonne taille), avant de pouvoir les remplir.
}

char	**ft_split(char *str)
{
	int		num_words;
	char	**array;
	// "char **" : tableau de pointeurs vers des strings (chaque
	// case du tableau contient l'adresse d'un mot).
	
	num_words = count_words(str);
	array = malloc(sizeof(char *) * (num_words + 1));
	// +1 : IMPORTANT, il faut une case SUPPLÉMENTAIRE pour marquer
	// la FIN du tableau avec NULL (comme argv qui se termine toujours
	// par un pointeur NULL implicite) -- sinon impossible de savoir
	// où s'arrête le tableau quand on le parcourt plus tard.
	
	array[num_words] = 0;
	// On place ce marqueur de fin (NULL) à la toute dernière case.
	fill_words(array, str);
	return (array);
}

/*
POINT CLÉ : le pattern "compter d'abord (count_words), PUIS allouer,
PUIS remplir (fill_words)" est indispensable dès qu'on doit créer un
tableau de TAILLE VARIABLE avec malloc -- on ne peut pas allouer
"au fur et à mesure" en C comme on le ferait avec une liste
dynamique d'un langage haut niveau. Il faut TOUJOURS connaître la
taille à l'avance (ou réallouer avec realloc, mais c'est plus complexe).
Ne pas oublier le "+1" pour le NULL final du tableau de pointeurs, en
plus du "+1" habituel pour le '\0' de chaque string individuelle.
*/
