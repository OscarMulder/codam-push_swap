/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_aisint.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 12:31:29 by omulder        #+#    #+#                */
/*   Updated: 2020/01/14 14:19:32 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>
#include <libft.h>

int		ft_aisint(char *n)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(n);
	i = 0;
	if (n[0] == '-')
		i++;
	if (len > 11 || (len == 11 && n[0] == '-') ||
		(len == 10 && n[0] != '-'))
	{
		if (len > 11 || n[i] > '2' || n[i + 1] > '1' || n[i + 2] > '4'
			|| n[i + 3] > '7' || n[i + 4] > '4' || n[i + 5] > '8' ||
			n[i + 6] > '3' || n[i + 7] > '6' || n[i + 8] > '4' ||
			(n[i + 9] > '8' && n[0] == '-') || (n[i + 9] > '7' && n[0] != '-'))
			return (0);
	}
	if (len < 10)
		while (n[i])
		{
			if (!ft_isdigit(n[i]))
				return (0);
			i++;
		}
	return (1);
}
