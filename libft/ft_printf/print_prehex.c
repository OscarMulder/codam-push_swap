/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_prehex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/11 12:41:39 by omulder       #+#    #+#                 */
/*   Updated: 2022/02/08 17:01:10 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_prehex(t_fmt fmt)
{
	int		hash;
	char	c;

	hash = fmt.opt[0];
	c = fmt.conv;
	if (hash)
	{
		if (c == 'X')
		{
			pf_putstr(fmt.fd, "0X");
			return (1);
		}
		else if (c == 'x' || c == 'p')
		{
			pf_putstr(fmt.fd, "0x");
			return (1);
		}
	}
	return (0);
}
