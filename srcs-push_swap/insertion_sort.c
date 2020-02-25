/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insertion_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:00:51 by omulder        #+#    #+#                */
/*   Updated: 2020/02/25 11:55:34 by omulder       ########   odam.nl         */
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

int		find_max(t_stack *a)
{
	int		max;

	max = a->pos;
	while (a->next != NULL)
	{
		if (a->pos > max)
			max = a->pos;
		a = a->next;
	}
	return (max);
}

void	set_sorted(t_stacks *s)
{
	t_stack *ptr;

	ptr = s->a;
	if (ptr == NULL)
		return ;
	s->atop = ptr->pos - 1;
	while (ptr != NULL)
	{
		s->amirror[ptr->pos - 1] = TRUE;
		ptr = ptr->next;
	}
}

int		get_a_rot_count(t_stacks *s, int bpos)
{
	int count;
	int	i;

	count = 0;
	if (bpos - 1 < s->atop)
	{
		i = bpos;
		while (i < s->atop)
		{
			if (s->amirror[i])
				count++;
			i++;
		}
		return (count);
	}
	i = s->atop + 1;
	count = 1;
	while (i < bpos - 1)
	{
		if (s->amirror[i])
			count++;
		i++;
	}
	return (count);
}

void	do_best_move(t_stacks *s)
{
	t_moves		*moves;
	t_stack		*bptr;
	int			i;
	int			best;

	i = 0;
	bptr = s->b;
	moves = (t_moves *)ft_memalloc(sizeof(t_moves) * (s->size_b + 1));
	if (moves == NULL)
		exit(1); //maybe error youknow
	while (bptr != NULL)
	{
		moves[i].a_rot = get_a_rot_count(s, bptr->pos);
		if (i < s->size_b / 2)
		{
			moves[i].b_rot = i;
			moves[i].total = moves[i].a_rot + i;
		}
		else
		{
			moves[i].b_rot = i - s->size_b;
			moves[i].total = moves[i].a_rot + i;
		}
		i++;
		bptr = bptr->next;
	}
	i = 0;
	best = 0;
	while (i < s->size_b)
	{
		if (moves[i].total < moves[best].total)
			best = i;
		i++;
	}
	if (moves[best].b_rot > 0)
	{
		while (moves[best].b_rot > 0)
		{
			moves[best].b_rot--;
			opp_do(s, RB);
		}
	}
	else if (moves[best].b_rot != 0)
	{
		while (moves[best].b_rot < 0)
		{
			moves[best].b_rot++;
			opp_do(s, RRB);
		}
	}
	if (s->b->pos -1 < s->atop)
	{
		while (moves[best].a_rot > 0)
		{
			opp_do(s, RRA);
			moves[best].a_rot--;
		}
	}
	else
	{
		while (moves[best].a_rot > 0)
		{
			opp_do(s, RA);
			moves[best].a_rot--;
		}
	}
	opp_do(s, PA);
}

void	insertion_sort(t_stacks *s)
{
	int		rotcounta;
	int		first_away;

	first_away = 0;
	prepare_inserting(s);
	set_sorted(s);
	while (s->size_b > 0)
	{
		do_best_move(s);
	}
}
