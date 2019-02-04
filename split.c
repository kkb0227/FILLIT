/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 21:00:46 by kykim             #+#    #+#             */
/*   Updated: 2018/06/02 12:49:16 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			*convert(char *input, int numoftet)
{
	int		fd;
	char	*tetriminos;

	fd = open(input, O_RDONLY);
	tetriminos = (char *)malloc(sizeof(char) * (numoftet * 21));
	read(fd, tetriminos, (numoftet * 21));
	tetriminos[(numoftet * 21) - 1] = '\0';
	close(fd);
	return (tetriminos);
}

char			*onetet(char *tetriminos)
{
	char	*tetrimino;

	tetrimino = (char *)malloc(sizeof(char) * 21);
	ft_strncpy(tetrimino, tetriminos, 21);
	tetrimino[20] = '\0';
	return (tetrimino);
}

char			**splitandsave(char **listoftet, char *tetriminos, int numoftet)
{
	int i;
	int j;

	i = 0;
	j = 0;
	listoftet = (char **)malloc(sizeof(char *) * numoftet);
	while (i < numoftet)
	{
		listoftet[i] = onetet(tetriminos + j);
		i++;
		j += 21;
	}
	free(tetriminos);
	return (listoftet);
}

char			**alphabet(char **listoftet, int numoftet)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < numoftet)
	{
		j = 0;
		while (listoftet[i][j] != '\0')
		{
			if (listoftet[i][j] == '#')
				listoftet[i][j] = 'A' + i;
			j++;
		}
		i++;
	}
	return (listoftet);
}
