/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 15:22:41 by omulder        #+#    #+#                */
/*   Updated: 2020/02/23 18:30:56 by omulder       ########   odam.nl         */
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
	fake_sort(s);
	quick_sort(s);
	// stupid_sort(s);
	ft_dprintf(2, "Nb. opps: %d\n", s->op_count);
	optimize_oplist(s->oplst);
	ft_dprintf(2, "Nb. optimized opps: %d\n", count_oplist(s->oplst));
	print_oplst(s->oplst);
	delete_stacks(&s);
	return (0);
}

	// print_stack(s->a);
	// stupid_sort(s);
	// ft_dprintf(2, "Stack A\n");
	// print_stack(s->a);
	// ft_dprintf(2, "------------------------------------------------------\nStack B\n");
	// print_stack(s->b);