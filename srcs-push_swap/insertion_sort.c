/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insertion_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:00:51 by omulder        #+#    #+#                */
/*   Updated: 2020/02/24 21:28:37 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <stddef.h>

void	prepare_inserting(t_stacks *s)
{
	int		blap;
	int		prev;
	int		i;

	blap = s->total / 10;
	prev = 0;
	i = 0;
	while (s->size_a > i)
	{
		if (s->a->pos <= blap && s->a->pos > prev)
		{
			prev = s->a->pos;
			opp_do(s, RA);
			blap += (s->total / 10);
			i++;
		}
		else
			opp_do(s, PB);
	}
}

int		last_pos(t_stack *a)
{
	while (a->next != NULL)
		a = a->next;
	return (a->pos);
}

int		find_min(t_stack *a)
{
	int		min;

	min = a->pos;
	while (a->next != NULL)
	{
		if (a->pos < min)
			min = a->pos;
		a = a->next;
	}
	return (min);
}

void	insertion_sort(t_stacks *s)
{
	prepare_inserting(s);
	
}
