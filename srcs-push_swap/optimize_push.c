/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   optimize_push.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/23 19:17:08 by omulder        #+#    #+#                */
/*   Updated: 2020/03/03 14:59:04 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <stdlib.h>

void	set_push_ops(t_oplst **ptr, int pusha, int pushb)
{
	while (pusha > 0)
	{
		pusha--;
		(*ptr)->op = PA;
		if (pusha > 0)
			*ptr = (*ptr)->next;
	}
	while (pushb > 0)
	{
		pushb--;
		(*ptr)->op = PB;
		if (pushb > 0)
			*ptr = (*ptr)->next;
	}
}

void	handle_push_optimize(t_oplst **head, t_oplst *end, int pusha, int pushb)
{
	t_oplst	*ptr;

	ptr = *head;
	while (pusha > 0 && pushb > 0)
	{
		pusha--;
		pushb--;
	}
	set_push_ops(&ptr, pusha, pushb);
	remove_leftover(ptr->next, end);
	if (pusha + pushb == 0)
	{
		free(*head);
		*head = end;
	}
	else
		ptr->next = end;
}

void	optimize_push(t_oplst **head)
{
	t_oplst	*end;
	int		pusha;
	int		pushb;

	pusha = 0;
	pushb = 0;
	end = *head;
	while (end != NULL && (end->op == PA || end->op == PB))
	{
		if (end->op == PA)
			pusha++;
		else
			pushb++;
		end = end->next;
	}
	if (pusha > 0 && pushb > 0)
		handle_push_optimize(head, end, pusha, pushb);
	if (end != NULL)
		optimize_push(&end->next);
}
