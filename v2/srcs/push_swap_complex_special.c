/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_complex_special.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:35:55 by jacher            #+#    #+#             */
/*   Updated: 2021/05/12 17:01:46 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

int			find_median_4_b(t_d *d)
{
	int test;
	int i;
	int j;
	int count;
	int pack_half;

	pack_half = 2;
	i = d->size_max - d->size_b;
	while (i < d->size_max - d->size_b + 4)
	{
		count = 0;
		test = d->b[i].nb;
		j = d->size_max - d->size_b;
		while (j < d->size_max - d->size_b + 4)
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

#include <stdio.h>
int			sort_array_4_b(t_d *d, t_list **l)
{
	int i;
	int mid_value;
	int count;
	int moved;

	printf("lll before\n");
	mid_value = find_median_4_b(d);
	printf("mid value = %d\n", mid_value);
	i = 0;
	count = 0;
	moved = 0;
	while (moved < 2 && i < 4)
	{
		if (d->b[d->size_max - d->size_b].nb > mid_value)
		{
			ft_push_bis(1, 0, d, l);
			moved++;
		}
		else
		{
			count++;
			ft_rotate_bis(0, 1, d, l);
		}
		i++;
	}
	printf("therre\n");
	while (count > 0)
	{
		ft_rrotate_bis(0, 1, d, l);
		count--;
	}
	printf("therre\n");
	if (d->a[d->size_max - d->size_a].nb > d->a[d->size_max - d->size_a + 1].nb)
		ft_swap_bis(1, 0, d, l);
	if (d->b[d->size_max - d->size_b].nb < d->b[d->size_max - d->size_b + 1].nb)
		ft_swap_bis(0, 1, d, l);
	ft_push_bis(1, 0, d, l);
	ft_push_bis(1, 0, d, l);
	printf("return ok\n");
	return (1);
}

int			find_median_4_a(t_d *d)
{
	int test;
	int i;
	int j;
	int count;
	int pack_half;

	pack_half = 2;
	i = d->size_max - d->size_a;
	while (i < d->size_max - d->size_a + 4)
	{
		count = 0;
		test = d->a[i].nb;
		j = d->size_max - d->size_a;
		while (j < d->size_max - d->size_a + 4)
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

int			sort_array_4_a(t_d *d, t_list **l)
{
	int i;
	int mid_value;
	int count;
	int moved;

	mid_value = find_median_4_a(d);
	printf("mid value = %d\n", mid_value);
	i = 4;
	count = 0;
	moved = 0;
	while (moved < 2 && i < 4)
	{
		if (d->a[d->size_max -d->size_a].nb <= mid_value)
		{
			moved++;
			ft_push_bis(0, 1, d, l);
		}
		else
		{
			count++;
			ft_rotate_bis(1, 0, d, l);
		}
		i++;
	}
	printf("herr\n");
	while (count > 0)
	{
		ft_rrotate_bis(1, 0, d, l);
		count--;
	}
	printf("herr\n");
	if (d->a[d->size_max - d->size_a].nb > d->a[d->size_max - d->size_a + 1].nb)
		ft_swap_bis(1, 0, d, l);
	if (d->b[d->size_max - d->size_b].nb < d->b[d->size_max - d->size_b + 1].nb)
		ft_swap_bis(0, 1, d, l);
	ft_push_bis(1, 0, d, l);
	ft_push_bis(1, 0, d, l);
	printf("return ok\n");
	return (1);
}
