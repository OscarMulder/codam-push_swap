/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 10:30:57 by omulder        #+#    #+#                */
/*   Updated: 2020/01/25 19:43:43 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stack.h>

static int	return_error(void)
{
	ft_printf("Error\n");
	return (1);
}

static int	do_opp(t_stack **a, t_stack **b, char *opp)
{
	if (ft_strequ(opp, "sa"))
		opp_sa(a);
	else if (ft_strequ(opp, "sb"))
		opp_sb(b);
	else if (ft_strequ(opp, "ss"))
		opp_ss(a, b);
	else if (ft_strequ(opp, "pa"))
		opp_pa(a, b);
	else if (ft_strequ(opp, "pb"))
		opp_pb(a, b);
	else if (ft_strequ(opp, "ra"))
		opp_ra(a);
	else if (ft_strequ(opp, "rb"))
		opp_rb(b);
	else if (ft_strequ(opp, "rr"))
		opp_rr(a, b);
	else if (ft_strequ(opp, "rra"))
		opp_rra(a);
	else if (ft_strequ(opp, "rrb"))
		opp_rrb(b);
	else if (ft_strequ(opp, "rrr"))
		opp_rrr(a, b);
	else
		return (0);
	return (1);
}

static int	read_and_do_opps(t_stack **a, t_stack **b, int *op_count)
{
	char	*line;
	int		ret;

	ret = 1;
	line = NULL;
	while (ret == 1)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		if (ret > 0)
		{
			if (!do_opp(a, b, line))
				return (0);
			(*op_count)++;
			free(line);
		}
	}
	return (1);
}

int			main(int argc, char **argv)
{
	size_t	i;
	t_stack	*a;
	t_stack *b;
	int		count;
	int		op_count;

	if (argc < 2)
		return (1);
	i = argc - 1;
	count = 0;
	op_count = 0;
	a = NULL;
	b = NULL;
	while (i > 0)
	{
		if (!check_and_push(&a, argv[i]))
			return (return_error());
		i--;
	}
	if (!read_and_do_opps(&a, &b, &op_count))
		return (return_error());
	ft_printf("Op_count: %d\n", op_count);
	return (check_stack(a, &count, argc));
}
