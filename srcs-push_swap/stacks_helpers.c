/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stacks_helpers.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/25 16:27:16 by omulder        #+#    #+#                */
/*   Updated: 2020/02/25 16:28:33 by omulder       ########   odam.nl         */
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

t_stack		*dup_stack(t_stack *s)
{
	t_stack		*dup;
	t_stack		*ptr;

	dup = ft_memalloc(sizeof(t_stack));
	if (dup == NULL)
		return (NULL);
	if (s != NULL)
		ft_memcpy(dup, s, sizeof(t_stack));
	s = s->next;
	ptr = dup;
	while (s != NULL)
	{
		ptr->next = ft_memalloc(sizeof(t_stack));
		if (ptr == NULL)
			return (NULL);
		ft_memcpy(ptr->next, s, sizeof(t_stack));
		s = s->next;
		ptr = ptr->next;
	}
	return (dup);
}

t_stacks	*dup_stacks(t_stacks *s)
{
	t_stacks	*dup;

	dup = (t_stacks*)ft_memalloc(sizeof(t_stacks));
	if (dup == NULL)
		return (NULL);
	dup->size_a = s->size_a;
	dup->size_b = s->size_b;
	dup->op_count = 0;
	dup->total = s->total;
	dup->atop = s->atop;
	dup->amirror = ft_memalloc(sizeof(char) * s->total);
	if (dup->amirror == NULL)
		return (NULL);
	ft_memcpy(dup->amirror, s->amirror, sizeof(char) * s->total);
	dup->a = dup_stack(s->a);
	dup->b = dup_stack(s->b);
	if ((dup->size_a != 0 && dup->a == NULL) ||
		(dup->size_b != 0 && dup->b == NULL))
		return (NULL);
	return (dup);
}

int			add_op(t_stacks *s, int op)
{
	int	ret;

	if (s == NULL)
		return (0);
	ret = add_oplst_item(&(s->oplst), op);
	if (ret == -1)
	{
		delete_stacks(&s);
		exit(1);
	}
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
