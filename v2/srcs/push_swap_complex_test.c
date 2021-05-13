/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_complex_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:35:55 by jacher            #+#    #+#             */
/*   Updated: 2021/05/13 11:23:02 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

#include <stdio.h>

void	sort_insertion_array_b(t_d *d, t_list **l, t_pack *p)
{
	int i;
	int j;
	int ref;
	int ins; 
	int cmp;
	int mov;
	int mod;
	

//	print_struct(d->size_max, d);
	while (check_int_order_b_range(d->b, d->size_max - d->size_b, d->size_max - d->size_b + p->on_b) == -1)
	{
		i = d->size_max - d->size_b;
		ref = d->size_max - d->size_b;
		while (i < ref + p->on_b - 1)
		{
	//		printf("i-there= %d\n", i);
	//		print_struct(d->size_max, d);
			if (d->b[i].nb < d->b[i + 1].nb)
			{
				if (i == ref)
					ft_swap_bis(0, 1, d, l);
				else
				{
					ins = d->b[i + 1].nb;
					j = ref;
					mov = 0;
					while (j < i + 1)
					{
						ft_rotate_bis(0, 1, d, l);
						mov++;
						j++;
					}
					ft_push_bis(1, 0, d, l);
					mov++;
					mod = 0;
					while (mov > 0)
					{
						cmp = d->b[d->size_max - 1].nb;
					//	printf("ins = %d | cmp = %d\n",ins, cmp);
						if ((cmp < ins && mov > 1) || mod == 1)
							ft_rrotate_bis(0, 1, d, l);
						else if (mod == 0)
						{
							ft_push_bis(0, 1, d, l);
							mod = 1;
						}
						mov--;
					}

				}
				break ;
			}
			else
				i++;
		}
	}
//	printf("Intermediate result\n");
//	print_struct(d->size_max, d);
	i = d->size_max - d->size_b;
	ref = d->size_max - d->size_b;
	while (i < ref + p->on_b && i < d->size_max)
	{
	//	printf("i = %d hellothere\n",i);
		ft_push_bis(1, 0, d, l);
		i++;
	}
//	printf("end b\n");
//	print_struct(d->size_max, d);
}

void	sort_insertion_array_a(t_d *d, t_list **l, t_pack *p)
{
	int i;
	int j;
	int ref;
	int ins;
	int	cmp;
	int mov;
	int mod;
	
//	print_struct(d->size_max, d);
	while (check_int_order_a_range(d->a, d->size_max - d->size_a, d->size_max - d->size_a + p->on_a) == -1)
	{	
		i = d->size_max - d->size_a;
		ref = d->size_max - d->size_a;
		while (i < ref + p->on_a - 1)
		{
			if (d->a[i].nb > d->a[i + 1].nb)
			{
				if (i == ref)
					ft_swap_bis(1, 0, d, l);
				else
				{
					ins = d->a[i + 1].nb;
					j = ref;
					mov = 0;
					while (j < i + 1)
					{
						ft_rotate_bis(1, 0, d, l);
						j++;
						mov++;
					}
					ft_push_bis(0, 1, d, l);
					mov++;
					mod = 0;
					while (mov > 0)
					{
						cmp = d->a[d->size_max - 1].nb;
						if ((cmp > ins && mov > 1) || mod == 1)
							ft_rrotate_bis(1, 0, d, l);
						else if (mod == 0)
						{
							ft_push_bis(1, 0, d, l);
							mod = 1;
						}
						mov--;
					}
				}
				break ;
			}
			else
				i++;
		}
	}
//	print_struct(d->size_max, d);
}
