/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 12:35:38 by omulder       #+#    #+#                 */
/*   Updated: 2020/03/07 18:24:38 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stack.h>

int		check_and_push(t_stack **stack, char *value)
{
	if (ft_aisint(value) && !value_exists(*stack, ft_atoi(value)))
		return (push_stack(stack, ft_atoi(value)));
	return (0);
}

int		push_stack(t_stack **stack, int value)
{
	t_stack		*new;

	new = ft_memalloc(sizeof(t_stack));
	if (new == NULL)
		return (0);
	new->value = value;
	new->next = *stack;
	new->pos = -1;
	*stack = new;
	return (1);
}

int		value_exists(t_stack *a, int value)
{
	if (a == NULL)
		return (0);
	if (a->value == value)
		return (1);
	return (value_exists(a->next, value));
}

void	delete_stack(t_stack **a)
{
	if (a == NULL || *a == NULL)
		return ;
	delete_stack(&((*a)->next));
	free(*a);
	*a = NULL;
}
