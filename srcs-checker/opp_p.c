/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   opp_p.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 13:44:07 by omulder        #+#    #+#                */
/*   Updated: 2020/01/14 13:44:16 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>
#include <stdlib.h>

void	opp_pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*b == NULL)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}

void	opp_pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
}
