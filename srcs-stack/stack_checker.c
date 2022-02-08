/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_checker.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/07 18:24:06 by omulder       #+#    #+#                 */
/*   Updated: 2022/02/08 16:51:56 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>
#include <libft.h>

int	stack_is_sorted(t_stack *a, int prev, int *count)
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

int	check_stack(t_stack *a, int *count, int argc)
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
