/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prepare_fmt_expo.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 15:24:34 by omulder       #+#    #+#                 */
/*   Updated: 2020/06/16 14:31:26 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fmt	prepare_fmt_exp(t_fmt fmt, t_fmt copy, int ret)
{
	fmt.width = -1;
	fmt.opt[3] = 0;
	fmt.opt[2] = copy.opt[2];
	if (fmt.opt[2])
		fmt.width = copy.width - ret;
	fmt.opt[4] = 0;
	fmt.prec = copy.prec;
	fmt.opt[0] = 0;
	return (fmt);
}
