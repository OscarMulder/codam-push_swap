/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 15:22:41 by omulder        #+#    #+#                */
/*   Updated: 2020/02/01 20:05:35 by omulder       ########   odam.nl         */
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
	size_t		i;
	t_stacks	*s;

	if (argc < 2)
		return (1);
	i = argc - 1;
	s = new_stacks();
	if (s == NULL)
		return (return_error());
	while (i > 0)
	{
		if (!check_and_push(&(s->a), argv[i]))
			return (return_error());
		i--;
		s->size_a++;
	}
	s->total = s->size_a;
	// print_stack(s->a);
	fake_sort(s);
	stupid_sort(s);
	// quick_sort(s);
	print_oplst(s->oplst);
	//ft_printf("Nb. opps: %d\n", s->op_count);
	// ft_printf("Stack A\n");
	// ft_printf("------------------------------------------------------\nStack B\n");
	// print_stack(s->b);
	delete_stacks(&s);
	return (0);
}
