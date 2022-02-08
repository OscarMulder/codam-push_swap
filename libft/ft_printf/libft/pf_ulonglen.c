/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_ulonglen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/11 12:15:08 by omulder       #+#    #+#                 */
/*   Updated: 2022/02/08 16:56:12 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_ulonglen(unsigned long long n, int base)
{
	int	len;

	len = 1;
	if (n != 0)
		len--;
	while (n != 0)
	{
		len++;
		n /= base;
	}
	return (len);
}
