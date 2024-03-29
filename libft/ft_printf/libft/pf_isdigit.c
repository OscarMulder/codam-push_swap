/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 11:53:34 by omulder       #+#    #+#                 */
/*   Updated: 2022/02/08 16:54:01 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	pf_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
