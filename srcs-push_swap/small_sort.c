/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 12:51:11 by omulder        #+#    #+#                */
/*   Updated: 2020/03/03 14:05:24 by omulder       ########   odam.nl         */
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

void	sort_3(t_stacks *s, int min, int mid, int max)
{
	if (s->a->pos == min && s->a->next->pos == mid && s->a->next->next->pos == max)
		return ;
	if (s->a->pos == mid && s->a->next->pos == max && s->a->next->next->pos == min)
		opp_do(s, RRA);
	if (s->a->pos == max && s->a->next->pos == mid && s->a->next->next->pos == min)
	{
		opp_do(s, SA);
		opp_do(s, RRA);
		return ;
	}
	if (s->a->pos == mid && s->a->next->pos == min && s->a->next->next->pos == max)
		opp_do(s, SA);
	if (s->a->pos == min && s->a->next->pos == max && s->a->next->next->pos == mid)
	{
		opp_do(s, RRA);
		opp_do(s, SA);
		return ;
	}
	if (s->a->pos == max && s->a->next->pos == min && s->a->next->next->pos == mid)
		opp_do(s, RA);
}

int		find_min(t_stack *a)
{
	int		min;

	min = a->pos;
	while (a != NULL)
	{
		if (a->pos < min)
			min = a->pos;
		a = a->next;
	}
	return (min);
}

int		find_mid(t_stack *a, int min, int max)
{
	while (a != NULL)
	{
		if (a->pos != min && a->pos != max)
			return (a->pos);
		a = a->next;
	}
	return (-1);
}

int		find_max(t_stack *a)
{
	int		max;

	max = a->pos;
	while (a != NULL)
	{
		if (a->pos > max)
			max = a->pos;
		a = a->next;
	}
	return (max);
}

void	sort_4(t_stacks *s)
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
	while (s->a->pos != 1)
		opp_do(s, RA);
}

void	sort_5(t_stacks *s)
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
	while (s->a->pos != 1)
		opp_do(s, RA);
}

int		small_sort(t_stacks *s)
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
