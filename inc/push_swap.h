/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 15:13:33 by omulder        #+#    #+#                */
/*   Updated: 2020/01/27 15:03:26 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stack.h>

typedef enum	e_opp {
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}				t_opp;

typedef struct	s_oplst
{
	t_opp			op;
	struct s_oplst	*next;
}				t_oplst;

typedef struct	s_stacks {
	int			size_a;
	int			size_b;
	int			op_count;
	int			total;
	t_stack		*a;
	t_stack		*b;
	t_oplst		*oplst;
}				t_stacks;

void	fake_sort(t_stacks *a);
void	stupid_sort(t_stacks *s);
void	less_stupid_sort(t_stacks *s);
void	quick_sort(t_stacks *s);
void	split_a(t_stacks *s, int min, int max);
void	sort_2_a(t_stacks *s);
void	sort_2_b(t_stacks *s);
void	sort_2_a_push_b(t_stacks *s);
void	sort_2_b_push_a(t_stacks *s);
void	sort_3_a(t_stacks *s);
void	sort_3_b(t_stacks *s);

/*
** opp_do
*/

int		opp_do(t_stacks *s, t_opp op);

/*
** Operation wrappers
*/

void	opp_wrap_sa(t_stacks *s);
void	opp_wrap_sb(t_stacks *s);
void	opp_wrap_ss(t_stacks *s);
void	opp_wrap_pa(t_stacks *s);
void	opp_wrap_pb(t_stacks *s);
void	opp_wrap_ra(t_stacks *s);
void	opp_wrap_rb(t_stacks *s);
void	opp_wrap_rr(t_stacks *s);
void	opp_wrap_rra(t_stacks *s);
void	opp_wrap_rrb(t_stacks *s);
void	opp_wrap_rrr(t_stacks *s);

/*
** Oplist helpers
*/

int			add_oplst_item(t_oplst **oplst, t_opp op);
void		delete_oplst(t_oplst **oplst);
void		print_oplst(t_oplst *oplst);

/*
** Stacks helpers
*/

t_stacks	*new_stacks(void);
int			add_op(t_stacks *s, int op);
void		delete_stacks(t_stacks **s);

#endif
