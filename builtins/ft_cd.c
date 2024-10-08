/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:38:02 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/08 23:50:04 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_export_key_value(char *str1, char *str2, t_state *s)
{
	char *str;
	char **array;

	str = pft_strjoin(str1, "=", s);
	if (!str)
		return (1);
	str = pft_strjoin(str, str2, s);
	if (!str)
		return (1);
	array = make_char_s_arr_from_str(str, s);
	if (!array)
		return (1);
	return (ft_export(array, s));
}

int	ft_cd(char **array, t_state *s)
{
	char	*dest;
	char	absolute_dest[PATH_MAX];

	if (array && array[1])
		dest = array[1];
	else
		dest = NULL;
	if (chdir(dest) != 0)
	{
		// voir si Théo veut + pousser la gestion des erreurs
		ft_putstr_fd("error: cd: cannot change directory to ", 2);
		ft_putendl_fd(array[1], 2);
		return (1);
	}
	if (getcwd(absolute_dest, PATH_MAX))
		if (ft_export_key_value("OLDPWD", get_var_value("PWD", s->env, 3, s), s)
			&& ft_export_key_value("PWD", absolute_dest, s))
			return (0);
	return (1);
}

/* int	main(void)
{
	return (0);
} */
