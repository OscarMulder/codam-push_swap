/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stacks_helpers.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/25 16:27:16 by omulder        #+#    #+#                */
/*   Updated: 2020/01/25 17:51:14 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stack.h>
#include <libft.h>
#include <stdlib.h>

t_stacks	*new_stacks(void)
{
	t_stacks	*new;

	new = (t_stacks*)ft_memalloc(sizeof(t_stacks));
	new->a = NULL;
	return (new);
}

int			add_op(t_stacks *s, int op)
{
	int	ret;

	if (s == NULL)
		return (0);
	ret = add_oplst_item(&(s->oplst), op);
	if (ret == 1)
		s->op_count++;
	return (ret);
}

void		delete_stacks(t_stacks **s)
{
	if (s == NULL)
		return ;
	delete_stack(&((*s)->a));
	delete_stack(&((*s)->b));
	delete_oplst(&((*s)->oplst));
	free(*s);
	*s = NULL;
}
