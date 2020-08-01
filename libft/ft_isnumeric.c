/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isnumeric.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/01 16:00:18 by omulder       #+#    #+#                 */
/*   Updated: 2020/08/01 16:05:47 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** ft_isnumeric(char *str)
**
** Checks if 'str' is a number in valid integer format that can be converted
** by an atoi() like function.
** Doesn't handle floating point numbers, doesn't check if the number fits in
** an int.
*/

int		ft_isnumeric(char *str)
{
	char	*orig;

	if (str == NULL)
		return (-1);
	orig = str;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str != '\0' || orig == str)
		return (0);
	return (1);
}
