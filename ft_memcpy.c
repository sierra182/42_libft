/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 09:55:31 by svidot            #+#    #+#             */
/*   Updated: 2023/10/09 08:33:48 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_uc;
	unsigned char		*dest_uc;

	src_uc = (const unsigned char *) src;
	dest_uc = (unsigned char *) dest;
	while (n--)
		*dest_uc++ = *src_uc++;
	return (dest);
}
