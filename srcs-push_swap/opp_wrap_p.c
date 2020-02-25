/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   opp_wrap_p.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/25 16:04:10 by omulder        #+#    #+#                */
/*   Updated: 2020/02/25 10:52:33 by omulder       ########   odam.nl         */
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
	s->atop = s->a->pos - 1;
	s->amirror[s->a->pos - 1] = TRUE;
	s->size_a++;
	s->size_b--;
}

void	opp_wrap_pb(t_stacks *s)
{
	if (s == NULL)
		return ;
	if (s->a == NULL)
		return ;
	s->amirror[s->a->pos - 1] = FALSE;
	opp_pb(&(s->a), &(s->b));
	if (s->a)
		s->atop = s->a->pos - 1;
	else
		s->atop = -1;
	s->size_a--;
	s->size_b++;
}
