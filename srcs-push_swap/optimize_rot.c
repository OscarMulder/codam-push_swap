/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   optimize_rot.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/23 18:04:00 by omulder       #+#    #+#                 */
/*   Updated: 2020/08/02 14:26:15 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	set_rot_ops(t_oplst **ptr, int rota, int rotb)
{
	while (rota > 0)
	{
		rota--;
		(*ptr)->op = RA;
		if (rota > 0)
			*ptr = (*ptr)->next;
	}
	while (rotb > 0)
	{
		rotb--;
		(*ptr)->op = RB;
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
		ptr->op = RR;
		if (rota > 0 || rotb > 0)
			ptr = ptr->next;
	}
	set_rot_ops(&ptr, rota, rotb);
	remove_leftover(ptr->next, end);
	ptr->next = end;
}

void		optimize_rot(t_oplst **head)
{
	t_oplst	*end;
	int		rota;
	int		rotb;

	rota = 0;
	rotb = 0;
	end = *head;
	while (end != NULL && (end->op == RA || end->op == RB))
	{
		if (end->op == RA)
			rota++;
		else
			rotb++;
		end = end->next;
	}
	if (rota > 0 && rotb > 0)
		handle_rota_opti(head, end, rota, rotb);
	if (end != NULL)
		optimize_rot(&end->next);
}
