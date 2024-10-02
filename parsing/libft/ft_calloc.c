/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:53:31 by vispinos          #+#    #+#             */
/*   Updated: 2024/05/18 22:08:20 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	sz;

	if (count < 1 || size < 1)
		return (malloc(0));
	if (size > __SIZE_MAX__ / count)
		return (NULL);
	sz = count * size;
	p = malloc(sz);
	if (!p)
		return (NULL);
	ft_bzero(p, (sz));
	return (p);
}
