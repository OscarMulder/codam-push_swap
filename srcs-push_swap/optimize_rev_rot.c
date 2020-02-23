/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   optimize_rev_rot.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/23 18:04:00 by omulder        #+#    #+#                */
/*   Updated: 2020/02/23 19:20:01 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stddef.h>

static void	handle_rot_optimize(t_oplst *end, t_oplst *first, int rota, int rotb)
{
	t_oplst *ptr;

	ptr = first;
	while (rota > 0 && rotb > 0)
	{
		rota--;
		rotb--;
		ptr->op = RRR;
		ptr = ptr->next;
	}
	while (rota > 0)
	{
		rota--;
		ptr->op = RRA;
		if (rota > 0 || rotb > 0)
			ptr = ptr->next;
	}
	while (rotb > 0)
	{
		rotb--;
		ptr->op = RRB;
		if (rotb > 0)
			ptr = ptr->next;
	}
	remove_leftover(ptr->next, end);
	ptr->next = end;
}

int			optimize_rev_rot(t_oplst *ptr, t_oplst *first, int rota, int rotb)
{
	if (ptr == NULL)
		return (0);
	if (first == NULL)
	{
		if (ptr->op == RRA || ptr->op == RRB)
			first = ptr;
	}
	if (ptr->op == RRA)
		rota++;
	else if (ptr->op == RRB)
		rotb++;
	else if (first != NULL)
	{
		if (rota > 0 && rotb > 0)
			handle_rot_optimize(ptr, first, rota, rotb);
		first = 0;
		rota = 0;
		rotb = 0;
	}
	if (optimize_rot(ptr->next, first, rota, rotb) == 0 && first != NULL
		&& rota > 0 && rotb > 0)
		handle_rot_optimize(ptr, first, rota, rotb);
	return (1);
}
