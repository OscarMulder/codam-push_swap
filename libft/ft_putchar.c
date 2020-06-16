/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 11:27:12 by omulder       #+#    #+#                 */
/*   Updated: 2019/03/23 17:48:30 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(unsigned int c)
{
	write(1, &c, 1);
}
