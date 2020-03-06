/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   optimize_rev_rot.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/23 18:04:00 by omulder        #+#    #+#                */
/*   Updated: 2020/03/06 14:45:20 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stddef.h>
#include <stdlib.h>

static void	set_rot_ops(t_oplst **ptr, int rota, int rotb)
{
	while (rota > 0)
	{
		rota--;
		(*ptr)->op = RRA;
		if (rota > 0)
			*ptr = (*ptr)->next;
	}
	while (rotb > 0)
	{
		rotb--;
		(*ptr)->op = RRB;
		if (rotb > 0)
			*ptr = (*ptr)->next;
	}
}

static void	handle_rota_opti(t_oplst **head, t_oplst *end, int rota, int rotb)
{
	t_oplst	*ptr;

	ptr = *head;
	while (rota > 0 && rotb > 0)
	{
		rota--;
		rotb--;
		ptr->op = RRR;
		if (rota > 0 || rotb > 0)
			ptr = ptr->next;
	}
	set_rot_ops(&ptr, rota, rotb);
	remove_leftover(ptr->next, end);
	ptr->next = end;
}

void		optimize_rev_rot(t_oplst **head)
{
	t_oplst	*end;
	int		rota;
	int		rotb;

	rota = 0;
	rotb = 0;
	end = *head;
	while (end != NULL && (end->op == RRA || end->op == RRB))
	{
		if (end->op == RRA)
			rota++;
		else
			rotb++;
		end = end->next;
	}
	if (rota > 0 && rotb > 0)
		handle_rota_opti(head, end, rota, rotb);
	if (end != NULL)
		optimize_rev_rot(&end->next);
}
