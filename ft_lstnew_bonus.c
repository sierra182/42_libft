/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:02:04 by svidot            #+#    #+#             */
/*   Updated: 2023/10/11 14:49:43 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_l;

	new_l = NULL;
	new_l = (t_list *) malloc(sizeof(t_list));
	if (!new_l)
		return (NULL);
	new_l->content;
	new_l->next = NULL;
	return (new_l);
}
