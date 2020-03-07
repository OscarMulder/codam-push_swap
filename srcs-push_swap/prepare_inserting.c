/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prepare_inserting.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 15:37:35 by omulder        #+#    #+#                */
/*   Updated: 2020/03/07 17:44:33 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <stddef.h>

static int	get_dividor(t_stacks *s)
{
	if (s->total <= 10)
		return (2);
	if (s->total <= 20)
		return (4);
	if (s->total <= 60)
		return (5);
	if (s->total <= 250)
		return (10);
	if (s->total <= 750)
		return (25);
	else
		return (40);
	return (10);
}

static void	set_init_vars(t_stacks *s, int *blap, int *first, int *prev)
{
	*blap = s->total / get_dividor(s);
	*prev = 0;
	*first = -1;
}

static int	first_if(t_stacks *s, int *prev, int *first, int *blap)
{
	*prev = s->a->pos;
	if (*first == -1)
		*first = *prev;
	opp_do(s, RA);
	*blap += (s->total / get_dividor(s));
	if (*blap >= s->total)
		return (1);
	return (0);
}

static void	second_if(t_stacks *s, int *prev, int *last, int *i)
{
	*prev = s->a->pos;
	(*last)++;
	opp_do(s, RA);
	(*i)++;
}

void		prepare_inserting(t_stacks *s)
{
	int		blap;
	int		first;
	int		last;
	int		prev;
	int		i;

	set_init_vars(s, &blap, &first, &prev);
	i = 0;
	last = 0;
	while (s->size_a > i)
	{
		if (s->a->pos <= blap && s->a->pos > prev)
		{
			last = first_if(s, &prev, &first, &blap);
			i++;
		}
		else if (last > 0 && s->a->pos < first &&
		(s->a->pos > prev && last > 1))
			second_if(s, &prev, &last, &i);
		else
			opp_do(s, PB);
	}
}
