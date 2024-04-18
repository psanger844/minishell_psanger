/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:15:55 by psanger           #+#    #+#             */
/*   Updated: 2024/03/20 15:57:59 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testingminishell.h"

void	init_data(char **argv, t_data *data)
{
	data->cmd1 = argv[1];
	data->cmd2 = argv[2];
	data->cmd3 = argv[3];
	data->path_cmd1 = get_path(data->cmd1);
	data->path_cmd2  = get_path(data->cmd2);
	data->path_cmd2  = get_path(data->cmd3);
	data->cpy_stdin = dup(STDIN_FILENO);
	data->cpy_stdout = dup(STDOUT_FILENO);
	// printf("%s\n%s\n%s\n%s\n\n--------\n", data->cmd1, data->cmd2, data->path_cmd1, data->path_cmd2);
}
