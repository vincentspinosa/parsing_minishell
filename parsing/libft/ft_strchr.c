/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:54:41 by vispinos          #+#    #+#             */
/*   Updated: 2024/05/16 12:54:42 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char) c)
			return ((char *) s + i);
		else
			i++;
	}
	if (*(s + i) == (char) c)
		return ((char *) s + i);
	return (NULL);
}
