/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:53:29 by psanger           #+#    #+#             */
/*   Updated: 2024/03/27 22:27:46 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"


void	ft_lexer(char *str)
{
	char **str_split;
	int i;

	i = 0;
	str_split = ft_split(str, ' ');
	if (ft_strncmp(str_split[i], "<", 2) == 0)
		fill_list_infile(str_split[i + 1]);
	else if (ft_strncmp(str_split[i], ">", 2) == 0)
		fill_list_outfile(str_split[i + 1]);
	else if (ft_strncmp(str_split[i], ">>", 2) == 0)
		fill_list_infile(str_split[i + 1]);
	else if (ft_str)


}


int main()
{
	char *input;
	int is_running = 1;

	while (is_running)
	{
		input = readline("minishell> ");
		if (input != NULL)
		{
			ft_lexer(input);
			free(input);
			if (!strcmp(input, "exit"))
				is_running = 0;
			add_history(input);
		}
	}
	return (0);
}
