/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quick_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/26 19:33:05 by omulder       #+#    #+#                 */
/*   Updated: 2020/03/07 18:01:33 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <stack.h>
#include <stdlib.h>

void	split_a(t_stacks *s, int min, int max, int pivot)
{
	int		i;
	int		rot;

	i = 0;
	rot = 0;
	while (i < (pivot - min) && i + rot < max - min)
	{
		if (s->a->pos <= pivot)
		{
			opp_do(s, PB);
			i++;
		}
		else
		{
			opp_do(s, RA);
			rot++;
		}
	}
	i = 0;
	while (max != s->total && min != 0 && i < rot)
	{
		opp_do(s, RRA);
		i++;
	}
}

void	split_b(t_stacks *s, int min, int max, int pivot)
{
	int		i;
	int		rot;

	i = 0;
	rot = 0;
	while (i <= (pivot - min) && i + rot <= max - min)
	{
		if (s->b->pos > pivot)
		{
			opp_do(s, PA);
			i++;
		}
		else
		{
			opp_do(s, RB);
			rot++;
		}
	}
	i = 0;
	while (i < rot)
	{
		opp_do(s, RRB);
		i++;
	}
}

void	splitsort_b(t_stacks *s, int min, int max)
{
	int		pivot;

	pivot = min + ((max - min) / 2);
	if (max - min == 3 && s->size_b > 2)
		sort_3_b(s);
	else if (max - min == 2 && s->size_b > 1)
		sort_2_b(s);
	else if (max - min > 1)
	{
		split_b(s, min, max, pivot);
		splitsort_b(s, min, pivot);
		splitsort_a(s, pivot, max);
		push_back(s, pivot, max, PB);
	}
}

void	splitsort_a(t_stacks *s, int min, int max)
{
	int		pivot;

	pivot = min + ((max - min) / 2);
	if (max - min == 3 && s->size_a > 2)
		sort_3_a(s);
	else if (max - min == 2 && s->size_a > 1)
		sort_2_a(s);
	else if (max - min > 1)
	{
		split_a(s, min, max, pivot);
		splitsort_a(s, pivot, max);
		splitsort_b(s, min, pivot);
		push_back(s, min, pivot, PA);
	}
}

void	quick_sort(t_stacks *s)
{
	splitsort_a(s, 0, s->total);
}
