/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:59:55 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/04 23:44:09 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../minishell.h" // decomment after code sync
#include "parsing.h"

char	*ft_join_all(char *line, char *var_value, int i_save, int cut, t_state *state)
{
	char	*temp_str;
	char	*pre_line;
	char	*new_line;

	temp_str = ft_substr(line, 0, i_save, state);
	pre_line = ft_strjoin(temp_str, var_value, state);
	temp_str = ft_strdup(&line[i_save + cut], state);
	new_line = ft_strjoin(pre_line, temp_str, state);
	return (new_line);
}
