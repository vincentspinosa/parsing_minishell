/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:03:49 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/09 14:16:18 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	len_one(void)
{
	ft_putendl_fd("exit", 1);
	// exec ;
	return (0);
}

static int	not_num(t_state *s)
{
	ft_putendl_fd("exit\nminishell: exit: numeric argument required", 2);
	s->exit_code = 2;
	// exec ;
	return (1);
}

static int	too_many_args(t_state *s)
{
	ft_putendl_fd("exit\nminishell: exit: too many arguments", 2);
	s->exit_code = 1;
	// exec ;
	return (1);
}

static int	isnum(char *str)
{
	int	i;

	i = 0;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i])
		return (0);
	return (1);
}

int	ft_exit(char **array, t_state *s)
{
	int	len;

	len = sal(array);
	if (len == 1)
		return (len_one());
	else if (!isnum(array[1]))
		return (not_num(s));
	else if (len > 2)
		return (too_many_args(s));
	s->exit_code = ft_atoi(array[1]) % 256;
	if (s->exit_code < 0)
		s->exit_code += 256;
	ft_putendl_fd("exit", 1);
	// exec ;
	return (0);
}

/* int	main(int ac, char **av)
{
	t_state	*s;

	s = malloc(sizeof(t_state));
	if (!s)
		return (1);
	s->exit_code = 999;
	ft_exit(av, s);
	printf("Exit return code : %i\n", s->exit_code);
	if (ac)
		return (0);
} */
