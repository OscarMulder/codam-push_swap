/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_longint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 13:51:55 by omulder       #+#    #+#                 */
/*   Updated: 2022/02/08 16:59:16 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_longint(t_fmt fmt)
{
	char	c;

	c = fmt.conv;
	if (c == 'D')
		return (1);
	return (0);
}
