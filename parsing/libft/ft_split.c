/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:54:37 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/01 14:22:48 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_words(char const *s, char c)
{
	int	nb;
	int	mode;

	nb = 0;
	mode = 1;
	while (*(s))
	{
		if (mode == 1)
		{
			if (*(s) != c)
			{
				mode = 0;
				nb++;
			}
		}
		else
		{
			if (*(s) == c)
			{
				mode = 1;
			}
		}
		s++;
	}
	return (nb);
}

static char	*make_word(char const *s, char c)
{
	int		len;
	char	*word;
	int		i;

	len = 0;
	while (*(s + len) && *(s + len) != c)
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(word + i) = *(s + i);
		i++;
	}
	*(word + i) = '\0';
	return (word);
}

static void	free_all(char **array, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;

	array = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!array || !s)
		return (NULL);
	i = 0;
	while (*(s))
	{
		while (*(s) && *(s) == c)
			s++;
		if (*(s) && *(s) != c)
		{
			*(array + i) = make_word(s, c);
			if (*(array + i) == NULL)
			{
				free_all(array, i);
				return (NULL);
			}
			s += ft_strlen(*(array + i));
			i++;
		}
	}
	*(array + i) = NULL;
	return (array);
}
