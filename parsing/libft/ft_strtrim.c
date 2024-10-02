/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:55:20 by vispinos          #+#    #+#             */
/*   Updated: 2024/05/16 12:55:23 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	while (*(set))
	{
		if (*(set) == c)
			return (1);
		else
			set++;
	}
	return (0);
}

static int	get_len(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = ft_strlen(s1) - 1;
	k = 0;
	while (*(s1 + i) && in_set(*(s1 + i), set) == 1)
		i++;
	if (!*(s1 + i))
		return (ft_strlen(s1) - i);
	while (j > -1 && in_set(*(s1 + j), set) == 1)
	{
		j--;
		k++;
	}
	return (ft_strlen(s1) - i - k);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = get_len(s1, set);
	s2 = malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	while (*(s1 + i) && in_set(*(s1 + i), set) == 1)
		i++;
	while (*(s1 + i + j) && j < len)
	{
		*(s2 + j) = *(s1 + i + j);
		j++;
	}
	*(s2 + j) = '\0';
	return (s2);
}
