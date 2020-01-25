/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   opp_wrap_p.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/25 16:04:10 by omulder        #+#    #+#                */
/*   Updated: 2020/01/25 17:44:07 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stack.h>
#include <stdlib.h>

void	opp_wrap_pa(t_stacks *s)
{
	if (s == NULL)
		return ;
	if (s->b == NULL)
		return ;
	opp_pa(&(s->a), &(s->b));
	s->size_a++;
	s->size_b--;
}

void	opp_wrap_pb(t_stacks *s)
{
	if (s == NULL)
		return ;
	if (s->a == NULL)
		return ;
	opp_pb(&(s->a), &(s->b));
	s->size_a--;
	s->size_b++;
}
