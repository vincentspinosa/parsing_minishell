/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 08:39:55 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/07 17:56:58 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_echo(char **array)
{
	int	i;
	int	add_endline;

	add_endline = 1;
	if (ft_strncmp(array[1], "-n", 2) == 0)
		add_endline = 0;
	i = 2 - add_endline;
	while (array[i])
	{
		if (ft_strlen(array[i]) != 0)
			ft_putstr_fd(array[i], 1);
		if (array[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (add_endline != 0)
		ft_putchar_fd('\n', 1);
	return (0);
}
