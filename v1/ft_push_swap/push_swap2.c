/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:35:55 by jacher            #+#    #+#             */
/*   Updated: 2021/05/06 16:06:05 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

void		check(t_list **l, t_d *d)
{
	printf("\nENTER CHECK\n");
	print_struct(d->size_max, d);
	checker_test(l, d);
	printf("AFTER\n");
	print_list(*l, 0);
	print_struct(d->size_max, d);
	printf("_______________\n");
}	
	
int			main(int ac, char **av)
{
	t_d		d;
	t_d 	d2;
	t_list	*l;
	t_list	*l2;
	int		count;
	int		res;
	int		res2;
	t_pack pack;
	
	l = NULL;
	l2 = NULL;
	count = check_args(ac, av, &d);
	check_args(ac, av, &d2);
	if (count == -1)
		return (1);
	if (check_order(&d) == 1)
	{
		ft_free_data(&d);
		ft_free_list(l);
		return (1);
	}
	//printf("sort simple res:\n");
	if (d.size_max > 2)
		sort_simple(&d, &l);
	else
		ft_swap_bis(1, 0, &d, &l);
	update_inst(&l);
	check(&l, &d2);
	res = print_list(l, 0);
	ft_free_data(&d);
	ft_free_data(&d2);
	
	count = check_args(ac, av, &d);
	check_args(ac, av, &d2);
	if (count > 4)
	{
		if (count == -1)
			return (1);
		if (check_order(&d) == 1)
		{
			ft_free_data(&d);
			ft_free_list(l2);
			return (1);
		}
		define_pack(d.a, 0, d.size_max, &pack);
		algo_push_swap(&d, &l2, 0, &pack);
		//printf("sort complex res:\n");
		update_inst(&l2);
		check(&l2, &d2);
		res2 = print_list(l2, 0);
	}
	else
		res2 = INT_MAX;
	if (res < res2)
	{
		printf("chose option 1 : %d | (option 2 was %d)\n", res, res2);
//		print_list(l, 2);
		print_struct(d.size_max, &d);
	}
	else
	{
		printf("chose option 2 : %d | (option 1 was %d)\n", res2, res);
//		print_list(l2, 0);
		print_struct(d.size_max, &d);
	}

	if (res2 < INT_MAX)
	{
		ft_free_data(&d);
		ft_free_list(l2);
	}
	ft_free_list(l);
	return (1);
}
