/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   optimize_push.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/23 19:17:08 by omulder        #+#    #+#                */
/*   Updated: 2020/02/23 20:06:39 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <stdlib.h>

void	handle_push_optimize(t_oplst *end, t_oplst *first, int pusha, int pushb)
{
	t_oplst *ptr;

	ptr = first;
	while (pusha > 0 && pushb > 0)
	{
		pusha--;
		pushb--;
	}
	while (pusha > 0)
	{
		pusha--;
		ptr->op = PA;
		if (pusha > 0)
			ptr = ptr->next;
	}
	while (pushb > 0)
	{
		pushb--;
		ptr->op = PB;
		if (pushb > 0)
			ptr = ptr->next;
	}
	remove_leftover(ptr->next, end);
	ptr->next = end;
}

int		optimize_push(t_oplst *ptr, t_oplst *first, int pusha, int pushb)
{
	if (ptr == NULL)
		return (0);
	if (first == NULL)
	{
		if (ptr->op == PA || ptr->op == PB)
			first = ptr;
	}
	if (ptr->op == PA)
		pusha++;
	else if (ptr->op == PB)
		pushb++;
	else if (first != NULL)
	{
		if (pusha > 0 && pushb > 0)
			handle_push_optimize(ptr, first, pusha, pushb);
		first = NULL;
		pusha = 0;
		pushb = 0;
	}
	if (optimize_push(ptr->next, first, pusha, pushb) == 0 && first != NULL
		&& pusha > 0 && pushb > 0)
		handle_push_optimize(ptr->next, first, pusha, pushb);
	return (1);
}
