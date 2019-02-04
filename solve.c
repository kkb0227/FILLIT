/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 19:17:27 by kykim             #+#    #+#             */
/*   Updated: 2018/06/02 12:15:22 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	solve(char **list, char **board, int tetorder, int numoftet)
{
	int grid[2];
	int i;

	i = ft_strlen(board[0]);
	if (tetorder == numoftet)
		return (1);
	grid[0] = 0;
	while (board[grid[0]] != NULL)
	{
		grid[1] = 0;
		while (board[grid[0]][grid[1]] != '\0')
		{
			if (goodtoput(board, list[tetorder], grid, i))
			{
				board = placetet(board, list[tetorder], grid, tetorder);
				if (solve(list, board, tetorder + 1, numoftet))
					return (1);
				board = removetetrimino(board, 'A' + tetorder);
			}
			grid[1]++;
		}
		grid[0]++;
	}
	return (0);
}
