/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   optimize.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/23 17:07:09 by omulder        #+#    #+#                */
/*   Updated: 2020/02/25 11:58:16 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <stdlib.h>

void	remove_leftover(t_oplst *ptr, t_oplst *end)
{
	if (ptr == NULL || ptr == end)
		return ;
	remove_leftover(ptr->next, end);
	free(ptr);
}

static void	free_2(t_oplst **oplst, t_oplst *ptr)
{
	free(ptr->next);
	free(ptr);
	*oplst = (*oplst)->next->next;
}

int			optimize_swaps(t_oplst **oplst)
{
	t_oplst *ptr;

	ptr = *oplst;
	if (ptr == NULL)
		return (0);
	if (ptr->op == SA)
	{
		if (ptr->next != NULL && ptr->next->op == SA)
			free_2(oplst, ptr);
	}
	else if (ptr->op == SB)
	{
		if (ptr->next != NULL && ptr->next->op == SB)
			free_2(oplst, ptr);
	}
	else if (ptr->op == SA || ptr->op == SB)
	{
		if (ptr->next != NULL && (ptr->next->op == SA || ptr->next->op == SB)
			&& ptr->op != ptr->next->op)
		{
			ptr = ptr->next;
			(*oplst)->next = ptr->next;
			(*oplst)->op = SS;
			free(ptr);
		}
	}
	optimize_swaps(&((*oplst)->next));
	return (1);
}

int		optimize_oplist(t_oplst **oplst)
{
	optimize_rot(*oplst, NULL, 0, 0);
	optimize_rev_rot(*oplst, NULL, 0, 0);
	optimize_rot_a(*oplst, NULL, 0, 0);
	optimize_rot_b(*oplst, NULL, 0, 0);
	optimize_swaps(oplst);
	optimize_push(oplst);
	return (1);
}
