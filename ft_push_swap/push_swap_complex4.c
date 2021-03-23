/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_complex4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:35:55 by jacher            #+#    #+#             */
/*   Updated: 2021/03/21 20:01:44 by jacher           ###   ########.fr       */
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


int			find_mid(t_s *s, int low, int high, t_m *mid)
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

int	put_on_a(t_d *d, t_list **l, t_m *mid, int pair)
{
	int moved;
	int count;

	count = 0;
	moved = 0;
	printf("PUT ON A: mid->nb = %d | mid->half = %d | d->size_b = %d\n", mid->nb, mid->half,d->size_b);
	printf("before:\n");
	printf("pair = %d\n", pair);
	print_struct(d->size_max, d);
	while (moved < mid->half)
	{
	//printf("mid->nb = %d | d->size_max =%d | d->size_b = %d\n", mid->nb, d->size_max, d->size_b);
	//	printf("d->
		if (pair % 2 == 0 && d->b[d->size_max - d->size_b].nb < mid->nb)
		{
			ft_rotate_bis(0, 1, d, l);
			count++;
		}
		else if (pair % 2 == 1 && d->b[d->size_max - d->size_b].nb <= mid->nb)
		{
			ft_rotate_bis(0, 1, d, l);
			count++;
		}
		
		else
		{		
			ft_push_bis(1, 0, d, l);
			moved++;
		}
	}
	while (count > 0)
	{
		ft_rrotate_bis(0, 1, d, l);
		count--;
	}
	printf("after:\n");
	print_struct(d->size_max, d);
	return (1);
}

int	put_on_b(t_d *d, t_list **l, t_m *mid, int pair)
{
	int moved;
	int count;

	count = 0;
	moved = 0;
	printf("PUT ON B: mid->nb = %d | d->size_max = %d | d->size_a = %d\n", mid->nb, d->size_max,d->size_a);
	printf("before:\n");
	printf("pair = %d\n", pair);
	print_struct(d->size_max, d);
	while (moved < mid->half + pair % 2)
	{
		if (pair % 2 == 0 && d->a[d->size_max - d->size_a].nb >= mid->nb)
		{
			ft_rotate_bis(1, 0, d, l);
			count++;
		}
		if (pair  % 2 == 1 && d->a[d->size_max - d->size_a].nb > mid->nb)
		{
			ft_rotate_bis(1, 0, d, l);
			count++;
		}
		else
		{		
			ft_push_bis(0, 1, d, l);
			moved++;
		}
	}
	while (count > 0)
	{
		ft_rrotate_bis(1, 0, d, l);
		count--;
	}
	printf("after:\n");
	print_struct(d->size_max, d);
	return (1);
}


int	putonb_with_mid(t_d *d, t_list **l, t_m *mid)
{
	int i;
	int s_b;
	int s_a;
	int res;
	int count;

	s_a= d->size_a;
	s_b = d->size_b;
	i = d->size_max - d->size_a;
	res = find_quicker_mid(d->a, d->size_max, d->size_a, mid->nb);
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
	return (1);
}

int calculate_levels(t_d *d)
{
	int tmp;
	int count;

	count = 0;
	tmp = d->size_max;
	while (tmp / 2 > 0)
	{
		count++;
		tmp = tmp / 2 + tmp % 2;
	}
	printf("count = %d\n", count);
	return(count);
}

