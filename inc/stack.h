/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 15:18:05 by omulder       #+#    #+#                 */
/*   Updated: 2020/02/02 11:32:09 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct	s_stack {
	int				value;
	int				pos;
	struct s_stack	*next;
}				t_stack;

/*
** Stack
*/

void			print_stack(t_stack *stack);
int				push_stack(t_stack **stack, int value);
int				stack_is_sorted(t_stack *a, int prev, int *count);
int				check_stack(t_stack *a, int *count, int argc);
int				value_exists(t_stack *a, int value);
int				check_and_push(t_stack **stack, char *value);
void			delete_stack(t_stack **a);
void			print_both_stacks(t_stack *a, t_stack *b);

/*
**	Operations
*/

void			opp_sa(t_stack **a);
void			opp_sb(t_stack **b);
void			opp_ss(t_stack **a, t_stack **b);
void			opp_pa(t_stack **a, t_stack **b);
void			opp_pb(t_stack **a, t_stack **b);
void			opp_ra(t_stack **a);
void			opp_rb(t_stack **b);
void			opp_rr(t_stack **a, t_stack **b);
void			opp_rra(t_stack **a);
void			opp_rrb(t_stack **b);
void			opp_rrr(t_stack **a, t_stack **b);

#endif
