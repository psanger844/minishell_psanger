/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:05:27 by psanger           #+#    #+#             */
/*   Updated: 2024/04/16 21:11:01 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

void	exec_ls()
{
	int pid = fork();
	if (pid < 0) {
		printf("ERROR PIPE\n");
	}
	if (pid == 0) {
		char *args[] = {"ls", NULL};
		execve("/bin/ls", args, NULL);
	}
	else {
		waitpid(pid, NULL, 0);
	}
}

char	*get_oldpwd()
{
	t_env *curr;
}


void	cd(char *argv)
{
	char *new_dir = argv;
	if (argv[0] == '-' && argv[1] == '\0') {
		new_dir = get_oldpwd();
		if (new_dir == NULL)
			return ;
	}
	// export("OLDPWD=", getcwd());
	else if ((argv[0] == '~' && argv[1] =='\0') || argv == NULL)
		new_dir = getenv("HOME");
	// export("PWD=", getcwd());
	chdir(new_dir);
}

int main(int argc, char **argv)
{
	if (argc != 3) {
		printf("wrong number of args\n");
		return (0);
	}
	printf("%s\t%s\t%s\n", argv[0], argv[1], argv[2]);
	char *new_dir;
	cd(argv[2]);
	exec_ls();
	return (0);
}
