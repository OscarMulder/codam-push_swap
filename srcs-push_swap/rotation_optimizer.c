/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotation_optimizer.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/23 18:04:00 by omulder        #+#    #+#                */
/*   Updated: 2020/02/23 18:22:22 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stddef.h>

void	handle_rot_optimize(t_oplst *end, t_oplst *firstrot, int rota, int rotb)
{
	t_oplst *ptr;

	ptr = firstrot;
	while (rota > 0 && rotb > 0)
	{
		rota--;
		rotb--;
		ptr->op = RR;
		ptr = ptr->next;
	}
	while (rota > 0)
	{
		rota--;
		ptr->op = RA;
		if (rota > 0 || rotb > 0)
			ptr = ptr->next;
	}
	while (rotb > 0)
	{
		rotb--;
		ptr->op = RB;
		if (rotb > 0)
			ptr = ptr->next;
	}
	remove_leftover(ptr->next, end);
	ptr->next = end;
}

int		optimize_rot(t_oplst *ptr, t_oplst *firstrot, int rota, int rotb)
{
	if (ptr == NULL)
		return (0);
	if (firstrot == NULL)
	{
		if (ptr->op == RA || ptr->op == RB)
			firstrot = ptr;
	}
	if (ptr->op == RA)
		rota++;
	else if (ptr->op == RB)
		rotb++;
	else if (firstrot != NULL)
	{
		if (rota > 0 && rotb > 0)
			handle_rot_optimize(ptr, firstrot, rota, rotb);
		firstrot = 0;
		rota = 0;
		rotb = 0;
	}
	if (optimize_rot(ptr->next, firstrot, rota, rotb) == 0 && firstrot != NULL
		&& rota > 0 && rotb > 0)
		handle_rot_optimize(ptr, firstrot, rota, rotb);
	return (1);
}
