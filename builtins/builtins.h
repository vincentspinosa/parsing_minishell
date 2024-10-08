/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:57:29 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/08 23:50:59 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULTINS_H
# define BUILTINS_H

# include <limits.h>
# include "../parsing/parsing.h"

int 	ft_echo(char **array);
int	    ft_env(char **env);
int	    ft_exit(char **array, t_state *s);
int	    ft_pwd(t_state *s);

/* ft_cd.c */
int	    ft_cd(char **array, t_state *s);
int	    ft_export_key_value(char *str1, char *str2, t_state *s);

/* ft_export.c */
int 	ft_export_zero(t_state *s);
char	**append_char_star(char **array, char *str, t_state *s);
int	    ft_export(char **vars, t_state *s);

/* ft_export_helpers.c */
char	**char_star_array_sort(char **array, t_state *s);
char	**make_char_s_arr_from_str(char *str, t_state *s);

/* ft_unset.c */
int	    char_star_array_len(char **array);
int	    is_present(char *env_elem, char **vars);
int	    ft_unset(char **vars, t_state *s);

#endif
