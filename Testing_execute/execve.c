/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:59:21 by psanger           #+#    #+#             */
/*   Updated: 2024/03/27 15:47:39 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testingminishell.h"

void	child1(char *path, int pfd[2], char *cmd1)
{
	close(pfd[0]);
	dup2(pfd[1], STDOUT_FILENO);
	close(pfd[1]);
	char *argv[2];
	argv[0] = cmd1;
	argv[1] = NULL;
	if (execve(path, argv, NULL) == -1)
	{
		write(2, "Wrong Input1\n", 14);
		exit(1);
	}
}

void	child2(char *path, int pfd[2], char *cmd2)
{
	dup2(pfd[1], STDOUT_FILENO);
	close(pfd[1]);
	dup2(pfd[0], STDIN_FILENO);
	close(pfd[0]);
	char *argv[2];
	argv[0] = cmd2;
	argv[1] = NULL;
	if (execve(path, argv, NULL) == -1)
	{
		write(2, "Wrong Input2\n", 14);
		exit(1);
	}
}

void	child3(char *path, int pfd[2], char *cmd3)
{
	close(pfd[1]);
	dup2(pfd[0], STDIN_FILENO);
	close(pfd[0]);
	char *argv[2];
	argv[0] = cmd3;
	argv[1] = NULL;

		char buffer[100];
		int i = read(0, buffer, 100);
		buffer[i] = '\0';
		printf("%s\n", buffer);
		exit(0);
	// if (execve(path, argv, NULL) == -1)
	// {
	// 	write(2, "Wrong Input3\n", 14);
	// 	exit(1);
	// }
}

