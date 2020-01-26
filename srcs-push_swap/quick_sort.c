/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quick_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/26 19:33:05 by omulder        #+#    #+#                */
/*   Updated: 2020/01/26 22:26:14 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <stack.h>
#include <stdlib.h>

// int		find_pivot_a(t_stacks *s)
// {
// 	int		mod;

// 	if (s->size_a == s->total)
// 		return (s->total / 2);
// 	if (s->size_a == 0)
// 		return (0);
// 	mod = s->total % s->size_a;
// 	if (mod % 2 != 0)
// 		mod++;
// 	return (s->size_a)	
// }

void	push_back(t_stacks *s, int min, int max, t_opp push)
{
	int i;

	i = 0;
	while (i < max - min)
	{
		i++;
		opp_do(s, push);
	}
}

void	sort_2_a_push_b(t_stacks *s)
{
	if (s->a->pos < s->a->next->pos)
	{
		opp_do(s, RA);
		opp_do(s, PB);
		opp_do(s, RRA);
		opp_do(s, PB);
	}
	else
	{
		opp_do(s, PB);
		opp_do(s, PB);
	}
}

void	sort_2_b_push_a(t_stacks *s)
{
	if (s->b->pos < s->b->next->pos)
	{
		opp_do(s, RB);
		opp_do(s, PA);
		opp_do(s, RRB);
		opp_do(s, PA);
	}
	else
	{
		opp_do(s, PA);
		opp_do(s, PA);
	}
}

void	sort_3_a(t_stacks *s)
{
	int		is_lowest;

	is_lowest = 0;
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
	if (s->b->pos < s->b->next->pos && s->b->next->pos < s->b->next->next->pos)
		return ; // 1 2 3
	if (s->b->next->pos > s->b->next->next->pos && s->b->pos > s->b->next->next->pos)
	{
		opp_do(s, PA);
		opp_do(s, PA);
		opp_do(s, RB);
		sort_2_a_push_b(s);
		opp_do(s, RRB);
		return ; // 3 2 1 && 2 3 1
	}
	// 1 3 2 && 3 1 2
	if (s->b->pos < s->b->next->pos)
		is_lowest = 1;
	opp_do(s, RB);
	opp_do(s, PA);
	opp_do(s, PA);
	if (!is_lowest)
		opp_do(s, RRB);
	sort_2_a_push_b(s);
	if (is_lowest)
		opp_do(s, RRB);
}

void	split_b(t_stacks *s, int min, int max)
{
	int		i;
	int		pivot;
	int		rotations;

	i = 0;
	rotations = 0;
	pivot = min + ((max - min) / 2);
	ft_printf("-----------------------SPLIT B----------------------------\n");
	print_stack(s->a);
	ft_printf("------------------------------------------------------\nStack B\n");
	print_stack(s->b);
	if (max - min == 3)
	{
		sort_3_b(s);
		push_back(s, min, max, PA);
		return ;
	}
	while (i < pivot && i + rotations < max - min)
	{
		if (s->b->pos < pivot)
		{
			opp_do(s, PA);
			i++;
		}
		else
		{
			opp_do(s, RB);
			rotations++;
		}
	}
	if (pivot - min == 2)
	{
		sort_3_b(s);
		sort_2_a_push_b(s);
	}
	else
	{
		split_a(s, pivot, max);
		split_b(s, min, pivot);
	}
	push_back(s, min, max, PA);
}

void	split_a(t_stacks *s, int min, int max)
{
	int		i;
	int		pivot;
	int		rotations;

	i = 0;
	rotations = 0;
	pivot = min + ((max - min) / 2);
	ft_printf("--------------------------SPLIT A----------------------\n");
	print_stack(s->a);
	ft_printf("------------------------------------------------------\nStack B\n");
	print_stack(s->b);
	if (max - min == 3)
	{
		sort_3_a(s);
		if (max != s->total)
			push_back(s, min, max, PB);
		return ;
	}
	while (i < pivot && i + rotations < max - min)
	{
		if (s->a->pos < pivot)
		{
			opp_do(s, PB);
			i++;
		}
		else
		{
			opp_do(s, RA);
			rotations++;
		}
	}
	if (pivot - min == 2)
	{
		sort_3_a(s);
		sort_2_b_push_a(s);
	}
	else
	{
		split_a(s, pivot, max);
		split_b(s, min, pivot);
	}
	if (max != s->total)
		push_back(s, min, max, PB);
}

void	quick_sort(t_stacks *s)
{
	split_a(s, 0, s->total);
}
