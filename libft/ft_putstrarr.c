/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstrarr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 15:43:03 by omulder       #+#    #+#                 */
/*   Updated: 2022/02/08 17:10:36 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrarr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != '\0')
	{
		ft_putendl(arr[i]);
		i++;
	}
}
