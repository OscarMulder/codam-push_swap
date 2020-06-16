/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rot_a_sorted.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 15:25:21 by omulder       #+#    #+#                 */
/*   Updated: 2020/03/06 15:25:33 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rot_a_sorted(t_stacks *s)
{
	int		i;
	t_stack	*ptr;

	ptr = s->a;
	i = 0;
	while (ptr && ptr->pos != 1)
	{
		i++;
		ptr = ptr->next;
	}
	if (i <= s->size_a / 2)
	{
		while (s->a->pos != 1)
			opp_do(s, RA);
	}
	else
	{
		while (s->a->pos != 1)
			opp_do(s, RRA);
	}
}
