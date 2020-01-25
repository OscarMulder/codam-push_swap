/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 15:22:41 by omulder        #+#    #+#                */
/*   Updated: 2020/01/25 21:44:44 by omulder       ########   odam.nl         */
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
	(void)argv;
	while (i > 0)
	{
		if (!check_and_push(&(s->a), argv[i]))
			return (return_error());
		i--;
		s->size_a++;
	}
	fake_sort(s);
	less_stupid_sort(s);
	print_oplst(s->oplst);
//	print_stack(s->a);
//	ft_printf("Nb. opps: %d\n", s->op_count);
	delete_stacks(&s);
	return (0);
}
