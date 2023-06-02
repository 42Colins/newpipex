/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:35:06 by cprojean          #+#    #+#             */
/*   Updated: 2023/02/23 12:52:08 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_stack *lst, void (*f)(int))
{
	t_stack	*array;
	t_stack	*next_array;

	if (!lst || !f)
		return ;
	array = lst;
	while (array)
	{
		next_array = array->next;
		f(array->data);
		array = next_array;
	}
}
