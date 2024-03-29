/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prepare_fmt_num.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 15:23:53 by omulder       #+#    #+#                 */
/*   Updated: 2022/02/08 17:00:25 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fmt	prepare_fmt_num(t_fmt fmt, t_fmt copy, int neg)
{
	if (copy.prec != 0 && copy.prec != -1)
		fmt.width = (fmt.width - fmt.prec - 1);
	fmt.prec = -1;
	fmt.conv = 'D';
	if (fmt.opt[2])
	{
		fmt.opt[2] = 0;
		fmt.width = 0;
	}
	if (fmt.width > 1)
		fmt.width--;
	if (neg)
		fmt.opt[4] = -1;
	return (fmt);
}
