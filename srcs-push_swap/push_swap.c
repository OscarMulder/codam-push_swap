/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 15:22:41 by omulder        #+#    #+#                */
/*   Updated: 2020/03/06 14:10:14 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <stack.h>
#include <stdlib.h>

int		return_error(void)
{
	ft_printf("Error\n");
	return (1);
}

void		sort_and_print(t_stacks *s)
{
	t_stacks	*quick;
	t_stacks	*insert;
	t_stacks	*small;
	int			smoll;

	quick = dup_stacks(s);
	insert = dup_stacks(s);
	small = dup_stacks(s);
	if (quick == NULL || insert == NULL || small == NULL)
	{
		return_error();
		exit(1);
	}
	smoll = small_sort(small);
	quick_sort(quick);
	insertion_sort(insert);
	optimize_oplist(&(quick->oplst));
	optimize_oplist(&(insert->oplst));
	quick->op_count = count_oplist(quick->oplst);
	insert->op_count = count_oplist(insert->oplst);
	if (smoll)
	{
		optimize_oplist(&(small->oplst));
		small->op_count = count_oplist(small->oplst);
		if (small->op_count <= quick->op_count && small->op_count <= insert->op_count)
		{
			// ft_dprintf(2, "SMALLSORT\n");
			print_oplst(small->oplst);
		}
		else
		{
			delete_stacks(&small);
			smoll = 0;
		}
	}
	if (!smoll && quick->op_count <= insert->op_count)
	{
		// ft_dprintf(2, "QUICKSORT\n");
		print_oplst(quick->oplst);
	}
	else if (!smoll)
	{
		// ft_dprintf(2, "INSERTIONSORT\n");
		print_oplst(insert->oplst);
	}
	delete_stacks(&quick);
	delete_stacks(&insert);
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
	s->amirror = ft_memalloc(sizeof(char) * s->total);
	if (!s->amirror)
		exit(return_error());
	fake_sort(s);
	sort_and_print(s);
	delete_stacks(&s);
	return (0);
}
