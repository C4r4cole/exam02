/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 09:59:55 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/18 10:31:44 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_point {
	int x;
	int y;
} t_point;

void fill(char **tab, t_point size, int x, int y, char to_fill)
{
	// 1. Vérifier si on sort de la grille
	if (x < 0 || y < 0 || x >= size.x || y >= size.y)
		return;

	// 2. Si ce n'est pas le bon caractère, on arrête
	if (tab[y][x] != to_fill)
		return;

	// 3. On remplit cette case
	tab[y][x] = 'F';

	// 4. Appel récursif sur les voisins
	fill(tab, size, x + 1, y, to_fill); // droite
	fill(tab, size, x - 1, y, to_fill); // gauche
	fill(tab, size, x, y + 1, to_fill); // bas
	fill(tab, size, x, y - 1, to_fill); // haut
}

void flood_fill(char **tab, t_point size, t_point begin)
{
	char to_fill = tab[begin.y][begin.x];
	fill(tab, size, begin.x, begin.y, to_fill);
}
