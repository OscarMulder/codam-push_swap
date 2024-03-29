/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_backpadding.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 16:01:42 by omulder       #+#    #+#                 */
/*   Updated: 2022/02/08 17:02:57 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_backpadding(t_fmt fmt, long long num, int ilen)
{
	if (fmt.opt[2])
	{
		if (fmt.opt[0] && is_hex(fmt) \
		&& (num != 0 || fmt.conv == 'p'))
			print_padding(fmt.fd, ' ', (fmt.width - ilen) - 2);
		else
			print_padding(fmt.fd, ' ', (fmt.width - ilen));
	}
}
