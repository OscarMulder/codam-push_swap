/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrdelone.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 19:41:15 by omulder       #+#    #+#                 */
/*   Updated: 2019/04/04 14:42:57 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strarrdelone(char **arr, int index)
{
	int		i;
	int		count;
	char	**new;

	if (!arr)
		return (NULL);
	count = 0;
	while (arr[count] != 0)
		count++;
	if (index >= count)
		return (NULL);
	i = 0;
	new = (char**)ft_memalloc(sizeof(char*) * (count + 1));
	count = 0;
	while (arr[i] != 0)
	{
		if (i != index)
			new[i - count] = ft_strdup(arr[i]);
		if (i != index && new[i - count] == NULL)
			return (NULL);
		if (i == index)
			count = 1;
		i++;
	}
	return (new);
}
