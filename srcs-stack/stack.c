/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 12:35:38 by omulder        #+#    #+#                */
/*   Updated: 2020/02/02 14:36:31 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stack.h>

void	print_stack(t_stack *stack)
{
	if (stack == NULL)
		return ;
	ft_printf("[ value: %d, pos: %d ]\n", stack->value, stack->pos);
	print_stack(stack->next);
}

void	print_both_stacks(t_stack *a, t_stack *b)
{
	if (a == NULL && b == NULL)
	{
		ft_printf("--------------------------------------------------------\n");
		return ;
	}
	if (a != NULL)
		ft_printf("%-15d", a->value);
	else
		ft_printf("%15s", "");
	if (b != NULL)
		ft_printf("%-15d", b->value);
	ft_printf("\n");
	print_both_stacks(a != NULL ? a->next : NULL, b != NULL ? b->next : NULL);
}

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
	if ((a != NULL && !stack_is_sorted(a, a->value, count))
		|| *count != argc - 1)
	{
		ft_printf("KO\n");
		return (1);
	}
	ft_printf("OK\n");
	return (0);
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
