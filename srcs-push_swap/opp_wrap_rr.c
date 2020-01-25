/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   opp_wrap_rr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/25 16:11:41 by omulder        #+#    #+#                */
/*   Updated: 2020/01/25 16:12:42 by omulder       ########   odam.nl         */
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
