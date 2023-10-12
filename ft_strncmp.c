/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 08:47:35 by svidot            #+#    #+#             */
/*   Updated: 2023/10/03 13:54:47 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 && n) || (*s2 && n))
	{
		if (*s1++ != *s2++)
			break ;
		n--;
	}
	return ((unsigned char) *--s1 - (unsigned char) *--s2);
}
