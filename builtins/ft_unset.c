/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:35:51 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/08 21:04:42 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	char_star_array_len(char **array)
{
	int	i;

	if (!array)
		return (0);
	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	is_present(char *env_elem, char **vars)
{
	int	i;

	if (!vars)
		return (0);
	i = 0;
	while (vars[i])
	{
		if (!ft_strncmp(env_elem, vars[i], ft_strlen(vars[i]))
			&& (!env_elem[ft_strlen(vars[i])]
				|| env_elem[ft_strlen(vars[i])] == '='))
			return (1);
		i++;
	}
	return (0);
}

int	ft_unset(char **vars, t_state *s)
{
	char	**new_env;
	int		len;
	int		i;
	int		j;

	if (!vars || !s->env)
		return (0);
	len = char_star_array_len(s->env);
	new_env = ft_malloc(sizeof(char *) * (len + 1), &(s->gc), s);
	if (!new_env)
		return (1);
	i = 0;
	j = 0;
	while (s->env[i])
	{
		if (!is_present(s->env[i], vars))
		{
			new_env[j] = s->env[i];
			j++;
		}
		i++;
	}
	new_env[j] = NULL;
	s->env = new_env;
	return (0);
}

/* int	main(int ac, char **av, char **envp)
{
	t_state	*s;
	char	**unset_param;

	s = malloc(sizeof(t_state));
	s->exit_code = 999;
	s->env = envp;
	ft_env(s->env);
	unset_param = malloc(sizeof(char *));
	unset_param = make_char_s_arr_from_str("_", s);
	unset_param = append_char_star(unset_param, "GOPATH", s);
	unset_param = append_char_star(unset_param, "OLDPWD", s);
	unset_param = append_char_star(unset_param, "TERM_PROGRAM", s);
	ft_unset(unset_param, s);
	ft_env(s->env);
	if (ac || av)
		return (0);
} */
