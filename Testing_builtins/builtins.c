/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:03:49 by psanger           #+#    #+#             */
/*   Updated: 2024/04/18 16:33:10 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// BUILTINS
// cd ✓
// pwd ✓
// echo x
// env ✓
// export ✓
// unset ✓
// exit x free all

#include "builtin.h"

char	*itoa_pt2(long int num, int n_p, char *str, int nbr_len)
{
	int	minus;

	minus = 0;
	str[nbr_len] = '\0';
	nbr_len--;
	if (num == 0)
	{
		str[nbr_len] = '0';
		return (str);
	}
	if (n_p == -1)
	{
		str[0] = '-';
		minus = 1;
	}
	while (nbr_len >= minus)
	{
		str[nbr_len] = num % 10 + '0';
		num = num / 10;
		nbr_len--;
	}
	return (str);
}

int	ft_nbr_len(long int num)
{
	int	i;

	i = 0;
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int	num;
	char		*str;
	int			n_p;
	int			nbr_len;

	nbr_len = 0;
	n_p = 0;
	num = (long int)n;
	if (num <= 0)
	{
		num = num * -1;
		n_p = -1;
		nbr_len++;
	}
	nbr_len = nbr_len + ft_nbr_len(num);
	str = (char *)malloc(sizeof(char) * (nbr_len + 1));
	if (!str)
		return (NULL);
	return (itoa_pt2(num, n_p, str, nbr_len));
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	minus;

	i = 0;
	num = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\f'
		|| str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * minus);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen((char *)s1);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;
	int		s1_len;
	int		s2_len;

	i = 0;
	j = 0;
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return ((char *)str);
}

int	ft_isalnum(unsigned char c)
{
	if ((c <= '9' && c >= '0') || (c <= 'z' && c >= 'a') || (c <= 'Z'
			&& c >= 'A'))
		return (1);
	else
		return (0);
}

int	ft_isalpha(int c)
{
	if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
		return (1);
	else
		return (0);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] != '\0' && s2[i] != '\0')
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i] && s1[i] != '\0'
			&& s2[i] != '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*get_key(char *envp)
{
	int		i;
	int		j;
	char	*key;

	i = 0;
	j = 0;
	while (envp[i] != '\0' && envp[i] != '=')
		i++;
	if (envp[i] == '\0')
		return (NULL);
	key = malloc(sizeof(char) * (i + 1));
	while (j < i)
	{
		key[j] = envp[j];
		j++;
	}
	key[j] = '\0';
	return (key);
}

void	pwd(void)
{
	char	pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	printf("%s\n", pwd);
}

t_env	*env_add_back(t_env *list, char *envp)
{
	t_env	*new_node;
	t_env	*curr;

	curr = list;
	new_node = malloc(sizeof(t_env));
	new_node->value = malloc(sizeof(char) * (ft_strlen(envp) + 1));
	ft_strlcpy(new_node->value, envp, ft_strlen(envp) + 1);
	new_node->key = get_key(envp);
	new_node->next = NULL;
	list->next = new_node;
	return (new_node);
}

t_env	*init_struct_env(char **envp)
{
	int		i;
	t_env	*env;
	t_env	*curr;

	if (envp == NULL || envp[0] == NULL)
		return (NULL);
	i = 0;
	env = malloc(sizeof(t_env));
	env->next = NULL;
	env->value = malloc(sizeof(char) * (ft_strlen(envp[i]) + 1));
	curr = env;
	ft_strlcpy(env->value, envp[i], ft_strlen(envp[i]));
	env->key = get_key(envp[i]);
	i++;
	while (envp[i] != NULL)
	{
		curr = env_add_back(curr, envp[i]);
		i++;
	}
	return (env);
}

void	unset(char *argv, t_env *env)
{
	t_env	*curr;
	t_env	*prev;

	curr = env;
	prev = NULL;
	while (curr != NULL)
	{
		if (ft_strncmp(argv, curr->key, ft_strlen(argv)) == 0
			&& ft_strlen(curr->key) == ft_strlen(argv))
		{
			if (prev == NULL)
			{
				env = curr->next;
			}
			else
			{
				prev->next = curr->next;
			}
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

void	ft_env(t_env *env)
{
	t_env	*curr;

	curr = env;
	while (curr != NULL)
	{
		if (curr->value != NULL)
			printf("%s\n", curr->value);
		curr = curr->next;
	}
}

int	check_key(char *key)
{
	int	i;

	i = 0;
	if (isalpha(key[i]) != 1 && key[0] != '_')
	{
		return (0);
	}
	while (key[i] != '\0')
	{
		if (isalnum(key[i]) != 1 || key[i] == '_')
			return (0);
		i++;
	}
	return (1);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i] != '\0')
			i++;
		return (i);
	}
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > i)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

t_env	*get_env_copy(t_env *env)
{
	t_env	*curr;
	t_env	*env_cpy;
	t_env	*prev;
	t_env	*new_node;

	if (env == NULL)
		return (NULL);
	curr = env;
	env_cpy = NULL;
	prev = NULL;
	while (curr != NULL)
	{
		new_node = malloc(sizeof(t_env));
		if (new_node == NULL)
		{
			return (NULL);
		}
		new_node->key = NULL;
		new_node->value = malloc(ft_strlen(curr->value) + 1);
		if (new_node->value == NULL)
		{
			free(new_node->value);
			free(new_node);
			return (NULL);
		}
		ft_strlcpy(new_node->value, curr->value, ft_strlen(curr->value) + 1);
		if (env_cpy == NULL)
		{
			env_cpy = new_node;
		}
		else
		{
			prev->next = new_node;
		}
		prev = new_node;
		curr = curr->next;
	}
	return (env_cpy);
}

void	sort_env_cpy(t_env *env_cpy)
{
	t_env	*curr;
	char	*temp;

	if (env_cpy == NULL || env_cpy->next == NULL)
		return ;
	curr = env_cpy;
	while (curr->next != NULL)
	{
		if (ft_strncmp(curr->value, curr->next->value, ft_strlen(curr->value)
				+ 1) > 0)
		{
			temp = curr->value;
			curr->value = curr->next->value;
			curr->next->value = temp;
			curr = env_cpy;
		}
		else
			curr = curr->next;
	}
}

void	export_no_args(t_env *env)
{
	t_env	*env_cpy;
	t_env	*prev;

	env_cpy = get_env_copy(env);
	sort_env_cpy(env_cpy);
	prev = NULL;
	while (env_cpy != NULL)
	{
		if (prev != NULL)
		{
			free(prev->value);
			free(prev);
		}
		printf("declare -x \"%s\"\n", env_cpy->value);
		prev = env_cpy;
		env_cpy = env_cpy->next;
	}
	free(prev->value);
	free(prev);
}


void	export(char *argv, t_env *env)
{
	char	*key;
	t_env	*prev;
	t_env	*curr;

	if (env == NULL)
		return ;
	if (argv == NULL)
	{
		export_no_args(env);
		return ;
	}
	key = get_key(argv);
	if (key == NULL)
		return ;
	prev = NULL;
	curr = env;
	while (curr != NULL)
	{
		if (ft_strncmp(argv, curr->key, ft_strlen(key)) == 0
			&& ft_strlen(curr->key) == ft_strlen(key))
		{
			free(curr->value);
			curr->value = NULL;
			free(key);
			curr->value = argv;
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
	if (curr == NULL && check_key(key) == 1 && argv[ft_strlen(key)] == '=')
	{
		env_add_back(prev, argv);
		free(argv);
	}
	free(key);
}

void	ft_free_env(t_env *env)
{
	t_env	*curr;
	t_env	*prev;

	prev = NULL;
	curr = env;
	while (curr != NULL)
	{
		if (prev != NULL)
		{
			free(prev->value);
			free(prev->key);
			free(prev);
		}
		prev = curr;
		curr = curr->next;
	}
	free(prev->value);
	free(prev->key);
	free(prev);
}

char	*extract(char *str)
{
	int		i;
	int		j;
	char	*val;

	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0' && str[i] != '=')
		i++;
	if (str[i] == '\0')
		return (NULL);
	i++;
	val = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (val == NULL)
		return (NULL);
	while (str[i + j] != '\0')
	{
		val[j] = str[i + j];
		j++;
	}
	val[j] = '\0';
	return (val);
}

char	*expander(char *key, t_env *env)
{
	t_env	*curr;

	if (env == NULL || key == NULL)
		return (NULL);
	curr = env;
	while (curr != NULL)
	{
		if (ft_strncmp(key, curr->key, ft_strlen(curr->key)) == 0
			&& ft_strlen(key) == ft_strlen(curr->key))
			return (extract(curr->value));
		curr = curr->next;
	}
	return (NULL);
}

void	exec_ls(void)
{
	int	pid;
		char *args[] = {"ls", NULL};

	pid = fork();
	if (pid < 0)
	{
		printf("ERROR PIPE\n");
	}
	if (pid == 0)
	{
		execve("/bin/ls", args, NULL);
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
}

void	ft_cd(t_env *env, char *dir)
{
	char	buffer_cwd[PATH_MAX];
	char	*temp;

	if (dir == NULL)
		dir = getenv("HOME");
	else if (dir[0] == '-' && dir[1] == '\0')
	{
		dir = expander("OLDPWD", env);
		if (dir == NULL)
			return ;
	}
	else if ((dir[0] == '~' && dir[1] == '\0'))
		dir = getenv("HOME");
	getcwd(buffer_cwd, PATH_MAX);
	temp = ft_strjoin("OLDPWD=", buffer_cwd);
	export(temp, env);
	if (chdir(dir) < 0)
		return ;
	getcwd(buffer_cwd, PATH_MAX);
	temp = ft_strjoin("PWD=", buffer_cwd);
	export(temp, env);
}

void	shell_lvl(t_env *env)
{
	int		shell_lvl_i;
	char	*shell_lvl_str;
	char	*shlvl;

	shell_lvl_i = 0;
	shell_lvl_str = NULL;
	shlvl = NULL;
	shell_lvl_str = expander("SHLVL", env);
	if (shell_lvl_str != NULL)
	{
		shell_lvl_i = ft_atoi(shell_lvl_str);
		free(shell_lvl_str);
	}
	else
		shell_lvl_i = 0;
	shell_lvl_i++;
	shlvl = ft_itoa(shell_lvl_i);
	export(ft_strjoin("SHLVL=", shlvl), env);
	free(shlvl);
}

void	ft_echo(char *str)
{
	printf("%s\n", str);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_env	*env;

	i = 0;
	env = init_struct_env(envp);
	ft_cd(env, "..");
	ft_env(env);
	ft_free_env(env);
	system("leaks a.out");
	return (0);
}
