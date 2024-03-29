/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_char.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/08 14:46:44 by omulder       #+#    #+#                 */
/*   Updated: 2022/02/08 17:00:32 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_padding(t_fmt fmt)
{
	if (!fmt.opt[1] && !fmt.opt[2])
		print_padding(fmt.fd, ' ', (fmt.width - 1));
	if (fmt.opt[1] && !fmt.opt[2])
		print_padding(fmt.fd, '0', (fmt.width - 1));
}

int	print_char(t_fmt fmt, unsigned int c)
{
	int	ret;

	put_padding(fmt);
	if (fmt.conv == 'c' && fmt.length == -1)
		ret = pf_putchar(fmt.fd, c);
	else
		ret = pf_putchar_uni(fmt.fd, c);
	if (fmt.opt[2])
		print_padding(fmt.fd, ' ', (fmt.width - 1));
	if (fmt.width > 1)
		return (fmt.width);
	return (ret);
}
