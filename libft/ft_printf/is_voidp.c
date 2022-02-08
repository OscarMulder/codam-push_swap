/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_voidp.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 13:51:41 by omulder       #+#    #+#                 */
/*   Updated: 2022/02/08 17:00:16 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_voidp(t_fmt fmt)
{
	char	c;

	c = fmt.conv;
	if (c == 'p')
		return (1);
	return (0);
}
