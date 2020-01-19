/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 15:22:41 by omulder        #+#    #+#                */
/*   Updated: 2020/01/19 15:49:05 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <stack.h>
#include <stdlib.h>

static int	return_error(void)
{
	ft_printf("Error\n");
	return (1);
}

int			main(int argc, char **argv)
{
	size_t	i;
	t_stack	*a;
	t_stack *b;

	if (argc < 2)
		return (1);
	i = argc - 1;
	a = NULL;
	b = NULL;
	while (i > 0)
	{
		if (!check_and_push(&a, argv[i]))
			return (return_error());
		i--;
	}
    print_stack(a);
}
