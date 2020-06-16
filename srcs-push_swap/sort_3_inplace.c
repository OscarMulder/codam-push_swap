/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_3_inplace.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 16:19:08 by omulder       #+#    #+#                 */
/*   Updated: 2020/03/07 18:12:22 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <stack.h>
#include <stdlib.h>

static void	sort_3_a_last(t_stacks *s)
{
	int		is_lowest;

	is_lowest = 0;
	if (s->a->pos < s->a->next->pos)
		is_lowest = 1;
	opp_do(s, RA);
	opp_do(s, PB);
	opp_do(s, PB);
	if (!is_lowest)
		opp_do(s, RRA);
	sort_2_b_push_a(s);
	if (is_lowest)
		opp_do(s, RRA);
}

void		sort_3_a(t_stacks *s)
{
	if (s->a->pos < s->a->next->pos && s->a->next->pos < s->a->next->next->pos)
		return ;
	if (s->a->next->pos > s->a->next->next->pos
	&& s->a->pos > s->a->next->next->pos)
	{
		opp_do(s, PB);
		opp_do(s, PB);
		opp_do(s, RA);
		sort_2_b_push_a(s);
		opp_do(s, RRA);
		return ;
	}
	if (s->a->pos > s->a->next->pos && s->a->next->pos < s->a->next->next->pos
	&& s->a->pos < s->a->next->next->pos)
	{
		opp_do(s, SA);
		return ;
	}
	sort_3_a_last(s);
}

static void	sort_3_b_last(t_stacks *s)
{
	int		is_lowest;

	is_lowest = 0;
	if (s->b->pos < s->b->next->pos)
		is_lowest = 1;
	opp_do(s, RB);
	opp_do(s, PA);
	opp_do(s, PA);
	if (is_lowest)
		opp_do(s, RRB);
	sort_2_a_push_b(s);
	if (!is_lowest)
		opp_do(s, RRB);
}

void		sort_3_b(t_stacks *s)
{
	if (s->b->pos > s->b->next->pos && s->b->next->pos > s->b->next->next->pos)
		return ;
	if (s->b->next->pos < s->b->next->next->pos
	&& s->b->pos < s->b->next->next->pos)
	{
		opp_do(s, PA);
		opp_do(s, PA);
		opp_do(s, RB);
		sort_2_a_push_b(s);
		opp_do(s, RRB);
		return ;
	}
	if (s->b->pos < s->b->next->pos && s->b->next->pos > s->b->next->next->pos
	&& s->b->pos > s->b->next->next->pos)
	{
		opp_do(s, SB);
		return ;
	}
	sort_3_b_last(s);
}
