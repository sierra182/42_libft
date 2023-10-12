/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 09:28:19 by svidot            #+#    #+#             */
/*   Updated: 2023/10/12 10:16:52 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;	
	size_t	little_len;

	if (!*little)
		return ((char *) big);
	little_len = ft_strlen(little);
	while (*big && len)
	{
		if (*big == *little)
		{
			i = 0;
			while (big[i] && big[i] == little[i] && len - i)
				i++;
			if (i == little_len)
				return ((char *) big);
		}
		big++;
		len--;
	}
	return (NULL);
}
