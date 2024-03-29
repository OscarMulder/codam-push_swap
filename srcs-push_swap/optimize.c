/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   optimize.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/23 17:07:09 by omulder       #+#    #+#                 */
/*   Updated: 2022/02/08 16:48:56 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdlib.h>

void	remove_leftover(t_oplst *ptr, t_oplst *end)
{
	if (ptr == NULL || ptr == end)
		return ;
	remove_leftover(ptr->next, end);
	free(ptr);
}

int	optimize_oplist(t_oplst **oplst)
{
	optimize_rot(oplst);
	optimize_rev_rot(oplst);
	optimize_rot_a(oplst);
	optimize_rot_b(oplst);
	optimize_push(oplst);
	return (1);
}
