/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:57:27 by psanger           #+#    #+#             */
/*   Updated: 2024/03/28 15:06:11 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "testingminishell.h"


char *ft_strncpy(char *s1, char *s2, int n)
{
	int i = -1;

	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

char	**ft_psplit(char *str, char c)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int wc = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == c))
			i++;
		if (str[i])
			wc++;
		while (str[i] && (str[i] != c))
			i++;
	}
	char **out = (char **)malloc(sizeof(char *) * (wc + 1));
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == c))
			i++;
		j = i;
		while (str[i] && (str[i] != c))
			i++;
		if (i > j)
		{
			out[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(out[k++], &str[j], i - j);
		}
	}
	out[k] = NULL;
	return (out);
}

int	ft_strlen(char *str)
{
	if (str == NULL)
		return (0);
	int	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_free(char *str, char *str2)
{
	int	i = 0;
	int	j = 0;
	char	*dest;
	dest = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(str2) + 1));
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	while (str2[j] != '\0')
	{
		dest[i + j] = str2[j];
		j++;
	}
	dest[i + j] = '\0';
	free(str);
	return (dest);
}



char	*get_path(char *argv)
{
	char *env = getenv("PATH");
	char **exe_path = ft_psplit(env, ':');
	int i = 0;
	while (exe_path[i]) {
		exe_path[i] = ft_strjoin_free(exe_path[i], "/");
		exe_path[i] = ft_strjoin_free(exe_path[i], argv);
		if (access(exe_path[i], X_OK) == 0)
		{
			printf("%s\n", exe_path[i]);
			// return (exe_path[i]);
		}
		else
		{
			
		}
		i++;
	}
	return (0);
}

int main()
{
	get_path("ls");
	return 0;
}


// void	funktion(char *cmd, char *text)
// {
// 	if (text != NULL)
// 	{
// 		char *argv[3];
// 		argv[0] = cmd;
// 		argv[1] = text;
// 		argv[2] = NULL;
// 	}
// 	else if (text == NULL)
// 	{
// 		char *argv[2];
// 		argv[0] = cmd;
// 		argv[1] = NULL;
// 	}

// }
