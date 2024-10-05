/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_join_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:59:55 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/05 13:05:20 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*pft_join_all(char *line, char *var_value, int i_save, int cut, t_state *state)
{
	char	*temp_str;
	char	*pre_line;
	char	*new_line;

	temp_str = pft_substr(line, 0, i_save, state);
	pre_line = pft_strjoin(temp_str, var_value, state);
	temp_str = pft_strdup(&line[i_save + cut], state);
	new_line = pft_strjoin(pre_line, temp_str, state);
	return (new_line);
}
