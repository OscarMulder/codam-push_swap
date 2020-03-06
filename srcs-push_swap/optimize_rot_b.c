/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   optimize_rot_b.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/23 18:04:00 by omulder        #+#    #+#                */
/*   Updated: 2020/03/06 14:27:58 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdlib.h>
#include <stddef.h>

static void	set_rot_ops(t_oplst **ptr, int rota, int rotb)
{
	while (rota > 0)
	{
		rota--;
		(*ptr)->op = RB;
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
	}
	set_rot_ops(&ptr, rota, rotb);
	remove_leftover(ptr->next, end);
	if (rota + rotb == 0)
	{
		free(*head);
		*head = end;
	}
	else
		ptr->next = end;
}

void		optimize_rot_b(t_oplst **head)
{
	t_oplst	*end;
	int		rota;
	int		rotb;

	rota = 0;
	rotb = 0;
	end = *head;
	while (end != NULL && (end->op == RB || end->op == RRB))
	{
		if (end->op == RB)
			rota++;
		else
			rotb++;
		end = end->next;
	}
	if (rota > 0 && rotb > 0)
		handle_rota_opti(head, end, rota, rotb);
	if (end != NULL)
		optimize_rot_a(&end->next);
}
