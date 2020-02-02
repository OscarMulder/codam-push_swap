/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stupid_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/25 18:16:46 by omulder        #+#    #+#                */
/*   Updated: 2020/02/01 20:05:04 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <stack.h>
#include <stdlib.h>

void		stupid_sort(t_stacks *s)
{
	int		i;
	int		total;

	i = 1;
	total = s->size_a;
	while (i < total - 1)
	{
		while (s->a->pos != i)
			opp_do(s, RA);
		opp_do(s, PB);
		i++;
	}
	while (s->b != NULL)
		opp_do(s, PA);
}
