/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   opp_wrap_s.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/25 16:12:58 by omulder        #+#    #+#                */
/*   Updated: 2020/01/25 17:43:36 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stack.h>
#include <stdlib.h>

void	opp_wrap_sa(t_stacks *s)
{
	if (s == NULL)
		return ;
	opp_sa(&(s->a));
}

void	opp_wrap_sb(t_stacks *s)
{
	if (s == NULL)
		return ;
	opp_sa(&(s->b));
}

void	opp_wrap_ss(t_stacks *s)
{
	if (s == NULL)
		return ;
	opp_ss(&(s->a), &(s->b));
}
