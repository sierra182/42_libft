/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:54:21 by svidot            #+#    #+#             */
/*   Updated: 2023/10/15 17:55:28 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
/*
static char	*ft_strndup(const char *s, size_t n)
{
	char	*s2;
	size_t	s_len;
	size_t	size;

	s_len = ft_strlen(s);
	if (n > s_len)
		size = s_len;
	else
		size = n;
	s2 = (char *) ft_calloc(size + 1, sizeof (char));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s, size + 1);
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		n_word;
	int		pass;
	int		n_letter;

	n_letter = 0;
	n_word = 0;
	while (s && s[n_letter])
	{
		pass = 0;
		while ((s[n_letter] && s[n_letter++] != c && ++pass) || (pass && n_word++ < 0))
			;
	}
	split = (char **) ft_calloc(n_word + 1, sizeof (char *));
	if (!split)
		return (NULL);		
	char **split_save = split;
	char **ss = split;
	while (*s)
	{
		n_letter = 0;
		while (s[n_letter] && s[n_letter] != c)
			n_letter++;
		if (n_letter)
		{
			*split = ft_strndup(s, n_letter);
			if (!*split)
			{
				while (*split_save)				
					free(*split_save++);					
				free(ss);
				return (NULL);
			}
			split++;
			s += n_letter - 1;			
		}	
		s++;	
	}
	return (split - n_word);
}
*/
/*
char	**ft_assin_word(char **split, int n_word, char const *s, char c)
{
	size_t	n_letter;
	int		i;	
	
	while (*s)
	{
		n_letter = 0;
		while (s[n_letter] && s[n_letter] != c)
			n_letter++;
		if (n_letter)
		{
			*split = (char *) ft_calloc((n_letter + 1), sizeof (char));	
			if (!*split++)
			{
				i = 0;
				while (split[i])
					free(split[i++]);
				free(split); 
				return (NULL);			
			}
		}
		i = 0;	
		while (n_letter--)
			(*(split - 1))[i++] = *s++;						
		if (i) 
			continue;
		s++;	
	}
	return (split - n_word);
}
*/

void	ft_free_split(char **split)
{
	int	i;
	
	i = 0; 
	while (split[i])
		free(split[i++]);
	free(split); 
}

char	**ft_assin_word(char **split, int n_word, char const *s, char c)
{
	char	**split2;
	size_t	n_letter;
	int		i;	
	
	split2 = split;
	while (*s)
	{
		n_letter = 0;
		while (s[n_letter] && s[n_letter] != c)
			n_letter++;
		if (n_letter)
		{
			*split++ = (char *) ft_calloc((n_letter + 1), sizeof (char));	
			if (!*(split - 1))
			{
				ft_free_split(split2);
				return (NULL);			
			}
		}
		i = 0;	
		while ((*s++ && n_letter--)||(i && !s--))
			(*(split - 1))[i++] = *(s - 1);
	}
	return (split - n_word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		n_word;
	int		pass;
	int		n_letter;

	n_letter = 0;
	n_word = 0;
	while (s && s[n_letter])
	{
		pass = 0;
		while ((s[n_letter] && s[n_letter++] != c && ++pass) || (pass && n_word++ < 0))
			;
	}
	split = (char **) ft_calloc(n_word + 1, sizeof (char *));
	if (!split)
		return (NULL);			
	return (ft_assin_word(split, n_word, s, c));
}


// #include <stdio.h>
// int main(void)
// {
// 	char	*s;
// 	char	**split;
// 	int		i;
	
// 	s = "xxsplitxxmoixlaxxxfacexx"; // 4
// 	split = ft_split(s, 'x');

// 	i = 0;
// 	while (split[i])
// 		printf("1 %s\n", split[i++]);	
// 	printf("\n");
	
// 	s = "splitxxmoixlaxxxfacexx"; //4
// 	split = NULL;
// 	split = ft_split(s, 'x');
	
// 	i = 0;
// 	while (split[i])
// 		printf("2 %s\n", split[i++]);
// 	printf("\n");
	
	
// 	s = "xxsplitxxmoixlaxxxface"; // 4 ! 9
// 	split = NULL;
// 	split = ft_split(s, 'x');
	
// 	i = 0;
// 	while (split[i])
// 		printf("3 %s\n", split[i++]);
// 	printf("\n");
	
	
// 	s = "splitxxmoixdoncxxlaxxxface"; // 4 ! 5
// 	split = NULL;
// 	split = ft_split(s, 'x');
	/*
	i = 0;
	while (split[i])
		printf("4 %s\n", split[i++]);
	printf("\n");
		
	s = "splitmoilafacexx"; // 1
	split = ft_split(s, 'x');
	
	i = 0;
	while (split[i])
		printf("5 %s\n", split[i++]);
	printf("\n");
		
	s = "xxsplitmoilaface"; // 1 ! 2
	split = ft_split(s, 'x');
	
	i = 0;		
	while (split[i])
		printf("6 %s\n", split[i++]);
	printf("\n");
		
	s = "splitmoilaface"; // 1
	split = ft_split(s, 'x');
	
	i = 0;
	while (split[i])
		printf("7 %s\n", split[i++]);
	printf("\n");
		
	s = ""; 
	split = ft_split(s, 'x'); // 0

	i = 0;
	while (split[i])
		printf("8 %s\n", split[i++]);
	printf("\n");
		
	s = "splitmoilaface"; // 1
	split = ft_split(s, 'x');

	i = 0;
	while (split[i])
		printf("9 %s\n", split[i++]);
	printf("\n");
	
	s = "splitmoilaface"; // 1
	split = ft_split(s, 'y');

	i = 0;
	while (split[i])
		printf("10 %s\n", split[i++]);
	printf("\n");
	
	s = "splitmoilaface"; // 1
	split = ft_split(s, '\0');

	i = 0;
	while (split[i])
		printf("11 %s\n", split[i++]);
	printf("\n");
	
	s = "xxxxxxx";     // 0
	split =ft_split(s, 'x');
	
	i = 0;
	while (split[i])
		printf("12 %s\n", split[i++]);
	printf("\n");
	
	s = "x";     // 0
	split = ft_split(s, 'x');
	
	i = 0;
	while (split[i])
		printf("13 %s\n", split[i++]);
	printf("\n");
	
	s = "u";     // 1
	split = ft_split(s, 'x');

	i = 0;
	while (split[i])
		printf("14 %s\n", split[i++]);
	printf("\n");
	
	return (0);	
}
	*/
/*
char	**ft_split(char const *s, char c)
{
	char	**split;
	int		n_word;
	int		pass;
	char const *s2;

	s2 = s;
	n_word = 0;
	while (s && *s)
	{
		pass = 0;
		while ((*s && *s++ != c && ++pass) || (pass && n_word++ < 0))
			;
	}
	split = (char **) ft_calloc(n_word + 1, sizeof (char *));
	//if (!split)
	//	return (NULL);
	
	int	n_letter;
	while (*s2)
	{
		n_letter = 0;
		while (s2[n_letter] && s2[n_letter] != c)
			n_letter++;
		if (n_letter)
		{
			*split = (char *) malloc((n_letter + 1) * sizeof (char));	
			//if (!*split)
			//	return (NULL);		
			(*split)[n_letter] = '\0';
			split++;	
		}	
		int d = n_letter;	
		while (n_letter--)
			(*(split - 1))[n_letter] = s2[n_letter];		
		if (d)
			d--;
		s2 = s2 + 1 + d;
	//s++;	
	}
	return (split - n_word);
}
*/



