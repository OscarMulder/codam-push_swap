/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fake_sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/25 18:26:16 by omulder        #+#    #+#                */
/*   Updated: 2020/01/25 18:44:21 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <stack.h>
#include <stdlib.h>

/*
** Doesn't really sort, just adds positions, should have better name.
*/

static void		loop_bois(t_stack **smolboi, t_stack **prevsmolboi)
{
	t_stack		*ptr;

	ptr = *smolboi;
	while (ptr != NULL)
	{
		if (*prevsmolboi == NULL)
		{
			if (ptr->value < (*smolboi)->value)
				*smolboi = ptr;
		}
		else
		{
			if (ptr->value > (*prevsmolboi)->value &&
				ptr->value < (*smolboi)->value)
				*smolboi = ptr;
		}
		ptr = ptr->next;
	}
}

void	fake_sort(t_stacks *s)
{
	t_stack		*smolboi;
	t_stack		*prevsmolboi;
	int			i;

	prevsmolboi = NULL;
	i = 0;
	while (i < s->size_a)
	{
		smolboi = s->a;
		while (smolboi != NULL && smolboi->pos != -1)
			smolboi = smolboi->next;
		loop_bois(&smolboi, &prevsmolboi);
		smolboi->pos = i;
		prevsmolboi = smolboi;
		i++;
	}
}
