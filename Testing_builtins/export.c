/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:15:51 by psanger           #+#    #+#             */
/*   Updated: 2024/04/16 15:54:59 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

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
	if (env == NULL)
		return (NULL);
	t_env *curr = env;
	t_env *env_cpy;
	t_env *prev = NULL;
	while (curr != NULL) {
		env_cpy = malloc(sizeof(t_env));
		env_cpy->key = NULL;
		env_cpy->next = NULL;
		env_cpy->value = malloc(sizeof(curr->value));
		ft_strlcpy(env_cpy->key, curr->value, ft_strlen(curr->value));
		curr = curr->next;
	}

}

t_env *get_env_copy(t_env *env)
{
	if (env == NULL)
		return NULL;

	t_env *curr = env;
	t_env *env_cpy = NULL;
	t_env *prev = NULL;

	while (curr != NULL) {
		t_env *new_node = malloc(sizeof(t_env));
		if (new_node == NULL) {
			return (NULL);
		}
		new_node->key = NULL;
		new_node->value = malloc(ft_strlen(curr->value) + 1);
		if (new_node->value == NULL) {
			free(new_node->value);
			free(new_node);
			return (NULL);
		}
		ft_strlcpy(new_node->value, curr->value, ft_strlen(curr->value));
		if (env_cpy == NULL) {
			env_cpy = new_node;
		} else {
			prev->next = new_node;
		}
		prev = new_node;
		curr = curr->next;
	}
	return (env_cpy);
}

void	sort_env_copy(t_env *env_cpy)
{
	if (env_cpy == NULL || env_cpy->next == NULL)
		return;
	t_env *curr = env_cpy;
	t_env *start = env_cpy;
	char *temp;
	while (curr->next != NULL)
	{
		if (ft_strncmp(curr->value, curr->next->value, 100) > 0) {
			temp = curr->value;
			curr->value = curr->next->value;
			curr->next->value = temp;
			curr = start;
		}
		curr = curr->next;
	}
}

void	export_no_args(t_env *env)
{
	t_env *env_cpy;

	env_cpy = NULL;
	env_cpy = get_env_copy(env);
	sort_env_cpy(env_cpy);
	t_env *prev = NULL;
	while (env_cpy != NULL)
	{
		if (prev != NULL) {
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
	if (env == NULL)
		return ;
	if (argv == NULL) {
		export_no_args(env);
		return ;
	}
	char *key = get_key(argv);
	if (key == NULL)
		return ;
	t_env *prev = NULL;
	t_env *curr = env;
	while (curr != NULL) {
		if (ft_strncmp(argv, curr->key, ft_strlen(key)) == 0
			&& ft_strlen(curr->key) == ft_strlen(key)) {
			curr->value = argv;
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
	if (curr == NULL && check_key(key) == 1
		&& argv[ft_strlen(key)] == '=' && argv[ft_strlen(key) + 1] != '\0') {
		env_add_back(prev, argv);
	}
}
