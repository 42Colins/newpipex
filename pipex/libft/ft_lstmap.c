/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:20:43 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/20 18:26:31 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstmap(t_stack *lst, int (*f)(int))
{
	t_stack	*array;
	t_stack	*next_array;

	if (!lst || !f)
		return (NULL);
	array = ft_lstnew(f(lst -> data));
	if (!array)
		return (NULL);
	lst = lst -> next;
	while (lst)
	{
		next_array = ft_lstnew(f(lst -> data));
		if (!next_array)
		{
			ft_lstclear(&array);
			return (NULL);
		}
		ft_lstadd_back(&array, next_array);
		lst = lst -> next;
	}
	return (array);
}
