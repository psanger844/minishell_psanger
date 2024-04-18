/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:52:49 by psanger           #+#    #+#             */
/*   Updated: 2024/04/02 18:02:30 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../LIBFT/libft.h"

void	ft_lexer(char *line);

#define CMD 0
#define INFILE 1
#define OUTFILE 2
#define APPEND 3
#define HEREDOC 4
#define BUILDIN 5


typedef struct s_minishell
{
	int							type;
	struct t_minishell			*next;
	struct t_value				*value;
}								t_minishell;

typedef struct s_value
{
	char						*cmd;				// -> cmd 			ls
	char						*args;				// -> cmd + text	args[0] = "ls" args[1] = "-la" args[2] = NULL
	char						*path_cmd;
	char						*name;
	bool						pipe;
	bool						exec;
}								t_value;

#endif
