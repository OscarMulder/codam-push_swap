/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 12:51:11 by omulder        #+#    #+#                */
/*   Updated: 2020/03/03 13:50:39 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <stack.h>
#include <stdlib.h>

void	sort_2(t_stacks *s)
{
	if (s->a->pos > s->a->next->pos)
		opp_do(s, SA);
}

void	sort_3(t_stacks *s)
{
	if (s->a->pos == 1 && s->a->next->pos == 2 && s->a->next->next->pos == 3)
		return ;
	if (s->a->pos == 2 && s->a->next->pos == 3 && s->a->next->next->pos == 1)
		opp_do(s, RRA);
	if (s->a->pos == 3 && s->a->next->pos == 2 && s->a->next->next->pos == 1)
	{
		opp_do(s, SA);
		opp_do(s, RRA);
		return ;
	}
	if (s->a->pos == 2 && s->a->next->pos == 1 && s->a->next->next->pos == 3)
		opp_do(s, SA);
	if (s->a->pos == 1 && s->a->next->pos == 3 && s->a->next->next->pos == 2)
	{
		opp_do(s, RRA);
		opp_do(s, SA);
		return ;
	}
	if (s->a->pos == 3 && s->a->next->pos == 1 && s->a->next->next->pos == 2)
		opp_do(s, RA);
}

void	sort_4(t_stacks *s)
{
	opp_do(s, PB);
	sort_3(s);
	find_and_do_best_move(s);
}

void	sort_5(t_stacks *s)
{
	opp_do(s, PB);
	opp_do(s, PB);
	sort_3(s);
	find_and_do_best_move(s);
	find_and_do_best_move(s);
}

int		small_sort(t_stacks *s)
{
	if (s->total == 2)
		sort_2(s);
	else if (s->total == 3)
		sort_3(s);
	else if (s->total == 4)
		sort_4(s);
	else if (s->total == 5)
		sort_5(s);
	else
		return (0);
	return (1);
}
