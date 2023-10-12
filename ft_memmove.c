/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:20:36 by svidot            #+#    #+#             */
/*   Updated: 2023/10/09 08:33:37 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_uc;
	unsigned char		*dest_uc;

	src_uc = (const unsigned char *) src;
	dest_uc = (unsigned char *) dest;
	if (src >= dest)
		while (n--)
			*dest_uc++ = *src_uc++;
	else
		while (n--)
			dest_uc[n] = src_uc[n];
	return (dest);
}
