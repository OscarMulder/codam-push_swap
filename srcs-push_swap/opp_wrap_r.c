/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   opp_wrap_r.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/25 16:09:15 by omulder       #+#    #+#                 */
/*   Updated: 2020/08/02 14:29:44 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	opp_wrap_ra(t_stacks *s)
{
	if (s == NULL)
		return ;
	opp_ra(&(s->a));
	if (s->a != NULL)
		s->atop = s->a->pos - 1;
}

void	opp_wrap_rb(t_stacks *s)
{
	if (s == NULL)
		return ;
	opp_rb(&(s->b));
}

void	opp_wrap_rr(t_stacks *s)
{
	opp_wrap_ra(s);
	opp_wrap_rb(s);
}
