/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:55:13 by vispinos          #+#    #+#             */
/*   Updated: 2024/05/18 16:28:57 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (ft_strlen((char *) needle) == 0)
		return ((char *) haystack);
	i = 0;
	while (*(haystack + i) && i < len)
	{
		j = 0;
		if (*(haystack + i) == *(needle))
		{
			while (*(needle + j) && *(needle + j) == *(haystack + i + j)
				&& (i + j) < len)
				j++;
			if (!*(needle + j))
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
