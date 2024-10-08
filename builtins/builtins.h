/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:57:29 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/08 15:09:59 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULTINS_H
# define BUILTINS_H

# include "../parsing/parsing.h"

int	ft_cd(char **array, t_state *s);
int	ft_echo(char **array);
int	ft_env(char **env);
int	ft_pwd(t_state *s);

/* ft_unset.c */
int	char_star_array_len(char **array);
int	is_present(char *env_elem, char **vars);
int	ft_unset(char **vars, t_state *s);

#endif
