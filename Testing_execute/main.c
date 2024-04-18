/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:00:22 by psanger           #+#    #+#             */
/*   Updated: 2024/03/20 16:00:18 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testingminishell.h"


int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		printf("Wrong number of args\n");
		return (1);
	}
	t_data	data;
	int		status;

	init_data(argv, &data);
	int pfd[2];
	pipe(pfd);	// 0 = read || 1 = write
	int pid1, pid2, pid3;


	pid1 = fork();
	if (pid1 == 0) // child1
	{
		child1(data.path_cmd1, pfd, data.cmd1);
	}


	pid2 = fork();
	if (pid2 == 0) // child2
	{
		waitpid(pid1, NULL, 0);
		child2(data.path_cmd2, pfd, data.cmd2);
	}


	pid3 = fork();
	{
		waitpid(pid2, NULL, 0);
		child3(data.path_cmd3, pfd, data.cmd3);
	}
	return (WIFEXITED(status) && WEXITSTATUS(status));
}
