/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 12:19:51 by omulder        #+#    #+#                */
/*   Updated: 2020/01/14 17:05:49 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

typedef struct	s_stack {
	int				value;
	struct s_stack	*next;
}				t_stack;

/*
** Stack
*/

void			print_stack(t_stack *stack);
int				push_stack(t_stack **stack, int value);
int				stack_is_sorted(t_stack *a, int prev, int *count);
int				check_stack(t_stack *a, int *count, int argc);

/*
**	Opperations
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
