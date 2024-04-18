/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:22:23 by psanger           #+#    #+#             */
/*   Updated: 2024/04/11 22:17:40 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
#define BUILTIN_H

# include "../exec_part/minishell.h"

typedef struct s_env
{
	char				*key;
	char				*value;
	struct s_env		*next;
}				t_env;


#endif
