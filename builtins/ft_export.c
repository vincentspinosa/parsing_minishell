/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:41:57 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/08 17:09:05 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_export_key_value(char *str1, char *str2, t_state *s)
{
	char *str;
	char **array;

	str = pft_strjoin(str1, "=");
	if (!str)
		return (1);
	str = pft_strjoin(str, str2);
	if (!str)
		return (1);
	array = make_char_s_arr_from_str(str, s);
	if (!array)
		return (1);
	return (ft_export(array));
}

int	ft_export_zero(t_state *s)
{
	char	**temp_env;
	int		i;

	temp_env = char_star_array_sort(s->env, s);
	if (!temp_env || !*temp_env)
		return (1);
	i = 0;
	while (temp_env[i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putendl_fd(temp_env[i], 1);
		i++;
	}
	return (0);
}

static int unvalid_regex(char *str)
{
	int	i;

	i = 0;
	while(str[i] && (str[i] != '=' || i == 0))
	{
		if (!is_regex(str[i], i))
			return (1);
		i++;
	}
	return (0);
}

char	**append_char_star(char **array, char *str, t_state *s)
{
	int		len;
	int		i;
	char	**new_array;

	len = char_star_array_len(array);
	new_array = ft_malloc(sizeof(char *) * (len + 2), &(s->gc), s);
	if (!new_array)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_array[i] = array[i];
		i++;
	}
	new_array[i] = str;
	new_array[i + 1] = NULL;
	return (new_array);
}

int	ft_export(char **vars, t_state *s)
{
	int	len;
	int	i;

	len = char_star_array_len(array);
	if (len == 0)
		return (export_zero(t_state *s));
	i = 0;
	while (i < len)
	{
		if (unvalid_regex(vars[i]))
		{
			ft_putstr_fd("bash: export: '", 2);
			ft_putstr_fd(vars[i], 2);
			ft_putendl_fd("': not a valid identifier", 2);
			s->exit_code = 1;
			continue;
		}
		ft_unset(make_char_s_arr_from_str(vars[i]), s);
		s->env = append_char_star(s->env, vars[i]);
		if (!s->env)
			return (NULL);
		i++;
	}
	return (0);
}
