/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:53:59 by vispinos          #+#    #+#             */
/*   Updated: 2024/05/18 17:23:20 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	size_t			i;

	s2 = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char) c == *(s2 + i))
			return ((void *)(s2 + i));
		i++;
	}
	return (NULL);
}
