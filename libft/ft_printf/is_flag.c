/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_flag.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 12:07:01 by omulder       #+#    #+#                 */
/*   Updated: 2019/02/07 12:13:48 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag(char c)
{
	if (c == '#' || c == '0' || c == '-')
		return (1);
	if (c == ' ' || c == '+' || c == '\'')
		return (1);
	return (0);
}
