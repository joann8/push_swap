/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:35:55 by jacher            #+#    #+#             */
/*   Updated: 2021/05/15 12:14:30 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

int		try_free_help(t_d *d, t_list **l)
{
	if (d)
		ft_free_data(d);
	if (l && *l)
		ft_free_list(*l);
	return (-1);
}

int		try_simple_sort(int ac, char **av, t_list **l, int *res)
{
	t_res	r;
	t_d		d;
	int		count;

	init_flags(&r);
	if ((count = check_args(ac, av, &d, &r)) < 0)
		return (-1);
	if (check_order(&d) == 1)
		return (try_free_help(&d, NULL));
	if (count < 101)
	{
		if (d.size_max > 2)
			sort_simple(&d, l);
		else
			ft_swap_bis(1, 0, &d, l);
		if (update_inst(l) == -1)
			return (try_free_help(&d, l));
		update_doublons(l);
		*res = print_list(*l, 3);
	}
	else
		*res = I_MAX;
	ft_free_data(&d);
	return (0);
}

int		try_complex_sort(int ac, char **av, t_list **l, int *res)
{
	t_pack	pack;
	t_res	r;
	t_d		d;
	int		count;

	init_flags(&r);
	if ((count = check_args(ac, av, &d, &r)) < 0)
		return (-1);
	if (count > 4)
	{
		if (check_order(&d) == 1)
			return (try_free_help(&d, NULL));
		define_pack(d.a, 0, d.size_max, &pack);
		algo_push_swap(&d, l, 0, &pack);
		if (update_inst(l) == -1)
			return (try_free_help(&d, l));
		update_doublons(l);
		*res = print_list(*l, 3);
	}
	else
		*res = I_MAX;
	ft_free_data(&d);
	return (0);
}

int		main(int ac, char **av)
{
	t_list	*l;
	t_list	*l2;
	int		res;
	int		res2;

	l = NULL;
	l2 = NULL;
	if (try_simple_sort(ac, av, &l, &res) == -1)
		return (1);
	if (try_complex_sort(ac, av, &l2, &res2) == -1)
		return (1);
	if (res < res2)
		print_list(l, 2);
	else
		print_list(l2, 2);
	if (res2 < I_MAX)
		ft_free_list(l2);
	if (res < I_MAX)
		ft_free_list(l);
	return (1);
}
