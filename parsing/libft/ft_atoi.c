/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:53:18 by vispinos          #+#    #+#             */
/*   Updated: 2024/05/19 01:12:24 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	sign;
	long	nb;
	long	i;

	sign = 1;
	i = 0;
	nb = 0;
	while (*(str + i) == ' ' || *(str + i) <= 13)
		i++;
	if (*(str + i) == '-' || *(str + i) == '+')
	{
		if (*(str + i) == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(*(str + i)))
	{
		if (nb > 0)
			nb *= 10;
		nb += (*(str + i) - '0');
		i++;
	}
	return (nb * sign);
}
