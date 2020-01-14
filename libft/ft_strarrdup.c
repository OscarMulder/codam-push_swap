/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrdup.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 18:15:59 by omulder        #+#    #+#                */
/*   Updated: 2019/04/03 18:43:09 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strarrdup(char **arr)
{
	int		i;
	int		count;
	char	**new;

	if (!arr)
		return (NULL);
	count = 0;
	while (arr[count] != 0)
		count++;
	i = 0;
	new = (char**)ft_memalloc(sizeof(char*) * (count + 1));
	while (arr[i] != 0)
	{
		new[i] = ft_strdup(arr[i]);
		if (new[i] == NULL)
			return (NULL);
		i++;
	}
	return (new);
}
