/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_short.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/11 18:39:13 by omulder       #+#    #+#                 */
/*   Updated: 2022/02/08 16:59:38 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_short(t_fmt fmt)
{
	char	c;
	int		l;

	c = fmt.conv;
	l = fmt.length;
	if (c == 'd' || c == 'i')
	{
		if (l == 'h')
			return (1);
	}
	return (0);
}
