/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_sorted_positions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 15:19:26 by omulder       #+#    #+#                 */
/*   Updated: 2020/03/06 16:04:34 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <stack.h>
#include <stdlib.h>

static void	find_next_smal(t_stack **smal, t_stack **prev_smal)
{
	t_stack		*ptr;

	ptr = *smal;
	while (ptr != NULL)
	{
		if (*prev_smal == NULL)
		{
			if (ptr->value < (*smal)->value)
				*smal = ptr;
		}
		else
		{
			if (ptr->value > (*prev_smal)->value &&
				ptr->value < (*smal)->value)
				*smal = ptr;
		}
		ptr = ptr->next;
	}
}

void		add_sorted_positions(t_stacks *s)
{
	t_stack		*smal;
	t_stack		*prev_smal;
	int			i;

	prev_smal = NULL;
	i = 1;
	while (i <= s->size_a)
	{
		smal = s->a;
		while (smal != NULL && smal->pos != -1)
			smal = smal->next;
		find_next_smal(&smal, &prev_smal);
		smal->pos = i;
		prev_smal = smal;
		i++;
	}
}
