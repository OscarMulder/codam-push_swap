/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putchar.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 15:14:38 by omulder       #+#    #+#                 */
/*   Updated: 2022/02/08 16:54:44 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putchar(int fd, int c)
{
	char	ca;

	ca = (char)c;
	write(fd, &ca, 1);
	return (1);
}
