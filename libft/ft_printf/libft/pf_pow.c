/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_pow.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/14 15:29:06 by omulder       #+#    #+#                 */
/*   Updated: 2022/02/08 16:54:36 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	pf_powl(long double x, long double y)
{
	int	i;
	int	f;

	i = 1;
	f = x;
	while (i < y)
	{
		x *= f;
		i++;
	}
	return (x);
}
