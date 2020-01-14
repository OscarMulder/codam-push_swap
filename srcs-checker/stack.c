/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 12:35:38 by omulder        #+#    #+#                */
/*   Updated: 2020/01/14 16:52:12 by omulder       ########   odam.nl         */
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

int		stack_is_sorted(t_stack *a, int prev, int *count)
{
	if (a == NULL && *count != 0)
		return (1);
	if (*count == 0 || a->value > prev)
	{
		(*count)++;
		return (stack_is_sorted(a->next, a->value, count));
	}
	return (0);
}

int		check_stack(t_stack *a, int *count, int argc)
{
	if (a != NULL && !stack_is_sorted(a, a->value, count) && *count != argc - 1)
	{
		ft_printf("KO\n");
		return (1);
	}
	ft_printf("OK\n");
	return (0);
}
