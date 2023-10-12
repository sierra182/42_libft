/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:39:24 by svidot            #+#    #+#             */
/*   Updated: 2023/10/12 14:15:00 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**ft_assign_words(char const *s, char c,
								char **s_split, size_t n_words)
{
	char	*s_trim;

	s_trim = NULL;
	while (s)
	{
		s_trim = ft_strtrim(s, &c);
		if (!s_trim)
			return (NULL);
		s = ft_strchr(s_trim, c);
		if (s)
			*s_split = ft_substr(s_trim, 0, s - s_trim);
		else
			*s_split = ft_substr(s_trim, 0, ft_strlen(s_trim));
		if (!*s_split)
			return (NULL);
		s_split++;
	}
	return (s_split - n_words);
}

char	**ft_split(char const *s, char c)
{
	char		**s_split;
	char		*s_trim;
	char const	*s1;
	size_t			n_words;

	s1 = s;
	n_words = 0;	
	while (s1)
	{
		s_trim = ft_strtrim(s1, &c);
		if (!s_trim)
			return (NULL);
		s1 = ft_strchr(s_trim, c);
		n_words++;
	}
	s_split = (char **) malloc(sizeof (char *) * (n_words + 1));
	if (!s_split)
		return (NULL);
	s_split[n_words] = NULL;
	return (ft_assign_words(s, c, s_split, n_words));
}
