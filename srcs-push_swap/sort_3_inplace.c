/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_3_inplace.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 16:19:08 by omulder        #+#    #+#                */
/*   Updated: 2020/02/23 17:01:14 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <stack.h>
#include <stdlib.h>

void	sort_3_a(t_stacks *s)
{
	int		is_lowest;

	is_lowest = 0;
	// ft_dprintf(2, "CALLED: sort_3_a\n");
	if (s->a->pos < s->a->next->pos && s->a->next->pos < s->a->next->next->pos)
		return ; // 1 2 3
	if (s->a->next->pos > s->a->next->next->pos && s->a->pos > s->a->next->next->pos)
	{
		opp_do(s, PB);
		opp_do(s, PB);
		opp_do(s, RA);
		sort_2_b_push_a(s);
		opp_do(s, RRA);
		return ; // 3 2 1 && 2 3 1
	}
	if (s->a->pos > s->a->next->pos && s->a->next->pos < s->a->next->next->pos && s->a->pos < s->a->next->next->pos)
	{
		opp_do(s, SA);
		return ; // 2 1 3
	}
	// 1 3 2 && 3 1 2
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

void	sort_3_b(t_stacks *s)
{
	int		is_lowest;

	is_lowest = 0;
	// ft_dprintf(2, "CALLED: sort_3_b\n");
	if (s->b->pos > s->b->next->pos && s->b->next->pos > s->b->next->next->pos)
		return ; // 3 2 1
	if (s->b->next->pos < s->b->next->next->pos && s->b->pos < s->b->next->next->pos)
	{
		opp_do(s, PA);
		opp_do(s, PA);
		opp_do(s, RB);
		sort_2_a_push_b(s);
		opp_do(s, RRB);
		return ; // 1 2 3 && 2 1 3
	}
	if (s->b->pos < s->b->next->pos && s->b->next->pos > s->b->next->next->pos && s->b->pos > s->b->next->next->pos)
	{
		opp_do(s, SB);
		return ; // 2 3 1
	}
	// 1 3 2 && 3 1 2
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
