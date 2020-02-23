/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_2_inplace.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 16:18:23 by omulder        #+#    #+#                */
/*   Updated: 2020/02/23 17:01:07 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <stack.h>
#include <stdlib.h>

void	sort_2_a(t_stacks *s)
{
	// ft_dprintf(2, "CALLED: sort_2_a\n");
	if (s->a->pos > s->a->next->pos)
		opp_do(s, SA);
}

void	sort_2_b(t_stacks *s)
{
	// ft_dprintf(2, "CALLED: sort_2_b\n");
	if (s->b->pos < s->b->next->pos)
		opp_do(s, SB);
}

void	sort_2_a_push_b(t_stacks *s)
{
	// ft_dprintf(2, "CALLED: sort_2_a_push_b\n");
	if (s->a->pos < s->a->next->pos)
	{
		opp_do(s, PB);
		opp_do(s, PB);
	}
	else
	{
		opp_do(s, SA);
		opp_do(s, PB);
		opp_do(s, PB);
	}
}

void	sort_2_b_push_a(t_stacks *s)
{
	// ft_dprintf(2, "CALLED: sort_2_b_push_a\n");
	// ft_dprintf(2, "-----------------------sort_2_b_push_a----------------------------\n");
	// // ft_printf("Pivot: %d, Min: %d, Max: %d\n", pivot, min, max);
	// print_stack(s->a);
	// ft_dprintf(2, "------------------------------------------------------\nStack B\n");
	// print_stack(s->b);
	if (s->b->pos < s->b->next->pos)
	{
		opp_do(s, SB);
		opp_do(s, PA);
		opp_do(s, PA);
	}
	else
	{
		opp_do(s, PA);
		opp_do(s, PA);
	}
}
