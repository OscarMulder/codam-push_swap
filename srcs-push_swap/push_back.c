/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_back.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/07 18:01:09 by omulder       #+#    #+#                 */
/*   Updated: 2022/02/08 16:49:41 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push_back(t_stacks *s, int min, int max, t_opp push)
{
	int	i;

	i = 0;
	while (i < max - min)
	{
		i++;
		opp_do(s, push);
	}
}
