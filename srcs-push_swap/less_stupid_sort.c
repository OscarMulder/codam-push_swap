/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   less_stupid_sort.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/25 18:16:46 by omulder        #+#    #+#                */
/*   Updated: 2020/01/25 20:33:07 by omulder       ########   odam.nl         */
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
	while (i < amount)
	{
		start->op = RRA;
		start = start->next;
		i++;
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
			while (ptr->next != NULL && ptr->op == RA)
			{
				rotcount++;
				ptr = ptr->next;
			}
			if (rotcount > s->size_a / 2)
				reverse_rotations(start_rot, ptr, s->size_a - rotcount);
		}
		ptr = ptr->next;
	}
}

void			less_stupid_sort(t_stacks *s)
{
	int		i;
	int		total;

	i = 0;
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
	print_oplst(s->oplst);
	ft_printf("------------------------------------------------------------\n");
	optimize(s);
}
