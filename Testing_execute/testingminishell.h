/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testingminishell.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:57:55 by psanger           #+#    #+#             */
/*   Updated: 2024/03/25 17:32:36 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTINGMINISHELL_H
#define TESTINGMINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct s_data
{
	char		*cmd1;
	char		*cmd2;
	char		*cmd3;
	char		*path_cmd1;
	char		*path_cmd2;
	char		*path_cmd3;
	int			cpy_stdin;
	int			cpy_stdout;
	char		*infile;
	char		*outfile;
}				t_data;
// 
void	child1(char *path, int pfd[2], char *cmd1);
void	child2(char *path, int pfd[2], char *cmd2);
void	child3(char *path, int pfd[2], char *cmd3);
void	init_data(char **argv, t_data *data);
char	*get_path(char *argv);

#endif
