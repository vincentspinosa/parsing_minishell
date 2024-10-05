/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:03:47 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/05 16:00:32 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h" // will need to remove after code sync
#include "stdio.h"

#ifndef LEXICAL
# define LEXICAL
# define INFILE 1
# define HEREDOC 2
# define OUTFILE_TRUNCATE 3
# define OUTFILE_APPEND 4
# define PIPE 5
# define CMD 6
# define ARG 7
#endif

#ifndef QUOTES	
# define QUOTES
# define SQUOTE 39
# define DQUOTE 34
# define NOQUOTE_SEP 0
#endif

#ifndef TOKEN
# define TOKEN 
typedef struct s_token
{
	int		type;
	char	*content;
	int		is_special;
}			t_token;
#endif

#ifndef LIST
# define LIST 
typedef struct      s_list
{
    void            *content;
    struct s_list   *next;
}                   t_list;
#endif

//ONLY HERE FOR TESTING, USE REAL ONE FROM MAIN .H FILE AFTER
typedef struct s_state
{
	char	**env;
	int		exit_code;
	t_list	*gc;
}			t_state;

/*
libft with state
*/
char	*pft_strdup(const char *s1, t_state *state);
char	*pft_strjoin(char const *s1, char const *s2, t_state *state);
char	*pft_substr(char const *s, unsigned int start, size_t len, t_state *state);
char	*pft_itoa(int n, t_state *state);

/*
helpers.c
*/
int		array_len(t_token **array);
int		main_array_len(t_token ***array);
int		ft_is_space(char c);
void	set_quotes_mode(int *sq, int *dq, char c);

/*
pft_join_all.c
*/
char	*pft_join_all(char *line, char *var_value, int x[2], t_state *state);

/*
garbage_collector.c
*/
t_list	*new_gc(void);
void	*ft_malloc(size_t size, t_list **gc, t_state *s);
void	destroy_gc(t_list *gc);

/*
make_token_and_append.c
*/
t_token	**make_token_and_append(int type, char *str, t_token **array, t_state *s);
t_token	**make_str_and_append_array(char *line, int i, t_token **array, char sep, t_state *s);

/*
parsing_main.c
*/
int		find_word_len(char *line, int i);
t_token	***parseline(t_state *s, char *line);

/*
replace_vars.c
*/
char	*replace_vars(char *str, t_state *s);

/*
split_array_tokens.c
*/
t_token ***ft_split_array_tokens(t_token **t_a, int type, t_state *s);

//////////////////////////////////
//    TO BIN :
//////////////////////////////////
void	print_token(t_token *token);
void	print_array(t_token **array);
void	print_main_array(t_token ***main_array);
