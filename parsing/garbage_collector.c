/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:45:34 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/04 17:32:20 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../minishell.h" // decomment after code sync
#include "parsing.h"

t_list	*new_gc(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = NULL;
	return (list);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*ptr;

	ptr = *alst;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = new;
}

void	*ft_malloc(size_t size, t_list **gc)
{
	void	*space;
	t_list	*lst_elem;

	space = malloc(size);
	if (!space)
		return (NULL);
	lst_elem = malloc(sizeof(t_list));
	if (!lst_elem)
		return (free(space), NULL);
	lst_elem->content = space;
	//ft_lstadd_back(gc, lst_elem);
	if (gc)
		return (space);
	return (space);
}

void	destroy_gc(t_list **gc)
{
	t_list	*temp;

	while (*gc)
	{
		temp = (*gc)->next;
		if ((*gc)->content)
		{
			free((*gc)->content);
			(*gc)->content = NULL;
		}
		free(*gc);
		*gc = temp;
	}
}
