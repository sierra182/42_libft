/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:54:21 by svidot            #+#    #+#             */
/*   Updated: 2023/10/14 11:55:40 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	size_t	n_word;
	
	n_word = 0;
	while (s && *s)
	{		
		while (*s && *s == c)
			s++;
		s = ft_strchr(s, c);
		if (s)
			n_word++;
	}
	
	ft_putnbr_fd(n_word, 1);
	ft_putchar_fd('\n', 1); 
}

int main(void)
{
	char	*s;
	
	s = "xxsplitxxmoixlaxxxfacexx";
	ft_split(s, 'x');

	s = "splitxxmoixlaxxxfacexx";
	ft_split(s, 'x');

	s = "xxsplitxxmoixlaxxxface"; // 3 au lieu de 4
	ft_split(s, 'x');
	
	s = "splitxxmoixlaxxxface"; // 3 au lieu de 4
	ft_split(s, 'x');
	
	s = "splitmoilafacexx";
	ft_split(s, 'x');

	s = "xxsplitmoilaface"; // 0 au lieu de 1
	ft_split(s, 'x');

	s = "splitmoilaface"; // 0 > 1
	ft_split(s, 'x');
	
	s = ""; // 0...
	ft_split(s, 'x');

	s = "splitmoilaface"; // 0
	ft_split(s, 'x');

	s = "splitmoilaface"; // 0 > 1
	ft_split(s, 'y');

	s = "splitmoilaface";
	ft_split(s, '\0');

	s = "xxxxxxx"; 
	ft_split(s, 'x');
	return (0);	
}