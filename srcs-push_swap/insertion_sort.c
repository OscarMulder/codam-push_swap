/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insertion_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:00:51 by omulder        #+#    #+#                */
/*   Updated: 2020/03/06 16:51:00 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <stddef.h>

static void	calc_reverse(t_stacks *s, t_stack *bptr, t_moves *moves, int i)
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

static void	calc_move(t_stacks *s, t_stack *bptr, t_moves *moves, int i)
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
		calc_reverse(s, bptr, moves, i);
}

static void	calc_moves(t_stacks *s, t_moves **moves)
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
	rot_a_sorted(s);
}
