/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 12:51:11 by omulder       #+#    #+#                 */
/*   Updated: 2022/02/08 16:50:20 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sort_2(t_stacks *s)
{
	if (s->a->pos > s->a->next->pos)
		opp_do(s, SA);
}

static void	sort_3(t_stacks *s, int min, int mid, int max)
{
	if (s->a->pos == min && s->a->next->pos == mid
		&& s->a->next->next->pos == max)
		return ;
	else if (s->a->pos == mid && s->a->next->pos == max
		&& s->a->next->next->pos == min)
		opp_do(s, RRA);
	else if (s->a->pos == max && s->a->next->pos == mid
		&& s->a->next->next->pos == min)
	{
		opp_do(s, SA);
		opp_do(s, RRA);
	}
	else if (s->a->pos == mid && s->a->next->pos == min
		&& s->a->next->next->pos == max)
		opp_do(s, SA);
	else if (s->a->pos == min && s->a->next->pos == max
		&& s->a->next->next->pos == mid)
	{
		opp_do(s, RRA);
		opp_do(s, SA);
	}
	else if (s->a->pos == max && s->a->next->pos == min
		&& s->a->next->next->pos == mid)
		opp_do(s, RA);
}

static void	sort_4(t_stacks *s)
{
	int		min;
	int		mid;
	int		max;

	opp_do(s, PB);
	min = find_min(s->a);
	max = find_max(s->a);
	mid = find_mid(s->a, min, max);
	sort_3(s, min, mid, max);
	set_sorted(s);
	find_and_do_best_move(s);
	rot_a_sorted(s);
}

static void	sort_5(t_stacks *s)
{
	int		min;
	int		mid;
	int		max;

	opp_do(s, PB);
	opp_do(s, PB);
	min = find_min(s->a);
	max = find_max(s->a);
	mid = find_mid(s->a, min, max);
	sort_3(s, min, mid, max);
	set_sorted(s);
	find_and_do_best_move(s);
	find_and_do_best_move(s);
	rot_a_sorted(s);
}

int	small_sort(t_stacks *s)
{
	if (s->total == 2)
		sort_2(s);
	else if (s->total == 3)
		sort_3(s, 1, 2, 3);
	else if (s->total == 4)
		sort_4(s);
	else if (s->total == 5)
		sort_5(s);
	else
		return (0);
	return (1);
}
