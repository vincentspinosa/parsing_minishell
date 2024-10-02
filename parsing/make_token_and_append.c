/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_token_and_append.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 00:38:00 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/02 19:04:03 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../minishell.h" // decomment after code sync
#include "parsing.h"

static t_token	*make_token(int type, char *str, t_state *s)
{
	t_token	*token;

	token = malloc(sizeof(t_token));//ft_malloc(sizeof(t_token), &(s->gc));
	if (!token)
		return (s->exit_code = 1, NULL);
	token->type = type;
	token->content = str;
	if (token->type == CMD || token->type == ARG)
		token->is_special = 0;
	else
		token->is_special = 1;
	return (token);
}

static t_token	**append_array(t_token *token, t_token **array, t_state *s)
{
	t_token	**new_array;
	int		len;
	int		i;

	//printf("Appending to array\n");
	len = array_len(array);
	//printf("Array len: %i\n", len);
	new_array = malloc(sizeof(t_token *) * (len + 2));//ft_malloc(sizeof(t_token *) * (len + 2), &(s->gc));// 1 for null, 1 for new token
	if (!new_array)
		return (s->exit_code = 1, NULL);
	i = 0;
	while (i < len)
	{
		new_array[i] = &(*(array[i]));
		i++;
	}
	new_array[i] = &(*(token));
	//printf("Printing new token appended:\n");
	//print_token(new_array[i]);
	new_array[i + 1] = NULL;
	//printf("Arren len of new array: %i\n", array_len(new_array));
	return (new_array);
}

t_token	**make_token_and_append(int type, char *str, t_token **array, t_state *s)
{
	t_token *token;
	t_token	**token_array;

	token = make_token(type, str, s);
	if (!token)
		return (s->exit_code = 1, NULL);
	//printf("New token made\n");
	//print_token(token);
	token_array = append_array(token, array, s);
	//printf("Len of array in make token and append, after appending: %i\n", array_len(token_array));
	return (token_array);
}

static int	cmd_present(t_token **array)
{
	int	i;
	int start;

	if (array_len(array) == 0)
		return (0);
	start = array_len(array) - 1;
	i = start;
	while (i >= 0)
	{
		if (array[i]->type == CMD)
			return (1);
		if (array[i]->type == PIPE)
			return (0);
		i--;
	}
	return (0);
}

static int	is_cmd(t_token **array)
{

	if (array_len(array) == 0 || array[array_len(array) - 1]->type == PIPE
		|| (cmd_present(array) == 0 && array_len(array) > 1 
		&& array[array_len(array) - 1]->type == ARG 
		&& (array[array_len(array) - 2]->is_special == 1 
		&& array[array_len(array) - 2]->type != PIPE)))
		return (1);
	else
		return (0);
}

t_token	**make_str_and_append_array(char *line, int i, t_token **array, char sep, t_state *s)
{
	char	*str;
	int		len;
	int		type;

	len = 0;
	if (sep == NOQUOTE_SEP)
		len = find_word_len(line, i);
	else
	{
		i++;
		while (line[i + len] && line[i + len] != sep)
			len++;
	}
	//printf("Len: %i\n", len);
	str = malloc(sizeof(char) * (len + 1));//ft_malloc(sizeof(char) * (len + 1), &(s->gc));
	if (!str)
		return (s->exit_code = 1, NULL);
	ft_strlcpy(str, &line[i], (len + 1));
	if (is_cmd(array) == 1)
		type = CMD;
	else
		type = ARG;
	return (make_token_and_append(type, str, array, s));
}
