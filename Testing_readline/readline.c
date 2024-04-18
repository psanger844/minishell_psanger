/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:54:54 by psanger           #+#    #+#             */
/*   Updated: 2024/03/25 17:18:34 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"


void	sig_quit(int param)
{
	(void)param;
	printf("control d\n");
	exit(1);
}

void	sig_int(int param)
{
	(void)param;
	printf("control c");
}

int main()
{
	char *input;
	int is_running = 1;

	signal(SIGINT, sig_int);
	signal(SIGQUIT, sig_quit);
	while (is_running)
	{
		input = readline("minishell> ");
		if (input != NULL)
		{
			printf("%s\n", input);
			free(input);
			if (!strcmp(input, "exit"))
				is_running = 0;
			add_history(input);
		}
	}
	return (0);
}
