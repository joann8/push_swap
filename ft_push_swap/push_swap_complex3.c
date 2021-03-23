/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_complex3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:35:55 by jacher            #+#    #+#             */
/*   Updated: 2021/03/20 14:38:41 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

void		put_min_on_top(t_d *d, t_list **l, int i_a);
int			find_min_a(t_d *d);

int			find_quicker_mid(t_s *s, int low, int high, int mid)
{
	int i;
	int j;

	i = low;
	//printf("i = %d | low = %d | high = %d\n", i, low, high);
	while (i < high)
	{
		if (s[i].nb > mid)
			break;
		i++;
	}
	j = high - 1;
	while (j >= low)
	{
		if (s[j].nb > mid)
			break;
		j--;
	}
	if (i - low < high - 1 - j)
		return (1);
	else
		return (-1);
}


int			find_rot(t_s *s, int low, int high, int mid)
{
	int i;
	int count_1;
	int count_2;

	i = low;
	count_1 = -1;
	//printf("i = %d | low = %d | high = %d\n", i, low, high);
	while (i < high)
	{
		count_1++;
		if (s[i].nb < mid)
			break;
		i++;
	}
	i = high - 1;
	count_2 = -1;
	while (i >= low)
	{
		count_2++;
		if (s[i].nb < mid)
			break;
			i--;
	}
	if (count_1 <= count_2)
		return (1);
	else
		return (-1);
}


int			find_mid(t_s *s, int low, int high, t_m *mid )
{
	int test;
	int i;
	int j;
	int count;

	mid->half = (high - low) / 2;
	if (mid->half < 1)
		return(-1);
	i = low;
	while (i < high)
	{
		count = 0;
		test = s[i].nb;
		j =  low;
		while (j < high)
		{
			if (j != i && s[j].nb < test)
				count++;
			j++;
		}
		if (count == mid->half)
		{
			mid->i = i;
			mid->nb = s[i].nb;
			printf("mid >> i = %d | nb = %d | half = %d\n", mid->i, mid->nb, mid->half);
			return(1);
		}
		i++;
	}
	return (-1);
}

int	putona_with_mid(t_d *d, t_list **l, t_m *mid, int *tab)
{
	int i;
	int s_b;
	int s_a;
	int res;
	int count;

	s_a= d->size_a;
	s_b = d->size_b;
	i = d->size_max - d->size_a;
	res = find_quicker_mid(d->a, d->size_max - d->size_a, mid->nb);
	count = 0;
	while (count < mid->half)
	{
		if (d->a[i].nb >= mid->nb)
		{
			if (res == 1)
				ft_rotate_bis(1, 0, d, l);
			else
				ft_rrotate_bis(1, 0, d, l);
			i = d->size_max - d->size_a;
		}
		else
		{		
			ft_push_bis(0, 1, d, l);
			count++;
			i++;
		}
	}
	*tab = mid->half;
	return (1);
}


int	putonb_with_mid(t_d *d, t_list **l, t_m *mid, int *tab)
{
	int i;
	int s_b;
	int s_a;
	int res;
	int count;

	s_a= d->size_a;
	s_b = d->size_b;
	i = d->size_max - d->size_a;
	res = find_quicker_mid(d->a, d->size_max - d->size_a, mid->nb);
	count = 0;
	while (count < mid->half)
	{
		if (d->a[i].nb >= mid->nb)
		{
			if (res == 1)
				ft_rotate_bis(1, 0, d, l);
			else
				ft_rrotate_bis(1, 0, d, l);
			i = d->size_max - d->size_a;
		}
		else
		{		
			ft_push_bis(0, 1, d, l);
			count++;
			i++;
		}
	}
	*tab = mid->half;
	return (1);
}

int calculate_size(t_d *d)
{
	int tmp;
	int count;

	count = 0;
	tmp = d->size_max;
	while (tmp / 2 > 0)
	{
		count++;
		tmp = tmp / 2;
	}
	return(count);
}

int sort_complex_phase_three(t_d *d, t_list **l, int *tab, int i)
{
	t_m mid;

	if (check_int_order_a(d) == -1)
	{
		if (d->size_a > 2)
		{
			find_mid(d->a, d->size_max - d->size_b, d->size_max - d->size_b + tab[i], &mid);
			putonb_with_mid(d, l, &mid, tab + i);
		}
		else
			swap_rotate_first_a(d, l);
		print_struct(d->size_max, d);
		
	}
	if (check_int_order_a(d) == -1)
	{	
	//	printf("call again in check in order\n");
	//	print_struct(d->size_max, d);
		sort_complex_phase_one(d, l, tab, i + 1);
		return (1);
	}
	printf("end\n");
	print_struct(d->size_max, d);
	printf("_______________\n");
	int j;
	j = 0;
	while(tab[j] < INT_MAX)
	{
		printf("tab[%d] = %d\n", j, tab[j]);
		j++;
	}
	printf("tab[%d] = %d\n", j, tab[j]);
	sort_complex_phase_two(d, l, tab, j - 1);
	print_struct(d->size_max, d);
	return (1);

int sort_complex_phase_two(t_d *d, t_list **l, int *tab, int i)
{
	(void)l;
	(void)d;
	(void)tab;

	if (tab[i] <= 2)
	{
		if (tab[i] == 2)
		{
			if (d->b[d->size_b].nb < d->b[d->size_b].nb)
				ft_rotate_bis(0, 1, d, l);
			ft_push_bis(1, 0, d, l);
		}
		ft_push_bis(1, 0, d, l);
		if (i > 0)
			sort_complex_phase_two(d, l, tab, i - 1);
	}
	else
		sort_complex_phase_three(d, l, tab, i);
	return(1);
}

int sort_complex_phase_one(t_d *d, t_list **l, int *tab, int i)
{
	t_m mid;

//	printf("****start complex*****\n");
	if (check_int_order_a(d) == -1)
	{
		if (d->size_a > 2)
		{
			find_mid(d->a, d->size_max - d->size_a, d->size_max, &mid);
			putonb_with_mid(d, l, &mid, tab + i);
		}
		else
			swap_rotate_first_a(d, l);
		print_struct(d->size_max, d);
		
	}
	if (check_int_order_a(d) == -1)
	{	
	//	printf("call again in check in order\n");
	//	print_struct(d->size_max, d);
		sort_complex_phase_one(d, l, tab, i + 1);
		return (1);
	}
	printf("end\n");
	print_struct(d->size_max, d);
	printf("_______________\n");
	int j;
	j = 0;
	while(tab[j] < INT_MAX)
	{
		printf("tab[%d] = %d\n", j, tab[j]);
		j++;
	}
	printf("tab[%d] = %d\n", j, tab[j]);
	sort_complex_phase_two(d, l, tab, j - 1);
	print_struct(d->size_max, d);
	return (1);
}


