/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_uint.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/21 12:15:00 by omulder       #+#    #+#                 */
/*   Updated: 2022/02/08 16:59:54 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_uint(t_fmt fmt)
{
	char	c;
	int		l;

	c = fmt.conv;
	l = fmt.length;
	if (c == 'o' || c == 'u' || c == 'x' || c == 'X')
	{
		if (l == -1)
			return (1);
		return (0);
	}
	return (0);
}
