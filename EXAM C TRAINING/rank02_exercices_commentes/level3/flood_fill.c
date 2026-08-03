/*
SUJET : flood_fill
Remplit une zone d'un tableau 2D de char (comme l'outil "pot de
peinture" d'un logiciel de dessin), en remplaçant tous les caractères
connectés horizontalement/verticalement par 'F'.
void	flood_fill(char **tab, t_point size, t_point begin);
Fonctions autorisées : aucune
*/

// Passed Moulinette 2019.09.01
// This code is heavily influenced by @jochang's solution: github.com/MagicHatJo

typedef struct 	s_point {
	int			x;				// x : Largeur | axe des x
	int			y;				// y : Hauteur | axe des y
}				t_point;
// On définit une structure "point" avec deux coordonnées (x, y),
// utilisée pour représenter une position dans la grille 2D.
 
void	fill(char **tab, t_point size, t_point cur, char to_fill)
// tab : la grille (tableau de tableaux de char).
// size : les dimensions de la grille (largeur=x, hauteur=y).
// cur : la position COURANTE qu'on est en train d'examiner.
// to_fill : le caractère d'origine qu'on doit remplacer (celui qui
// était présent au tout début, à la position de départ).
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)
		return;
	// CONDITION D'ARRÊT (cas de base de la récursion) : on s'arrête
	// si on sort des limites de la grille (cur.y ou cur.x hors
	// plage), OU si le caractère à cette position N'EST PAS celui
	// qu'on doit remplacer (donc on est sorti de la "zone" à
	// remplir, ou on est déjà tombé sur du 'F' déjà rempli -- ce qui
	// évite aussi une boucle infinie de récursion !).

	tab[cur.y][cur.x] = 'F';
	// On remplit la case courante -- IMPORTANT : ça doit être fait
	// AVANT les appels récursifs, sinon la fonction rappellerait la
	// même case indéfiniment (récursion infinie).
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	// On appelle récursivement fill() sur les 4 voisins directs :
	// gauche (x-1), droite (x+1), haut (y-1), bas (y+1).
	// "(t_point){cur.x - 1, cur.y}" : syntaxe de "composite literal"
	// (C99), qui crée une structure t_point TEMPORAIRE à la volée,
	// sans avoir besoin de la déclarer et remplir sur plusieurs
	// lignes.
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
	// PAS de diagonales (comme précisé dans le sujet) : seulement
	// haut/bas/gauche/droite -> "4-connexité".
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
	// On récupère le caractère D'ORIGINE présent au point de départ
	// (tab[begin.y][begin.x]) AVANT toute modification, et on lance
	// la récursion depuis là.
}

/*
POINT CLÉ : c'est l'algorithme classique du "flood fill" (utilisé
dans les logiciels de dessin, ou pour résoudre des problèmes de
"comptage d'îles"/zones connectées). Le point le plus important à
retenir : marquer la case AVANT de récurser sur les voisins, sinon
on tombe dans une récursion infinie (chaque voisin rappellerait son
voisin d'origine indéfiniment).
*/
