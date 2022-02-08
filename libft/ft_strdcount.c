/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdcount.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 15:27:57 by omulder       #+#    #+#                 */
/*   Updated: 2022/02/08 17:11:46 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strdcount(char const *s, char c)
{
	unsigned int	i;
	unsigned int	strs;

	i = 0;
	strs = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			strs++;
			while (s[i] != c && s[i] != '\0')
				i++;
			i--;
		}
		i++;
	}
	return (strs);
}
