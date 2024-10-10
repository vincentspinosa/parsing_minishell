/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:55:17 by vispinos          #+#    #+#             */
/*   Updated: 2024/05/16 12:55:18 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*occ;

	i = 0;
	occ = NULL;
	while (*(s + i))
	{
		if (*(s + i) == (char) c)
			occ = (char *) s + i;
		i++;
	}
	if (*(s + i) == (char) c)
		occ = (char *) s + i;
	return (occ);
}
