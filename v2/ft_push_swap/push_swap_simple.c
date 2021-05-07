/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:35:55 by jacher            #+#    #+#             */
/*   Updated: 2021/03/23 10:36:57 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

void		swap_rotate_first_b(t_d *d, t_list **l)
{
	int i;
	int action;

	i = d->size_max - d->size_b;
	action = 0;
	while (action == 0)
	{
		if (d->b[i].nb < d->b[i + 1].nb)
		{
			if (d->size_b > 2 && d->b[i + 1].nb < d->b[d->size_max - 1].nb
				&& d->b[d->size_max - 1].nb < d->b[i].nb)
				ft_rotate_bis(0, 1, d, l);
			if (check_int_order_b(d) == 1)
				break;
			ft_swap_bis(0, 1, d, l);
			action = 1;
		}
		else if (d->b[i].nb < d->b[d->size_max - 1].nb)
		{
			ft_rrotate_bis(0, 1, d, l);
			action = 1;
		}
		if (action == 1)
		{
			i = d->size_max - d->size_b;
			action = 0;
		}
		else
			action = 1;
	}
}
void		swap_rotate_first_a(t_d *d, t_list **l)
{
	int i;
	int action;

	i = d->size_max - d->size_a;
	action = 0;
	while (action == 0)
	{
		if (d->a[i].nb > d->a[i + 1].nb)
		{
			if (d->size_a > 2 && d->a[i + 1].nb < d->a[d->size_max - 1].nb
				&& d->a[d->size_max - 1].nb < d->a[i].nb)
				ft_rotate_bis(1, 0, d, l);
			if (check_int_order_a(d) == 1)
				break;
			ft_swap_bis(1, 0, d, l);
			action = 1;
		}
		else if (d->a[i].nb > d->a[d->size_max - 1].nb)
		{
			ft_rrotate_bis(1, 0, d, l);
			action = 1;
		}
		if (action == 1)
		{
			i = d->size_max - d->size_a;
			action = 0;
		}
		else
			action = 1;
	}
}

int			find_min_a(t_d *d)
{
	int min_a;
	int i;
	int i_a;
	int count;

	min_a = INT_MAX;
	i = d->size_max - d->size_a;
	i_a = -1;
	count = -1;
	while (i < d->size_max)
	{
		count++;
		if (d->a[i].nb < min_a)
		{
			min_a = d->a[i].nb;
			i_a = count;
		}
		i++;
	}
	if (i_a < 0)
		return (-1);
	return (i_a);
}

void		put_min_on_top(t_d *d, t_list **l, int i_a)
{
	int i;

	i = 0;
	if (i_a == 1)
		ft_swap_bis(1, 0, d, l);
	else
	{
		if (d->size_a / 2 >= i_a)
		{
			while (i < i_a)
			{
				ft_rotate_bis(1, 0, d, l);
				i++;
			}
		}
		else
		{
			while (d->size_a - i > i_a)
			{
				ft_rrotate_bis(1, 0, d, l);
				i++;
			}
		}
	}
}

int			sort_simple(t_d *d, t_list **l)
{
	int i;
	int i_a;

	if (d->size_a >= 2)
		swap_rotate_first_a(d, l);
	i_a = find_min_a(d);
	if (check_int_order_a(d) == -1 && i_a > 0)
		put_min_on_top(d, l, i_a);
	if (check_int_order_a(d) == -1 && i_a >= 0)
	{
		ft_push_bis(0, 1, d, l);
		sort_simple(d, l);
	}
	else
	{
		i = 0;
		while (i < d->size_max && d->size_a < d->size_max)
		{
			ft_push_bis(1, 0, d, l);
			i++;
		}
	}
	return (1);
}
