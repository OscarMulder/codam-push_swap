/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_env.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 12:35:29 by omulder       #+#    #+#                 */
/*   Updated: 2022/02/08 17:07:09 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_find_env(char **env, char *var)
{
	int		i;

	i = 0;
	while (env[i] != 0)
	{
		if (ft_strstr(env[i], var) == env[i])
		{
			return (ft_strsub(env[i], ft_strlen(var) + 1, (ft_strlen(env[i]) \
			- ft_strlen(var))));
		}
		i++;
	}
	return (NULL);
}
