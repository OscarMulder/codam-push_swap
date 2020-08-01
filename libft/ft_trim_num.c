/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_trim_num.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/01 16:11:48 by omulder       #+#    #+#                 */
/*   Updated: 2020/08/01 16:38:17 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	count_leading_spaces(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	return (i);
}

static int	count_leading_zeros(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '0')
		i++;
	if (str[i] == '\0' && i > 0)
		return (i - 1);
	return (i);
}

static int	count_digits(char *str)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

/*
** char		*ft_trim_num(char *str)
**
** Trims spaces and leading zeros from a valid (checked by ft_isnumeric)
** number string.
** Returns a newly allocated string.
*/

char		*ft_trim_num(char *str)
{
	int		count_zero;
	int		start;
	int		i;
	int		j;
	char	*new;

	start = count_leading_spaces(str);
	i = (str[start] == '-' || str[start] == '+');
	count_zero = count_leading_zeros(&(str[start + i]));
	j = 0;
	i += count_digits(&(str[start + i + count_zero]));
	new = ft_memalloc(sizeof(char) * (i + 1));
	if (new == NULL)
		return (NULL);
	if (str[start] == '-' || str[start] == '+')
	{
		new[j] = str[start];
		j++;
	}
	while (j < i)
	{
		new[j] = str[start + count_zero + j];
		j++;
	}
	return (new);
}
