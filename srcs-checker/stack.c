/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 12:35:38 by omulder        #+#    #+#                */
/*   Updated: 2020/01/14 12:51:43 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <checker.h>

void	print_stack(t_stack *stack)
{
	if (stack == NULL)
		return ;
	ft_printf("%d\n", stack->value);
	print_stack(stack->next);
}

int		push_stack(t_stack **stack, int value)
{
	t_stack		*new;

	new = ft_memalloc(sizeof(t_stack));
	if (new == NULL)
		return (0);
	new->value = value;
	new->next = *stack;
	*stack = new;
	return (1);
}
