/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   opp_wrap_rr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/25 16:11:41 by omulder       #+#    #+#                 */
/*   Updated: 2020/02/25 10:21:57 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stack.h>
#include <stdlib.h>

void	opp_wrap_rra(t_stacks *s)
{
	if (s == NULL)
		return ;
	opp_rra(&(s->a));
	if (s->a != NULL)
		s->atop = s->a->pos - 1;
}

void	opp_wrap_rrb(t_stacks *s)
{
	if (s == NULL)
		return ;
	opp_rrb(&(s->b));
}

void	opp_wrap_rrr(t_stacks *s)
{
	opp_wrap_rra(s);
	opp_wrap_rrb(s);
}
