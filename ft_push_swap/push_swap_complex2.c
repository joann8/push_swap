/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_complex2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:35:55 by jacher            #+#    #+#             */
/*   Updated: 2021/03/20 11:22:36 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

void		put_min_on_top(t_d *d, t_list **l, int i_a);
int			find_min_a(t_d *d);

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


int			find_mid(t_s *s, int low, int high)
{
	int test;
	int	half;
	int i;
	int j;
	int count;

	half = (high - low - 1) / 2;
	if (half < 1)
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
		if (count == half)
			return(i);
		i++;
	}
	return (-1);
}

int	putonb_with_mid(t_d *d, t_list **l, int mid)
{
	int i;
	int s_b;
	int s_a;

	s_a= d->size_a;
	s_b = d->size_b;
	i = d->size_max - d->size_a;
	if (d->a[i].nb > mid)
	{
		ft_rotate_bis(1, 0, d, l);
	}
	else
	{		
		ft_push_bis(0, 1, d, l);
		if (d->size_b >= 2)
			swap_rotate_first_b(d, l);
	}
//	print_struct(d->size_max, d);
	while (i < d->size_max)
	{
		if (d->a[i].nb < mid)
		{
			putonb_with_mid(d, l, mid);
			break ;
		}
		i++;
	}
	return (1);
}

int sort_complex(t_d *d, t_list **l)
{
	int mid_i;
	int mid_n;
	int i;
	
//	printf("****start complex*****\n");
	if (check_int_order_a(d) == -1)
	{
		if (d->size_a == 2)
			swap_rotate_first_a(d, l);
		else
		{
//			print_struct(d->size_max, d);
			mid_i = find_mid(d->a, d->size_max - d->size_a, d->size_max);
	//		printf("there\n");
			mid_n = d->a[mid_i].nb;
	//		printf("here\n");
			if (check_int_order_a(d) == -1 && mid_i >= 0)
			{
	//			printf("call in main function \n");
				putonb_with_mid(d, l, mid_n);
			}
	//		printf("___after put on b___\n");
	//		print_struct(d->size_max, d);
		}
	}
	if (check_int_order_a(d) == -1)
	{	
	//	printf("call again in check in order\n");
	//	print_struct(d->size_max, d);
		sort_complex(d, l);
	}
	else
	{
	//	printf("last else\n");
		i = d->size_max - d->size_b;
		while(i < d->size_max && d->size_a < d->size_max)
		{
			ft_push_bis(1, 0, d, l);
			if (d->size_a >= 2)
				swap_rotate_first_a(d, l);
			i++;
		}
		print_struct(d->size_max, d);
		printf("end\n");
	}
	return (1);
}
