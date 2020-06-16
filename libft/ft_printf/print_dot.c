/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_dot.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 15:25:00 by omulder       #+#    #+#                 */
/*   Updated: 2020/06/16 14:28:42 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_dot(t_fmt copy)
{
	if (copy.prec != 0 || copy.opt[0])
		return (pf_putchar(copy.fd, '.'));
	return (0);
}
