/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 12:35:38 by omulder       #+#    #+#                 */
/*   Updated: 2022/02/08 16:51:48 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stack.h>

int	check_and_push(t_stack **stack, char *value)
{
	char	*tvalue;
	int		num;

	if (!ft_isnumeric(value))
		return (0);
	tvalue = ft_trim_num(value);
	if (tvalue == NULL)
		return (-1);
	if (!ft_aisint32(tvalue))
	{
		free(tvalue);
		return (0);
	}
	num = ft_atoi(tvalue);
	free(tvalue);
	if (!value_exists(*stack, num))
		return (push_stack(stack, num));
	return (0);
}

int	push_stack(t_stack **stack, int value)
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

int	value_exists(t_stack *a, int value)
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
