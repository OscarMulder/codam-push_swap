/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insertion_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:00:51 by omulder        #+#    #+#                */
/*   Updated: 2020/03/03 12:50:18 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <stddef.h>

void	prepare_inserting(t_stacks *s)
{
	int		blap;
	int		first;
	int		last;
	int		prev;
	int		i;

	blap = s->total / 11;
	prev = 0;
	i = 0;
	first = -1;
	last = 0;
	while (s->size_a > i)
	{
		if (s->a->pos <= blap && s->a->pos > prev)
		{
			prev = s->a->pos;
			if (first == -1)
				first = prev;
			opp_do(s, RA);
			blap += (s->total / 10);
			if (blap >= s->total)
				last = 1;
			i++;
		}
		else if (last > 0 && s->a->pos < first && (s->a->pos > prev && last > 1))
		{
			prev = s->a->pos;
			last++;
			opp_do(s, RA);
			i++;
		}
		else
			opp_do(s, PB);
	}
}

// int		how_many_are_sorted(t_stack *ptr, int prev, int call)
// {
// 	int		rot;
// 	int		push;

// 	rot = -1;
// 	push = -1;
// 	ft_dprintf(2, "call: %d\n", call);
// 	if (ptr == NULL)
// 		return (0);
// 	if (ptr->pos > prev)
// 	{
// 		prev = ptr->pos;
// 		rot = how_many_are_sorted(ptr->next, prev, ++call);
// 		return (rot + 1);
// 	}
// 	rot = how_many_are_sorted(ptr->next, prev, ++call);
// 	return (rot);
// 	// push = how_many_are_sorted(ptr->next, ptr->pos, call);
// 	// if (rot >= push)
// 	// {
// 	// 	return (rot + 1);
// 	// }
// 	// return (push);
// }

// void	prepare_inserting(t_stacks *s)
// {
// 	char	*torot;
// 	int		wut;

// 	torot = ft_memalloc(sizeof(char) * s->total);
// 	wut = how_many_are_sorted(s->a, -1, 0);
// 	ft_dprintf(2, "wut: %d\n", wut);
// }

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

void	do_best_move(t_stacks *s, int a, int b)
{
	if (b > 0)
	{
		while (b > 0)
		{
			b--;
			opp_do(s, RB);
		}
	}
	else
	{
		while (b < 0)
		{
			b++;
			opp_do(s, RRB);
		}
	}
	while (a > 0)
	{
		if (s->b->pos - 1 < s->atop)
			opp_do(s, RRA);
		else
			opp_do(s, RA);
		a--;
	}
	opp_do(s, PA);
}

int		find_best(t_stacks *s, t_moves *moves)
{
	int		i;
	int		best;

	i = 0;
	best = 0;
	while (i < s->size_b)
	{
		if (moves[i].total < moves[best].total)
			best = i;
		i++;
	}
	return (best);
}

void	calc_move(t_stacks *s, t_stack *bptr, t_moves *moves, int i)
{
	moves[i].a_rot = get_a_rot_count(s, bptr->pos);
	if (i < s->size_b / 2)
	{
		moves[i].b_rot = i;
		if (bptr->pos - 1 < s->atop)
		{
			if (moves[i].a_rot > i)
				moves[i].total = moves[i].a_rot - i;
			else
				moves[i].total = i - moves[i].a_rot;
		}
		else
			moves[i].total = moves[i].a_rot + i;
	}
	else
	{
		moves[i].b_rot = i - s->size_b;
		if (bptr->pos - 1 < s->atop)
		{
			if (moves[i].a_rot > 0 - (moves[i].b_rot))
				moves[i].total = moves[i].a_rot + (moves[i].b_rot);
			else
				moves[i].total = 0 - (moves[i].b_rot) - moves[i].a_rot;
		}
		else
			moves[i].total = moves[i].a_rot - (moves[i].b_rot);
	}
}

void	calc_moves(t_stacks *s, t_moves **moves)
{
	t_stack		*bptr;
	int			i;

	bptr = s->b;
	*moves = (t_moves *)ft_memalloc(sizeof(t_moves) * (s->size_b + 1));
	if (*moves == NULL)
	{
		ft_printf("Error\n");
		free(*moves);
		delete_stacks(&s);
		exit(1);
	}
	i = 0;
	while (bptr != NULL)
	{
		calc_move(s, bptr, *moves, i);
		i++;
		bptr = bptr->next;
	}
}

void	find_and_do_best_move(t_stacks *s)
{
	t_moves		*moves;
	int			best;

	calc_moves(s, &moves);
	best = find_best(s, moves);
	do_best_move(s, moves[best].a_rot, moves[best].b_rot);
	free(moves);
}

void	insertion_sort(t_stacks *s)
{
	int		first_away;

	first_away = 0;
	prepare_inserting(s);
	set_sorted(s);
	while (s->size_b > 0)
	{
		find_and_do_best_move(s);
	}
	while (s->a->pos != 1)
		opp_do(s, RA); // maybe I want RRA sometimesssss
}
