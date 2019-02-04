/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 18:01:49 by kykim             #+#    #+#             */
/*   Updated: 2018/06/01 21:09:12 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_tetri
{
	int hash1coor[2];
	int hash2coor[2];
	int hash3coor[2];
	int hash4coor[2];
}				t_tetri;

int				numoftet(char *inputfile);

int				howmanyadjacent(char str[20], int index);
int				countadjacent(char str[20], int buffsize);
int				fourhashed(char str[20], int buffsize);
int				validation(char str[20], int buffsize);
int				validinput(char *inputfile, int numoftet);

char			*convert(char *input, int numoftet);
char			*onetet(char *tetriminos);
char			**splitandsave(char **listoftet,
				char *tetriminos, int numoftet);
char			**alphabet(char **listoftet, int numoftet);

t_tetri			*fixcoor(t_tetri *coor);
t_tetri			*getcoor(char *tetrimino);

int				boardsize(int numoftet);
void			printboard(char **board);
char			**initboard(char **board, int size);
char			**makeboard(int size);

char			**placetet(char **board, char *tetrimino,
				int grid[2], int tetorder);
char			**removetetrimino(char **board, char c);
int				goodtoput2(char **board, t_tetri *coor, int row, int col);
int				goodtoput(char **board, char *tetrimino, int grid[2], int size);

int				solve(char **list, char **board, int tetorder, int numoftet);

void			freeboard(char **board);

void			backtrack(char **av, char **list, char **board);

#endif
