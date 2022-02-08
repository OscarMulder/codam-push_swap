/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_ulong.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/21 12:16:24 by omulder       #+#    #+#                 */
/*   Updated: 2022/02/08 16:59:58 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_ulong(t_fmt fmt)
{
	char	c;
	int		l;

	c = fmt.conv;
	l = fmt.length;
	if (c == 'o' || c == 'u' || c == 'x' || c == 'X')
	{
		if (l == ('l' + 'l') || l == 'l' || l == 'j' || l == 'z')
			return (1);
	}
	if (c == 'U' || c == 'O')
		return (1);
	return (0);
}
