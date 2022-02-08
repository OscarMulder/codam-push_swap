/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insertion_helpers.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 15:21:18 by omulder       #+#    #+#                 */
/*   Updated: 2022/02/08 16:45:33 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	set_sorted(t_stacks *s)
{
	t_stack	*ptr;

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

int	calc_a_rot_count(t_stacks *s, int bpos)
{
	int	count;
	int	i;

	count = 0;
	i = s->atop;
	while (i < s->total && i != bpos)
	{
		if (s->amirror[i])
			count++;
		i++;
	}
	if (i == bpos)
		return (count);
	i = 0;
	while (i <= s->atop && i != bpos)
	{
		if (s->amirror[i])
			count++;
		i++;
	}
	return (count);
}

int	get_a_rot_count(t_stacks *s, int bpos)
{
	int		count;

	count = calc_a_rot_count(s, bpos);
	if (count > s->size_a / 2)
		count = count - s->size_a;
	return (count);
}

void	do_best_move(t_stacks *s, int a, int b)
{
	while (a > 0)
	{
		a--;
		opp_do(s, RA);
	}
	while (a < 0)
	{
		a++;
		opp_do(s, RRA);
	}
	while (b > 0)
	{
		b--;
		opp_do(s, RB);
	}
	while (b < 0)
	{
		b++;
		opp_do(s, RRB);
	}
	opp_do(s, PA);
}

int	find_best(t_stacks *s, t_moves *moves)
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
