/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 19:21:44 by omulder       #+#    #+#                 */
/*   Updated: 2022/02/08 17:07:37 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_intlen(int n)
{
	int	len;

	len = 1;
	if (n > 0)
		len--;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}
