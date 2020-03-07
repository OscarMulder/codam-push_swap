/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_helpers.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/07 18:04:29 by omulder        #+#    #+#                */
/*   Updated: 2020/03/07 18:04:40 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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

void	rot_a_sorted(t_stacks *s)
{
	int		i;
	t_stack	*ptr;

	ptr = s->a;
	i = 0;
	while (ptr && ptr->pos != 1)
	{
		i++;
		ptr = ptr->next;
	}
	if (i <= s->size_a / 2)
	{
		while (s->a->pos != 1)
			opp_do(s, RA);
	}
	else
	{
		while (s->a->pos != 1)
			opp_do(s, RRA);
	}
}
