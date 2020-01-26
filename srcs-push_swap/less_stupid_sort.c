/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   less_stupid_sort.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/25 18:16:46 by omulder        #+#    #+#                */
/*   Updated: 2020/01/26 19:31:25 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <stack.h>
#include <stdlib.h>

static void		reverse_rotations(t_oplst *start, t_oplst *end, int amount)
{
	int		i;
	t_oplst	*ptr;
	t_oplst *tmp;

	i = 0;
	while (i <= amount)
	{
		start->op = RRA;
		i++;
		if (i <= amount)
			start = start->next;
	}
	ptr = start->next;
	while (ptr != end)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
	start->next = end;
}

static void		optimize(t_stacks *s)
{
	t_oplst		*ptr;
	t_oplst		*start_rot;
	int			rotcount;

	ptr = s->oplst;
	while (ptr != NULL)
	{
		if (ptr->op == RA)
		{
			rotcount = 1;
			start_rot = ptr;
			while (ptr != NULL && ptr->op == RA)
			{
				rotcount++;
				ptr = ptr->next;
			}
			if (rotcount > s->size_a / 2)
				reverse_rotations(start_rot, ptr, s->size_a - rotcount);
		}
		if (ptr != NULL)
			ptr = ptr->next;
	}
}

void			less_stupid_sort(t_stacks *s)
{
	stupid_sort(s);
	// print_oplst(s->oplst);
	// ft_printf("------------------------------------------------------------\n");
	optimize(s);
}
