/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   opp_r.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 13:46:10 by omulder        #+#    #+#                */
/*   Updated: 2020/01/26 21:42:05 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>
#include <stdlib.h>

void	opp_ra(t_stack **a)
{
	t_stack	*ptr;
	t_stack	*first;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	ptr = *a;
	while (ptr->next != NULL)
		ptr = ptr->next;
	*a = (*a)->next;
	first->next = NULL;
	ptr->next = first;
}

void	opp_rb(t_stack **b)
{
	t_stack	*ptr;
	t_stack	*first;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	first = *b;
	ptr = *b;
	while (ptr->next != NULL)
		ptr = ptr->next;
	*b = (*b)->next;
	first->next = NULL;
	ptr->next = first;
}

void	opp_rr(t_stack **a, t_stack **b)
{
	opp_ra(a);
	opp_rb(b);
}
