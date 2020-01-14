/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_envi.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 18:58:26 by omulder        #+#    #+#                */
/*   Updated: 2019/04/04 14:31:02 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_envi(char **env, char *var)
{
	int		i;
	char	*find;

	i = 0;
	find = ft_strjoin(var, "=");
	if (!find)
		return (-1);
	while (env[i] != 0)
	{
		if (ft_strstr(env[i], find) == env[i])
		{
			ft_strdel(&find);
			return (i);
		}
		i++;
	}
	ft_strdel(&find);
	return (-1);
}
