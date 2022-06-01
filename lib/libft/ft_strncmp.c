/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:59:40 by bde-meij          #+#    #+#             */
/*   Updated: 2022/05/30 14:59:41 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	retval;
	size_t	index;

	retval = 0;
	index = 0;
	while ((index < n) && (s1[index] || s2[index]))
	{
		retval = ((unsigned char) s1[index] - (unsigned char) s2[index]);
		index++;
		if (retval != 0)
			return (retval);
	}
	return (retval);
}