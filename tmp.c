void	split_a(t_stacks *s, int min, int max)
{
	int		i;
	int		pivot;
	int		rotations;

	i = 0;
	rotations = 0;
	pivot = min + ((max - min) / 2);
	ft_printf("--------------------------SPLIT A----------------------\n");
	ft_printf("Pivot: %d, Min: %d, Max: %d\n", pivot, min, max);
	print_stack(s->a);
	ft_printf("------------------------------------------------------\nStack B\n");
	print_stack(s->b);
	if (max - min == 3)
	{
		sort_3_a(s);
		if (max != s->total)
			push_back(s, min, max, PB);
		return ;
	}
	while (i < (pivot - min) && i + rotations < max - min)
	{
		if (s->a->pos < pivot)
		{
			opp_do(s, PB);
			i++;
		}
		else
		{
			opp_do(s, RA);
			rotations++;
		}
	}
	i = 0;
	while (i < rotations)
	{
		opp_do(s, RRA);
		i++;
	}
	ft_printf("-----------------------SPLIT A AFTER LOOPS----------------------------\n");
	print_stack(s->a);
	ft_printf("------------------------------------------------------\nStack B\n");
	print_stack(s->b);
	if (pivot - min == 2 && (max - min) % 2 == 0)
	{
		ft_printf("CALLED in a: pivot - min && (max - min) %% 2 == 1 == 2\n");
		sort_3_a(s);
		sort_2_b_push_a(s);
	}
	else if (pivot - min == 2)
	{
		ft_printf("CALLED in a: pivot - min\n");
		sort_2_a(s);
		sort_2_b_push_a(s);
	}
	else
	{
		split_a(s, pivot, max);
		split_b(s, min, pivot);
	}
	// if (max != s->total)
	// 	push_back(s, min, max, PB);
}