/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_paddingandsign.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 16:07:28 by omulder       #+#    #+#                 */
/*   Updated: 2022/02/08 17:03:03 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_paddingandsign(t_fmt fmt, long long num, int ilen)
{
	if (!fmt.opt[2] && (!fmt.opt[1] || fmt.prec != -1))
		print_padding(fmt.fd, ' ', (fmt.width - ilen));
	if (num >= 0 && fmt.opt[3] && !fmt.opt[4])
		pf_putchar(fmt.fd, ' ');
	if (num == 0 && fmt.prec == 0 && fmt.width != -1)
		pf_putchar(fmt.fd, ' ');
	if (num >= 0 && fmt.opt[4] == 1)
		pf_putchar(fmt.fd, '+');
	if (num < 0 || fmt.opt[4] == -1)
		pf_putchar(fmt.fd, '-');
	if (!fmt.opt[2] && fmt.opt[1] && fmt.prec == -1)
		print_padding(fmt.fd, '0', (fmt.width - ilen));
}
