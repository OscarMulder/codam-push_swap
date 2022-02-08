/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 14:46:11 by omulder       #+#    #+#                 */
/*   Updated: 2022/02/08 17:10:20 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr(char const *s, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		write(1, &s[i], 1);
		i++;
	}
}
