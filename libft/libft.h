/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:59:44 by bde-meij          #+#    #+#             */
/*   Updated: 2022/05/31 13:33:12 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h> //exit
# include <unistd.h> //write

int	ft_strncmp(const char *s1, const char *s2, int n);
size_t	ft_strlen(const char *string);
void	ft_putstr_fd(char *s, int fd);

#endif
