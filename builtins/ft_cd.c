/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:38:02 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/08 16:27:03 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_cd(char **array, t_state *s)
{
	char	*str;

	if (array && array[1])
		str = array[1];
	else
		str = NULL;
	if (chdir(str) != 0)
	{
		// voir si Théo veut + pousser la gestion des erreurs
		ft_putstr_fd("error: cd: cannot change directory to ", 2);
		ft_putendl_fd(array[1], 2);
		return (1)
	}
	return (ft_export_key_value("OLDPWD", get_var_value("PWD", s->env, 3, s))
		|| ft_export_key_value("PWD", ft_pwd(s)));
}
