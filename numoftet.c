/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numoftet.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:40:33 by kykim             #+#    #+#             */
/*   Updated: 2018/05/30 20:41:13 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	numoftet(char *inputfile)
{
	int		fd;
	int		num;
	char	buff[545];
	int		count;

	count = 0;
	fd = open(inputfile, O_RDONLY);
	if (fd == -1)
		return (0);
	num = read(fd, buff, 545);
	while (num / 20)
	{
		num -= 21;
		count += 1;
	}
	close(fd);
	return (count);
}
