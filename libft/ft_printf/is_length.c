/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_length.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 12:06:05 by omulder       #+#    #+#                 */
/*   Updated: 2022/02/08 16:59:05 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_length(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'L')
		return (1);
	if (c == 'j' || c == 't' || c == 'z')
		return (1);
	return (0);
}
