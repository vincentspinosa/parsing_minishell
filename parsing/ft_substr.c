/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:55:25 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/05 00:06:05 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*ft_substr(char const *s, unsigned int start, size_t len, t_state *state)
{
	char	*str;
	size_t	i;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		start = slen;
	i = 0;
	while (*(s + start + i) && i < len)
		i++;
	str = ft_malloc(sizeof(char) * (i + 1), &(state->gc), state);
	if (!str)
		return (NULL);
	i = 0;
	while (*(s + start + i) && i < len)
	{
		*(str + i) = *(s + start + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
