/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:39:24 by svidot            #+#    #+#             */
/*   Updated: 2023/10/13 17:05:46 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <stdlib.h>

static char	**ft_assign_words(char const *s, char c,
								char **s_split, size_t n_words)
{
	char	*s_trim;
	char	*s2;
	char	*s_chr;

	s2 = ft_strdup(s);
	s_trim = NULL;
	s_chr = "a";
	//s2 = "a";
	char *s_trim_av = NULL;	
	int i = 0;
	while (s_chr)
	{//ft_putstr_fd("f\n",1);
		s_trim = ft_strtrim(s, &c);
		if (!s_trim)
			return (NULL);
		free(s_trim_av);
		s_chr = ft_strchr(s_trim, c);
		if (s_chr)
			*s_split = ft_substr(s_trim, 0, s_chr - s_trim);
		else
			*s_split = ft_substr(s_trim, 0, ft_strlen(s_trim));
		if (!*s_split)
			return (NULL);
		s_trim_av = s_trim;
		s = s_chr;
		s_split++;
		//free(s_trim);
	}
	//free(s_trim_av);
	free(s_trim);
	free(s2);
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
	if(!s)
		return (NULL);
	if (!*s)
	{
		s_split = (char **) malloc(sizeof (char *));
		*s_split = NULL;
		return (s_split);
	}
	
	char *s_trim_av = NULL;
	while (s1)
	{
		s_trim = ft_strtrim(s1, &c);
		if (!s_trim)
			return (NULL);
		free(s_trim_av);
		s1 = ft_strchr(s_trim, c);
		if(*s_trim)
			n_words++;
		s_trim_av = s_trim;
	}
	
	if (!n_words)
	{
		s_split = (char **) malloc(sizeof (char *) * (1));
		*s_split = NULL;
		free(s_trim);
		return (s_split);
	}
	//n_words = 4;
	free(s_trim);
	s_split = (char **) ft_calloc(n_words + 1, sizeof (char *));
	if (!s_split)
		return (NULL);
	//s_split[n_words] = NULL;
	return (ft_assign_words(s, c, s_split, n_words));
}


#include <stdio.h>

int	main(void)
{
	char	*s = "xxxsplitxxmoixlaxface";
	char	**split;
	int		i;
	printf("test\n");
	// split = (char **) ft_calloc(4 + 1, sizeof (char *));
	// ft_assign_words(s, 'x', split, 4);
	split = ft_split(s, 'x');
	i = 0;
	while (split[i])
		printf("%s\n", split[i++]);	
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	/*
	ft_split(s, 'x');
	printf("mysplit\n\n");
	i = 0;
	split = ft_split(s, 'x');
	while (split[i])
		printf("%s\n", split[i++]);	
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	*/

	
	return (0);
}