int sort_complex_phase_two(t_d *d, t_list **l, t_level *lev, int i, int *blocked)
{
	t_m mid;
	int count;
			count = 0;
			

	printf("ENTER SORT COMPLEX WITH FOLLOWING DATA\n");
	printf("lev[%d].a = %d | lev[%d].b = %d | lev[%d].level = %d\n", i, lev[i].a, i, lev[i].b, i, lev[i].level);
	printf("blocked = %d\n", *blocked);
	print_struct(d->size_max, d);
	if (lev[i].b <= 2)
	{
		if (lev[i].b == 2)
		{
			printf("lev[%d] = %d\n", i, lev[i].b);
			if (d->b[d->size_max - d->size_b].nb < d->b[d->size_max - d->size_b + 1].nb)
				ft_swap_bis(0, 1, d, l);
			ft_push_bis(1, 0, d, l);
			*blocked += 1;
		}
		ft_push_bis(1, 0, d, l);
		*blocked += 1;
	}
	else
	{
		if (lev[i].a == 2)
			ft_swap_bis(1, 0, d, l);
		if (d->size_b <= 2)
			swap_rotate_first_b(d, l);
		else
		{
			while (lev[i].b > 2)
			{
				count++;
				find_mid(d->b, d->size_max - d->size_b, d->size_max - d->size_b + lev[i].b, &mid);
				lev[i+1].a = mid.half;
				lev[i+1].b = lev[i].b / 2 + lev[i].b % 2;
				lev[i+1].level = i + 1;
				i++;
				printf("---PUT ON A---\n");
				printf("lev[%d].a = %d | lev[%d].b = %d | lev[%d].level = %d\n", i , lev[i ].a, i , lev[i].b, i , lev[i ].level);
				put_on_a(d, l, &mid, lev[i].b + lev[i].a);
				if (mid.half == 2)
				{
					swap_rotate_first_a(d, l);
					*blocked += 2;
				}
				if (lev[i].b == 2)
				{
					swap_rotate_first_b(d, l);
					ft_push_bis(1,0,d,l);
					ft_push_bis(1,0,d,l);
				}
				
			
			else if (mid.half > 2 )
			{
				count = 0;
				while (lev[i].a > 2)
				{
				 	count++;
					find_mid(d->a, d->size_max - d->size_a, d->size_max - d->size_a + lev[i].a, &mid);
					lev[i+1].b = mid.half + lev[i].a % 2;
					lev[i+1].a = lev[i].a / 2;
					lev[i+1].level = i + 1;
					i++;
					printf("---PUT ON B---\n");
					printf("lev[%d].a = %d | lev[%d].b = %d | lev[%d].level = %d\n", i +1, lev[i].a, i, lev[i].b, i, lev[i].level);
					put_on_b(d, l, &mid, lev[i].b + lev[i].a);

				}
				if (lev[i].a == 2)
					ft_swap_bis(1, 0, d, l);
				if (lev[i].b == 2)
				{
					swap_rotate_first_b(d, l);
					ft_push_bis(1,0,d,l);
					ft_push_bis(1,0,d,l);
					i--;
				}
				if (lev[i].b == 3)
				{
					find_mid(d->b, d->size_max - d->size_b, d->size_max - d->size_b + lev[i].b, &mid);
					lev[i+1].a = mid.half;
					lev[i+1].b = lev[i].b / 2 + lev[i].b % 2;
					lev[i+1].level = i + 1;
					i++;
					printf("---PUT ON A---\n");
					printf("lev[%d].a = %d | lev[%d].b = %d | lev[%d].level = %d\n", i , lev[i ].a, i , lev[i].b, i , lev[i ].level);
					put_on_a(d, l, &mid, lev[i].b + lev[i].a);
					swap_rotate_first_b(d, l);
					ft_push_bis(1,0,d,l);
					ft_push_bis(1,0,d,l);
					i -= 2;
				}
				sort_complex_phase_two(d, l, lev, i , blocked);
				return(1);
			}
		}
		}
	}
	if (i > 0)
	{
		if (check_int_order_b(d) == -1)
		{
			printf("Sort complex\n");
			sort_complex_phase_two(d, l, lev, i - count - 1, blocked);
		}
		else
		{
			printf("____Last ELSE____\n");
			int j;
			j = d->size_max - d->size_b;
			while (j < d->size_max)
			{
				ft_push_bis(1,0,d, l);
				j++;
			}
		}
	}
	return(1);
}

int sort_complex_phase_one(t_d *d, t_list **l, t_level *lev, int i, int *blocked)
{
	t_m mid;

//	printf("****start complex*****\n");
	if (check_int_order_a(d) == -1)
	{
		if (d->size_a - *blocked > 2)
		{
			if (find_mid(d->a, d->size_max - d->size_a, d->size_max - *blocked, &mid) >= 1)
			{
				lev[i].a = d->size_a - mid.half;
				lev[i].b = mid.half;
				lev[i].level = i;
				printf("lev[%d].a = %d | lev[%d].b = %d | lev[%d].level = %d\n", i, lev[i].a, i, lev[i].b, i, lev[i].level);
				putonb_with_mid(d, l, &mid);
			}
		}
		else
		{
			swap_rotate_first_a(d, l);
		}
		print_struct(d->size_max, d);
		
	}
	if (check_int_order_a(d) == -1)
	{	
		printf("call again in check in order\n");
	//	print_struct(d->size_max, d);
		sort_complex_phase_one(d, l, lev, i + 1, blocked);
		return (1);
	}
	else
	{
		if (lev[i].b == 1)
		{
			ft_push_bis(1, 0 , d, l);
		}
	}
	*blocked = d->size_a;
	printf("i = %d\n", i);
	i++;
	while (lev[i].level != INT_MAX)
	{
		lev[i].level = INT_MAX;
		lev[i].a = INT_MAX;
		lev[i].b = INT_MAX;
		i++;
	}
	printf("end\n");
	printf("blocked = %d\n", *blocked);
	print_struct(d->size_max, d);
	printf("_______________\n");
	int j;
	j = 0;
	while(lev[j].level < INT_MAX)
	{
		printf("lev[%d].a = %d | lev[%d].b = %d | lev[%d].level = %d\n", j, lev[j].a, j, lev[j].b, j, lev[j].level);
		j++;
	}
	printf("lev[%d].a = %d | lev[%d].b = %d | lev[%d].level = %d\n", j, lev[j].a, j, lev[j].b, j, lev[j].level);
	printf("\n***START PHASE TWO***\n\n");
	sort_complex_phase_two(d, l, lev, j - 1, blocked);
	//print_struct(d->size_max, d);
	return (1);
}


