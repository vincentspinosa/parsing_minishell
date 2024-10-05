/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:45:34 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/05 12:56:15 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_list	*new_gc(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = NULL;
	list->next = NULL;
	return (list);
}

void	*ft_malloc(size_t size, t_list **gc, t_state *s)
{
	t_list	*lst_elem;

	lst_elem = malloc(sizeof(t_list));
	if (!lst_elem)
		return (s->exit_code = 1, NULL);
	lst_elem->content = malloc(size);
	if (!lst_elem->content)
		return (s->exit_code = 1, free(lst_elem), NULL);
	lst_elem->next = *gc;
	*gc = lst_elem;
	return (lst_elem->content);
}

void	destroy_gc(t_list *gc)
{
	if (!gc)
		return ;
	destroy_gc(gc->next);
	free(gc->content);
	free(gc);
}
