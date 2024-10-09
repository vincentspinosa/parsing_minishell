/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:35:51 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/09 13:36:51 by vispinos         ###   ########.fr       */
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

static void	check_regex(char **vars, t_state *s)
{
	int	i;

	i = 0;
	while (vars[i])
	{
		if (unvalid_regex(vars[i]))
		{
			ft_putstr_fd("bash: export: '", 2);
			ft_putstr_fd(vars[i], 2);
			ft_putendl_fd("': not a valid identifier", 2);
			s->exit_code = 1;
		}
		i++;
	}
}

int	ft_unset(char **vars, t_state *s)
{
	char	**new_env;
	int		len;
	int		i;
	int		j;

	if (!vars || !s->env)
		return (0);
	check_regex(vars, s);
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
	unset_param = malloc(sizeof(char *));
	//unset_param = NULL;
	//unset_param = make_char_s_arr_from_str("", s);
	unset_param = make_char_s_arr_from_str("_", s);
	unset_param = append_char_star(unset_param, "GOPATH", s);
	unset_param = append_char_star(unset_param, "OLDPWD", s);
	unset_param = append_char_star(unset_param, "&BAD", s);
	unset_param = append_char_star(unset_param, "1BAD", s);
	unset_param = append_char_star(unset_param, "Ba-d", s);
	unset_param = append_char_star(unset_param, "TERM_PROGRAM", s);
	unset_param = append_char_star(unset_param, "PWD", s);
	ft_unset(unset_param, s);
	ft_export_zero(s);
	if (ac || av)
		return (0);
} */
