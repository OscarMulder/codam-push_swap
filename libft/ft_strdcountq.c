/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdcountq.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 14:48:01 by omulder       #+#    #+#                 */
/*   Updated: 2019/04/01 17:12:01 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_quote(unsigned int *dquote, unsigned int *quote,
const char *str, int i)
{
	if (i > 0 && str[i - 1] == '\\')
		return ;
	if (!*dquote && str[i] == '\'')
		*quote = !*quote;
	else if (!*quote && str[i] == '\"')
		*dquote = !*dquote;
}

int			ft_strdcountq(char const *s, char c)
{
	unsigned int	i;
	unsigned int	strs;
	unsigned int	quote;
	unsigned int	dquote;

	i = 0;
	strs = 0;
	quote = 0;
	dquote = 0;
	while (s[i] != '\0')
	{
		check_quote(&dquote, &quote, s, i);
		if (dquote || quote || s[i] != c)
		{
			strs++;
			while ((dquote || quote || s[i] != c) && s[i] != '\0')
			{
				i++;
				check_quote(&dquote, &quote, s, i);
			}
			i--;
		}
		i++;
	}
	return (strs);
}
