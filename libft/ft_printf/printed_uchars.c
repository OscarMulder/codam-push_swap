/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printed_uchars.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 16:00:06 by omulder       #+#    #+#                 */
/*   Updated: 2020/06/16 14:28:42 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printed_uchars(t_fmt fmt, unsigned long long num)
{
	int	ilen;
	int rilen;

	ilen = pf_ulonglen(num, find_base(fmt));
	rilen = ilen;
	if ((fmt.opt[0] && is_hex(fmt) &&
	num != 0) || fmt.conv == 'p')
		rilen += 2;
	if (fmt.prec == 0 && num == 0 && fmt.conv != 'p')
		rilen = 0;
	if (fmt.prec == 0 && num == 0 && fmt.conv == 'p')
		rilen = 2;
	if (fmt.prec > ilen || fmt.width > rilen)
	{
		if (fmt.prec > fmt.width)
		{
			rilen = fmt.prec;
			if (fmt.opt[0] && is_hex(fmt) && (num != 0 || fmt.conv == 'p'))
				rilen += 2;
		}
		else
			rilen = fmt.width;
	}
	return (rilen);
}
