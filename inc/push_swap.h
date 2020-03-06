/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 15:13:33 by omulder        #+#    #+#                */
/*   Updated: 2020/03/06 14:28:11 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stack.h>
# include <stddef.h>
# define TRUE 1
# define FALSE 0

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

typedef struct	s_moves
{
	int		a_rot;
	int		b_rot;
	int		total;
}				t_moves;

typedef struct	s_stacks {
	int			size_a;
	int			size_b;
	int			op_count;
	int			total;
	int			atop;
	char		*amirror;
	t_stack		*a;
	t_stack		*b;
	t_oplst		*oplst;
}				t_stacks;

int		return_error(void);

void	fake_sort(t_stacks *a);
int		small_sort(t_stacks *s);
void	stupid_sort(t_stacks *s);
void	less_stupid_sort(t_stacks *s);
void	quick_sort(t_stacks *s);
void	sort_2_a(t_stacks *s);
void	sort_2_b(t_stacks *s);
void	sort_2_a_push_b(t_stacks *s);
void	sort_2_b_push_a(t_stacks *s);
void	sort_3_a(t_stacks *s);
void	sort_3_b(t_stacks *s);
void	splitsort_a(t_stacks *s, int min, int max);
void	splitsort_b(t_stacks *s, int min, int max);
void	split_a(t_stacks *s, int min, int max, int pivot);
void	split_b(t_stacks *s, int min, int max, int pivot);
void	find_and_do_best_move(t_stacks *s);
void	set_sorted(t_stacks *s);
/*
** First, push 90% of A to B, leave a balanced 10% sorted on A
** Then, insert efficiently into A, skipping if inserting requires to many
** rotations.
** Lastly, insert the last numbers regardless of the amount of rotations.
** Rotate stack A so the smallest number is at the top.
*/
void	insertion_sort(t_stacks *s);

/*
** Optimize
*/

int		optimize_oplist(t_oplst **oplst);
void	remove_leftover(t_oplst *ptr, t_oplst *end);
void	optimize_push(t_oplst **head);
void	optimize_rot(t_oplst **head);
void	optimize_rev_rot(t_oplst **head);
void	optimize_rot_a(t_oplst **head);
void	optimize_rot_b(t_oplst **head);

/*
** opp_do
*/

int		opp_do(t_stacks *s, t_opp op);
char	*op_to_string(t_opp op);

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
int			count_oplist(t_oplst *ptr);

/*
** Stacks helpers
*/

t_stacks	*new_stacks(void);
int			add_op(t_stacks *s, int op);
void		delete_stacks(t_stacks **s);
t_stacks	*dup_stacks(t_stacks *s);

#endif
