/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insertion_helpers.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 15:21:18 by omulder        #+#    #+#                */
/*   Updated: 2020/03/06 16:57:33 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <stddef.h>

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
