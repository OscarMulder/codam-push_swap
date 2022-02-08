/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 15:13:33 by omulder       #+#    #+#                 */
/*   Updated: 2022/02/08 16:52:55 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stack.h>
# include <stddef.h>
# define TRUE 1
# define FALSE 0

typedef enum e_opp {
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

typedef struct s_oplst
{
	t_opp			op;
	struct s_oplst	*next;
}				t_oplst;

typedef struct s_moves
{
	int			a_rot;
	int			b_rot;
	int			total;
}				t_moves;

typedef struct s_stacks {
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

/*
** Quick Sort
*/
void			quick_sort(t_stacks *s);
void			sort_2_a(t_stacks *s);
void			sort_2_b(t_stacks *s);
void			sort_2_a_push_b(t_stacks *s);
void			sort_2_b_push_a(t_stacks *s);
void			sort_3_a(t_stacks *s);
void			sort_3_b(t_stacks *s);
void			splitsort_a(t_stacks *s, int min, int max);
void			splitsort_b(t_stacks *s, int min, int max);
void			split_a(t_stacks *s, int min, int max, int pivot);
void			split_b(t_stacks *s, int min, int max, int pivot);
void			find_and_do_best_move(t_stacks *s);
void			push_back(t_stacks *s, int min, int max, t_opp push);

/*
** Insertion Sort
*/

void			insertion_sort(t_stacks *s);
void			set_sorted(t_stacks *s);
void			rot_a_sorted(t_stacks *s);
void			prepare_inserting(t_stacks *s);
void			add_sorted_positions(t_stacks *a);
int				find_best(t_stacks *s, t_moves *moves);
int				get_a_rot_count(t_stacks *s, int bpos);
void			do_best_move(t_stacks *s, int a, int b);

/*
** Small Sort
*/

int				small_sort(t_stacks *s);
int				find_min(t_stack *a);
int				find_mid(t_stack *a, int min, int max);
int				find_max(t_stack *a);

/*
** Errors
*/

int				return_error(void);

/*
** Optimize
*/

int				optimize_oplist(t_oplst **oplst);
void			remove_leftover(t_oplst *ptr, t_oplst *end);
void			optimize_push(t_oplst **head);
void			optimize_rot(t_oplst **head);
void			optimize_rev_rot(t_oplst **head);
void			optimize_rot_a(t_oplst **head);
void			optimize_rot_b(t_oplst **head);

/*
** opp_do
*/

int				opp_do(t_stacks *s, t_opp op);
char			*op_to_string(t_opp op);

/*
** Operation wrappers
*/

void			opp_wrap_sa(t_stacks *s);
void			opp_wrap_sb(t_stacks *s);
void			opp_wrap_ss(t_stacks *s);
void			opp_wrap_pa(t_stacks *s);
void			opp_wrap_pb(t_stacks *s);
void			opp_wrap_ra(t_stacks *s);
void			opp_wrap_rb(t_stacks *s);
void			opp_wrap_rr(t_stacks *s);
void			opp_wrap_rra(t_stacks *s);
void			opp_wrap_rrb(t_stacks *s);
void			opp_wrap_rrr(t_stacks *s);

/*
** Oplist helpers
*/

int				add_oplst_item(t_oplst **oplst, t_opp op);
void			delete_oplst(t_oplst **oplst);
void			print_oplst(t_oplst *oplst);
int				count_oplist(t_oplst *ptr);

/*
** Stacks helpers
*/

t_stacks		*new_stacks(void);
int				add_op(t_stacks *s, int op);
void			delete_stacks(t_stacks **s);
t_stacks		*dup_stacks(t_stacks *s);

#endif
