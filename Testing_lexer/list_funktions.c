/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funktions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:48:06 by psanger           #+#    #+#             */
/*   Updated: 2024/03/27 14:49:57 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"


t_minishell *create_list(void)
{
	t_minishell *root;
	root = malloc(sizeof(t_minishell) * 1);
	if (root == NULL)
		return (NULL);
	root->next = NULL;
}

t_minishell *add_list_back(t_minishell *list)
{
	if (list == NULL)
		return (NULL);
	t_minishell *curr;
	t_minishell *new_node;

	new_node = malloc(sizeof(t_minishell) * 1);
	if (new_node == NULL)
		return (NULL);
	new_node->next = NULL;
	curr = list;
	while (curr != NULL)
		curr = curr->next;
	curr = new_node;
	return (new_node);
}
