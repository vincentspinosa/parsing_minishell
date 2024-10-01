/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:55:06 by vispinos          #+#    #+#             */
/*   Updated: 2024/05/16 12:55:07 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dst;
	unsigned int	i;

	dst = ft_strdup(s);
	i = 0;
	while (*(dst + i))
	{
		*(dst + i) = (*f)(i, *(dst + i));
		i++;
	}
	return (dst);
}
