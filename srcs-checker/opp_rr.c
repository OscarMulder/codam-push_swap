/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   opp_rr.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 13:52:07 by omulder        #+#    #+#                */
/*   Updated: 2020/01/14 14:52:44 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>
#include <stdlib.h>

void	opp_rra(t_stack **a)
{
	t_stack	*ptr;
	t_stack *second_last_ptr;

	if (*a == NULL)
		return ;
	ptr = *a;
	while (ptr->next != NULL)
	{
		second_last_ptr = ptr;
		ptr = ptr->next;
	}
	second_last_ptr->next = *a;
	*a = ptr;
}

void	opp_rrb(t_stack **b)
{
	t_stack	*ptr;
	t_stack *second_last_ptr;

	if (*b == NULL)
		return ;
	ptr = *b;
	while (ptr->next != NULL)
	{
		second_last_ptr = ptr;
		ptr = ptr->next;
	}
	second_last_ptr->next = *b;
	*b = ptr;
}

void	opp_rrr(t_stack **a, t_stack **b)
{
	opp_rra(a);
	opp_rrb(b);
}
