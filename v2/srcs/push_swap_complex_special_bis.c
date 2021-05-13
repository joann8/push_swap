/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_complex_special_bis.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:35:55 by jacher            #+#    #+#             */
/*   Updated: 2021/05/12 16:50:37 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

int			find_median_3_b(t_d *d)
{
	int test;
	int i;
	int j;
	int count;
	int pack_half;

	pack_half = 2;
	i = d->size_max - d->size_b;
	while (i < d->size_max - d->size_b + 3)
	{
		count = 0;
		test = d->b[i].nb;
		j = d->size_max - d->size_b;
		while (j < d->size_max - d->size_b + 3)
		{
			if (d->b[j].nb <= test)
				count++;
			j++;
		}
		if (count == pack_half)
			return (d->b[i].nb);
		i++;
	}
	return (-1);
}

int			sort_array_3_b(t_d *d, t_list **l)
{
	int i;
	int mid_value;
	int count;

	if ((d->b[d->size_max - d->size_b].nb
					> d->b[d->size_max - d->size_b + 1].nb)
			&& (d->b[d->size_max - d->size_b + 1].nb
					> d->b[d->size_max - d->size_b + 2].nb))
	{
		ft_push_bis(1, 0, d, l);
		ft_push_bis(1, 0, d, l);
		ft_push_bis(1, 0, d, l);
		return (1);
		
	}
	else if ((d->b[d->size_max - d->size_b].nb
					< d->b[d->size_max - d->size_b + 1].nb)
			&& (d->b[d->size_max - d->size_b + 1].nb
					> d->b[d->size_max - d->size_b + 2].nb)
			&& (d->b[d->size_max - d->size_b].nb
					> d->b[d->size_max - d->size_b + 2].nb))
	{	
		ft_swap_bis(0, 1, d, l);
		ft_push_bis(1, 0, d, l);
		ft_push_bis(1, 0, d, l);
		ft_push_bis(1, 0, d, l);
		return (1);
	}
	mid_value = find_median_3_b(d);
	i = 0;
	count = 0;
	while (i < 3)
	{
		if (d->b[d->size_max - d->size_b].nb > mid_value)
		{
			ft_push_bis(1, 0, d, l);
			break ;
		}
		else
		{
			count++;
			ft_rotate_bis(0, 1, d, l);
		}
		i++;
	}
	while (count > 0)
	{
		ft_rrotate_bis(0, 1, d, l);
		count--;
	}
	if (d->b[d->size_max - d->size_b].nb < d->b[d->size_max - d->size_b + 1].nb)
		ft_swap_bis(0, 1, d, l);
	ft_push_bis(1, 0, d, l);
	ft_push_bis(1, 0, d, l);
	return (1);
}

int			find_median_3_a(t_d *d)
{
	int test;
	int i;
	int j;
	int count;
	int pack_half;

	pack_half = 2;
	i = d->size_max - d->size_a;
	while (i < d->size_max - d->size_a + 3)
	{
		count = 0;
		test = d->a[i].nb;
		j = d->size_max - d->size_a;
		while (j < d->size_max - d->size_a + 3)
		{
			if (d->a[j].nb <= test)
				count++;
			j++;
		}
		if (count == pack_half)
			return (d->a[i].nb);
		i++;
	}
	return (-1);
}

#include <stdio.h>
int			sort_array_3_a(t_d *d, t_list **l)
{
	int i;
	int mid_value;
	int count;

	if ((d->a[d->size_max - d->size_a].nb
					< d->a[d->size_max - d->size_a + 1].nb)
			&& (d->a[d->size_max - d->size_a + 1].nb
					< d->a[d->size_max - d->size_a + 2].nb))
		return (1);
	else if ((d->a[d->size_max - d->size_a].nb
					> d->a[d->size_max - d->size_a + 1].nb)
			&& (d->a[d->size_max - d->size_a + 1].nb
					< d->a[d->size_max - d->size_a + 2].nb)
			&& (d->a[d->size_max - d->size_a].nb
					< d->a[d->size_max - d->size_a + 2].nb))
	{
		ft_swap_bis(1, 0, d, l);
		return (1);
	}
	mid_value = find_median_3_a(d);
	i = 0;
	count = 0;
	while (i < 3)
	{
		if (d->a[d->size_max - d->size_a].nb < mid_value)
		{
			ft_push_bis(0, 1, d, l);
			break ;
		}
		else
		{
			count++;
			ft_rotate_bis(1, 0, d, l);
		}
	}
	while (count > 0)
	{
		ft_rrotate_bis(1, 0, d, l);
		count--;
	}
	if (d->a[d->size_max - d->size_a].nb > d->a[d->size_max - d->size_a + 1].nb)
		ft_swap_bis(1, 0, d, l);
	ft_push_bis(1, 0, d, l);
	return (1);
}
