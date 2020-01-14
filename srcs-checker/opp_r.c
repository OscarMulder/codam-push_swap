/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   opp_r.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 13:46:10 by omulder        #+#    #+#                */
/*   Updated: 2020/01/14 13:51:51 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>
#include <stdlib.h>

void	opp_ra(t_stack **a)
{
	t_stack	*ptr;
	t_stack	*first;

	if (*a == NULL)
		return ;
	first = *a;
	ptr = *a;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = first;
}

void	opp_rb(t_stack **b)
{
	t_stack	*ptr;
	t_stack	*first;

	if (*b == NULL)
		return ;
	first = *b;
	ptr = *b;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = first;
}

void	opp_rr(t_stack **a, t_stack **b)
{
	opp_ra(a);
	opp_rb(b);
}
