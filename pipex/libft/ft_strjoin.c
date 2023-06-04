/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:52:31 by cprojean          #+#    #+#             */
/*   Updated: 2023/05/29 11:44:01 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		sizearray;
	int		sizestring;
	int		runner;
	char	*array;

	runner = 0;
	sizearray = ft_strlen(s1);
	sizestring = ft_strlen(s2);
	array = malloc(sizeof(char) * (sizearray + sizestring) + 1);
	if (!array)
		return (NULL);
	while (runner < sizearray)
	{
		array[runner] = s1[runner];
		runner++;
	}
	runner = 0;
	while (runner < sizestring)
	{
		array[runner + sizearray] = s2[runner];
		runner++;
	}
	array[runner + sizearray] = '\0';
	return (array);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	size_t	runner;
	char	*array;

	runner = 0;
	array = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!array)
		return (NULL);
	while (runner < ft_strlen(s1))
	{
		array[runner] = s1[runner];
		runner++;
	}
	runner = 0;
	while (runner < ft_strlen(s2))
	{
		array[runner + ft_strlen(s1)] = s2[runner];
		runner++;
	}
	array[runner + ft_strlen(s1)] = '\0';
	free(s1);
	return (array);
}
