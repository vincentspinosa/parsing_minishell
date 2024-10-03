/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:59:55 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/03 03:11:32 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../minishell.h" // decomment after code sync
#include "parsing.h"

char	*ft_join_all(char *line, char *var_value, int i_save, int cut)
{
	char	*temp_str;
	char	*pre_line;
	char	*new_line;

	temp_str = ft_substr(line, 0, i_save);
	pre_line = ft_strjoin(temp_str, var_value);
	if (temp_str)
		free(temp_str);
	temp_str = ft_strdup(&line[i_save + cut]);
	new_line = ft_strjoin(pre_line, temp_str);
	if (pre_line)
		free(pre_line);
	if (temp_str)
		free(temp_str);
	return (new_line);
}
