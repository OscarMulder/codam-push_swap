/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 10:37:05 by omulder       #+#    #+#                 */
/*   Updated: 2020/01/14 14:29:09 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*new;
	size_t	i;

	new = malloc(size);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		((char*)new)[i] = 0;
		i++;
	}
	return (new);
}
