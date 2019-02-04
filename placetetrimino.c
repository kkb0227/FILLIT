/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placetetrimino.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:56:46 by kykim             #+#    #+#             */
/*   Updated: 2018/05/31 10:38:52 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**placetet(char **board, char *tetrimino, int grid[2], int tetorder)
{
	char		c;
	t_tetri		*coor;
	int			x;
	int			y;

	coor = getcoor(tetrimino);
	c = 'A' + tetorder;
	x = grid[0] - coor->hash1coor[0];
	y = grid[1] - coor->hash1coor[1];
	board[coor->hash1coor[0] + x][coor->hash1coor[1] + y] = c;
	board[coor->hash2coor[0] + x][coor->hash2coor[1] + y] = c;
	board[coor->hash3coor[0] + x][coor->hash3coor[1] + y] = c;
	board[coor->hash4coor[0] + x][coor->hash4coor[1] + y] = c;
	free(coor);
	return (board);
}

char	**removetetrimino(char **board, char c)
{
	int i;
	int j;

	i = 0;
	while (board[i] != NULL)
	{
		j = 0;
		while (board[i][j] != '\0')
		{
			if (board[i][j] == c)
				board[i][j] = '.';
			j++;
		}
		i++;
	}
	return (board);
}

int		goodtoput2(char **board, t_tetri *coor, int row, int col)
{
	if ((board[coor->hash1coor[0] + row][coor->hash1coor[1] + col] == '.'
		&& board[coor->hash2coor[0] + row][coor->hash2coor[1] + col] == '.'
		&& board[coor->hash3coor[0] + row][coor->hash3coor[1] + col] == '.'
		&& board[coor->hash4coor[0] + row][coor->hash4coor[1] + col] == '.'))
	{
		return (1);
	}
	else
		return (0);
}

int		goodtoput(char **board, char *tetrimino, int grid[2], int size)
{
	t_tetri		*coor;
	int			row;
	int			col;

	coor = getcoor(tetrimino);
	row = grid[0] - coor->hash1coor[0];
	col = grid[1] - coor->hash1coor[1];
	if ((coor->hash1coor[0] + row >= 0 && coor->hash1coor[0] + row < size)
		&& (coor->hash2coor[0] + row >= 0 && coor->hash2coor[0] + row < size)
		&& (coor->hash3coor[0] + row >= 0 && coor->hash3coor[0] + row < size)
		&& (coor->hash4coor[0] + row >= 0 && coor->hash4coor[0] + row < size)
		&& (coor->hash1coor[1] + col >= 0 && coor->hash1coor[1] + col < size)
		&& (coor->hash2coor[1] + col >= 0 && coor->hash2coor[1] + col < size)
		&& (coor->hash3coor[1] + col >= 0 && coor->hash3coor[1] + col < size)
		&& (coor->hash4coor[1] + col >= 0 && coor->hash4coor[1] + col < size))
	{
		if (goodtoput2(board, coor, row, col))
		{
			free(coor);
			return (1);
		}
	}
	free(coor);
	return (0);
}
