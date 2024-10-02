/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:54:55 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/02 18:21:21 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*to_return;
	int		i;
	int		j;
	int		malloc_size;

	malloc_size = ft_strlen((char *) s1) + ft_strlen((char *) s2) + 1;
	to_return = malloc(sizeof(char) * malloc_size);
	if (!to_return)
		return (NULL);
	i = 0;
	while (s1 && *(s1 + i))
	{
		*(to_return + i) = *(s1 + i);
		i++;
	}
	j = 0;
	while (s2 && *(s2 + j))
	{
		*(to_return + i + j) = *(s2 + j);
		j++;
	}
	*(to_return + i + j) = '\0';
	return (to_return);
}
