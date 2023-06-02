/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:27:24 by cprojean          #+#    #+#             */
/*   Updated: 2023/04/27 14:53:48 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack	*array;
	t_stack	*next_array;
	int		size;
	int		runner;

	runner = 0;
	size = ft_lstsize(*lst);
	if (!lst)
		return ;
	array = *lst;
	while (runner < size)
	{
		next_array = array->next;
		free(array);
		if (array->next)
			array = next_array;
		size++;
	}
	*lst = NULL;
	return ;
}

void	ft_lstintclear(t_stack **lst)
{
	t_stack	*array;
	t_stack	*next_array;

	if (lst == NULL)
		return ;
	array = *lst;
	while (array)
	{
		next_array = array->next;
		free(array);
		array = next_array;
	}
	*lst = NULL;
	return ;
}
