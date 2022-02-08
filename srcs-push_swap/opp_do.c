/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   opp_do.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/25 16:16:04 by omulder       #+#    #+#                 */
/*   Updated: 2022/02/08 16:48:10 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	opp_do(t_stacks *s, t_opp op)
{
	if (op == SA)
		opp_wrap_sa(s);
	else if (op == SB)
		opp_wrap_sb(s);
	else if (op == SS)
		opp_wrap_ss(s);
	else if (op == PA)
		opp_wrap_pa(s);
	else if (op == PB)
		opp_wrap_pb(s);
	else if (op == RA)
		opp_wrap_ra(s);
	else if (op == RB)
		opp_wrap_rb(s);
	else if (op == RR)
		opp_wrap_rr(s);
	else if (op == RRA)
		opp_wrap_rra(s);
	else if (op == RRB)
		opp_wrap_rrb(s);
	else if (op == RRR)
		opp_wrap_rrr(s);
	else
		return (0);
	return (add_op(s, op));
}
