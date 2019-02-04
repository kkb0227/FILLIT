/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readandvalidcheck.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 21:06:35 by kykim             #+#    #+#             */
/*   Updated: 2018/05/30 21:34:08 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	howmanyadjacent(char str[20], int index)
{
	int count;

	count = 0;
	if (((index - 1) >= 0) && (str[index - 1] == '#'))
		count += 1;
	if (((index + 1) <= 18) && (str[index + 1] == '#'))
		count += 1;
	if (((index - 5) >= 0) && (str[index - 5] == '#'))
		count += 1;
	if (((index + 5) <= 18) && (str[index + 5] == '#'))
		count += 1;
	return (count);
}

int	countadjacent(char str[20], int buffsize)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < buffsize)
	{
		if (str[i] == '#')
			count += howmanyadjacent(str, i);
		i++;
	}
	return (count);
}

int	fourhashed(char str[20], int buffsize)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (i < buffsize)
	{
		if (str[i] == '#')
			count += 1;
		i++;
	}
	if (count != 4)
		return (0);
	return (1);
}

int	validation(char str[20], int buffsize)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n' || str[19] != '\n')
		return (0);
	while (i < buffsize)
	{
		if (str[i] == '.')
			count += 1;
		i++;
	}
	if (count != 12)
		return (0);
	if (!fourhashed(str, buffsize))
		return (0);
	count = countadjacent(str, buffsize);
	if (count != 6 && count != 8)
		return (0);
	return (1);
}

int	validinput(char *inputfile, int numoftet)
{
	int		fd;
	int		i;
	char	buff[20];

	i = 0;
	fd = open(inputfile, O_RDONLY);
	if (fd == -1)
		return (0);
	while (i < numoftet)
	{
		read(fd, buff, 20);
		if (!validation(buff, 20))
			return (0);
		if (i == numoftet - 1)
		{
			if (read(fd, buff, 20) == 0)
				return (1);
			else
				return (0);
		}
		read(fd, buff, 1);
		i++;
	}
	close(fd);
	return (0);
}
