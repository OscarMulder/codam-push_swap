/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   oplist_helpers.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/25 17:06:57 by omulder       #+#    #+#                 */
/*   Updated: 2020/08/02 13:37:31 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

int			add_oplst_item(t_oplst **oplst, t_opp op)
{
	t_oplst	*new;

	if (oplst == NULL)
		return (0);
	new = (t_oplst*)ft_memalloc(sizeof(t_oplst));
	if (new == NULL)
		return (-1);
	new->op = op;
	new->next = *oplst;
	*oplst = new;
	return (1);
}

void		delete_oplst(t_oplst **oplst)
{
	if (oplst == NULL || *oplst == NULL)
		return ;
	delete_oplst(&((*oplst)->next));
	free(*oplst);
	*oplst = NULL;
}

char		*op_to_string(t_opp op)
{
	if (op == SA)
		return ("sa");
	else if (op == SB)
		return ("sb");
	else if (op == SS)
		return ("ss");
	else if (op == PA)
		return ("pa");
	else if (op == PB)
		return ("pb");
	else if (op == RA)
		return ("ra");
	else if (op == RB)
		return ("rb");
	else if (op == RR)
		return ("rr");
	else if (op == RRA)
		return ("rra");
	else if (op == RRB)
		return ("rrb");
	else if (op == RRR)
		return ("rrr");
	return ("");
}

int			count_oplist(t_oplst *ptr)
{
	if (ptr == NULL)
		return (0);
	return (1 + count_oplist(ptr->next));
}

void		print_oplst(t_oplst *oplst)
{
	if (oplst == NULL)
		return ;
	print_oplst(oplst->next);
	ft_printf("%s\n", op_to_string(oplst->op));
}
