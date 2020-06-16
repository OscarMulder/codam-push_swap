/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_options.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 12:05:01 by omulder       #+#    #+#                 */
/*   Updated: 2020/06/16 14:31:42 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_fmt	set_option(char c, t_fmt fmt)
{
	if (c == '#')
		fmt.opt[0] = 1;
	if (c == '0')
		fmt.opt[1] = 1;
	if (c == '-')
		fmt.opt[2] = 1;
	if (c == ' ')
		fmt.opt[3] = 1;
	if (c == '+')
		fmt.opt[4] = 1;
	if (c == '\'')
		fmt.opt[5] = 1;
	return (fmt);
}

t_fmt			find_options(const char **format, t_fmt fmt)
{
	const char *tmp;

	tmp = *format;
	while (*tmp && !is_conversion(*tmp) && (!pf_isdigit(*tmp) || *tmp == '0'))
	{
		if (is_flag(*tmp))
		{
			fmt = set_option(*tmp, fmt);
		}
		tmp++;
	}
	while (*tmp && !is_conversion(*tmp))
	{
		if (is_flag(*tmp) && *tmp != '0')
		{
			fmt = set_option(*tmp, fmt);
		}
		tmp++;
	}
	return (fmt);
}
