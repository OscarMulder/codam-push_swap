/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   opp_s.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 12:53:45 by omulder        #+#    #+#                */
/*   Updated: 2020/01/14 16:19:56 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>
#include <stdlib.h>

void	opp_sa(t_stack **a)
{
	t_stack	*tmp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = tmp->next->next;
	(*a)->next = tmp;
}

void	opp_sb(t_stack **b)
{
	t_stack	*tmp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = tmp->next->next;
	(*b)->next = tmp;
}

void	opp_ss(t_stack **a, t_stack **b)
{
	opp_sa(a);
	opp_sb(b);
}
