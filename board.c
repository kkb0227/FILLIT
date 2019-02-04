/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:01:18 by kykim             #+#    #+#             */
/*   Updated: 2018/06/02 12:15:24 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		boardsize(int numoftet)
{
	int i;

	i = 1;
	while ((numoftet * 4) > (i * i))
		i++;
	return (i);
}

void	printboard(char **board)
{
	int i;

	i = 0;
	while (board[i] != NULL)
	{
		ft_putstr(board[i]);
		ft_putchar('\n');
		i++;
	}
}

char	**initboard(char **board, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			board[i][j] = '.';
			j++;
		}
		i++;
	}
	return (board);
}

char	**makeboard(int size)
{
	char		**board;
	int			i;
	int			j;

	i = 0;
	board = (char **)malloc(sizeof(char *) * (size + 1));
	board[size] = NULL;
	while (i < size)
	{
		board[i] = (char *)malloc(sizeof(char) * (size + 1));
		board[i][size] = '\0';
		i++;
	}
	board = initboard(board, size);
	return (board);
}
