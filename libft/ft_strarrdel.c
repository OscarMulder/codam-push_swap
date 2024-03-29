/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrdel.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 13:17:15 by omulder       #+#    #+#                 */
/*   Updated: 2022/02/08 17:10:56 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strarrdel(char ***arr)
{
	int	i;

	i = 0;
	if (arr == NULL || *arr == NULL)
		return ;
	while ((*arr)[i] != 0)
	{
		ft_strdel(&((*arr)[i]));
		i++;
	}
	free(*arr);
	*arr = NULL;
}
