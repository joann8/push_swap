/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_complex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:35:55 by jacher            #+#    #+#             */
/*   Updated: 2021/05/13 18:59:35 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"
#include <stdio.h>
void	algo_push_swap_a_help(t_d *d, t_list **l, t_pack *new_pack)
{
	if (new_pack->on_a > 8)
	{
		algo_push_swap(d, l, 1, new_pack);
		algo_push_swap(d, l, 2, new_pack);
	}
	else
	{
		if (new_pack->on_a == 2)
		{
			if (d->a[d->size_max - d->size_a].nb
					> d->a[d->size_max - d->size_a + 1].nb)
				ft_swap_bis(1, 0, d, l);
		}
		else if (new_pack->on_a == 3)
		{
			if (special_3_a(d, l) == 0)
				algo_push_swap(d, l, 1, new_pack);
		}
		else if (new_pack->on_a == 4)
		{
			if (special_4_a(d, l) == 0)
				algo_push_swap(d, l, 1, new_pack);
		}	
		else if (new_pack->on_a == 5)
		{
			if (special_5_a(d, l) == 0)
				algo_push_swap(d, l, 1, new_pack);
		}
		else if (new_pack->on_a == 6)
		{
			if (special_6_a(d, l) == 0)
				algo_push_swap(d, l, 1, new_pack);
		}
		else if (new_pack->on_a == 7)
		{
			if (special_7_a(d, l) == 0)
				algo_push_swap(d, l, 1, new_pack);
		}
		else if (new_pack->on_a == 8)
		{
			if (special_8_a(d, l) == 0)
				algo_push_swap(d, l, 1, new_pack);
		}
	
		else
			algo_push_swap(d, l, 1, new_pack);
	
		
		if (new_pack->on_b == 2)
		{
			if (d->b[d->size_max - d->size_b].nb
					< d->b[d->size_max - d->size_b + 1].nb)
				ft_swap_bis(0, 1, d, l);
			ft_push_bis(1, 0, d, l);
			ft_push_bis(1, 0, d, l);
		}
		else if (new_pack->on_b == 3)
		{
			if (special_3_b(d, l) == 0)
				algo_push_swap(d, l, 2, new_pack);
		}
		else if (new_pack->on_b == 4)
		{
			if (special_4_b(d, l) == 0)
				algo_push_swap(d, l, 2, new_pack);
		}
		else if (new_pack->on_b == 5)
		{
			if (special_5_b(d, l) == 0)
				algo_push_swap(d, l, 2, new_pack);
		}
		else if (new_pack->on_b == 6)
		{
			if (special_6_b(d, l) == 0)
				algo_push_swap(d, l, 2, new_pack);
		}
		else if (new_pack->on_b == 7)
		{
			if (special_7_b(d, l) == 0)
				algo_push_swap(d, l, 2, new_pack);
		}
		else if (new_pack->on_b == 8)
		{
			if (special_8_b(d, l) == 0)
				algo_push_swap(d, l, 2, new_pack);
		}
		else
			algo_push_swap(d, l, 2, new_pack);
	}
}

void	algo_push_swap_a(t_d *d, t_list **l, int mod, t_pack *old_pack)
{
	t_pack	new_pack;
	int		res;

	if (mod == 1)
		res = define_pack(d->a, d->size_max - d->size_a,
			d->size_max - d->size_a + old_pack->on_a, &new_pack);
	if (mod == 0)
		res = define_pack(d->a, 0, d->size_max, &new_pack);
	if (res == 1)
		put_on_b(d, l, &new_pack, 0);
	else
	{
		new_pack.on_a = old_pack->on_a;
		new_pack.on_b = old_pack->on_b;
		new_pack.pair = old_pack->pair;
		new_pack.size = old_pack->size;
		new_pack.mid_value = old_pack->mid_value;
	}
	algo_push_swap_a_help(d, l, &new_pack);
}

void	algo_push_swap_b_help(t_d *d, t_list **l, t_pack *new_pack)
{
	if (new_pack->on_a > 8)
	{	
		algo_push_swap(d, l, 1, new_pack);
		algo_push_swap(d, l, 2, new_pack);
	}
	else
	{	
		if (new_pack->on_a == 2)
		{
			if (d->a[d->size_max - d->size_a].nb
					> d->a[d->size_max - d->size_a + 1].nb)
				ft_swap_bis(1, 0, d, l);
		}
		else if (new_pack->on_a == 3)
		{
			if (special_3_a(d, l) == 0)
				algo_push_swap(d, l, 1, new_pack);
		}
		else if (new_pack->on_a == 4)
		{
			if (special_4_a(d, l) == 0)
				algo_push_swap(d, l, 1, new_pack);
		}
		else if (new_pack->on_a == 5)
		{
			if (special_5_a(d, l) == 0)
				algo_push_swap(d, l, 1, new_pack);
		}
		else if (new_pack->on_a == 6)
		{
			if (special_6_a(d, l) == 0)
				algo_push_swap(d, l, 1, new_pack);
		}
		else if (new_pack->on_a == 7)
		{
			if (special_7_a(d, l) == 0)
				algo_push_swap(d, l, 1, new_pack);
		}
		else if (new_pack->on_a == 8)
		{
			if (special_8_a(d, l) == 0)
				algo_push_swap(d, l, 1, new_pack);
		}
		else
			algo_push_swap(d, l, 1, new_pack);



		if (new_pack->on_b == 2)
		{
			if (d->b[d->size_max - d->size_b].nb
					< d->b[d->size_max - d->size_b + 1].nb)
				ft_swap_bis(0, 1, d, l);
			ft_push_bis(1, 0, d, l);
			ft_push_bis(1, 0, d, l);
		}
		else if (new_pack->on_b == 3)
		{
			if (special_3_b(d, l) == 0)
				algo_push_swap(d, l, 2, new_pack);
		}
		else if (new_pack->on_b == 4)
		{
			if (special_4_b(d, l) == 0)
				algo_push_swap(d, l, 2, new_pack);
		}
		else if (new_pack->on_b == 5)
		{
			if (special_5_b(d, l) == 0)
				algo_push_swap(d, l, 2, new_pack);
		}
		else if (new_pack->on_b == 6)
		{
			if (special_6_b(d, l) == 0)
				algo_push_swap(d, l, 2, new_pack);
		}
		else if (new_pack->on_b == 7)
		{
			if (special_7_b(d, l) == 0)
				algo_push_swap(d, l, 2, new_pack);
		}	
		else if (new_pack->on_b == 8)
		{
			if (special_8_b(d, l) == 0)
				algo_push_swap(d, l, 2, new_pack);
		}
	
		else
			algo_push_swap(d, l, 2, new_pack);
	}
}

void	algo_push_swap_b(t_d *d, t_list **l, t_pack *old_pack)
{
	t_pack	new_pack;
	int		res;

	res = define_pack(d->b, d->size_max - d->size_b,
			d->size_max - d->size_b + old_pack->on_b, &new_pack);
	if (res == 1)
	{
		put_on_a(d, l, &new_pack, 0);
	}
	else
	{
		new_pack.on_a = old_pack->on_a;
		new_pack.on_b = old_pack->on_b;
		new_pack.pair = old_pack->pair;
		new_pack.size = old_pack->size;
		new_pack.mid_value = old_pack->mid_value;
	}
	algo_push_swap_b_help(d, l, &new_pack);
}

int		algo_push_swap(t_d *d, t_list **l, int mod, t_pack *old_pack)
{
	int count;

	if (mod == 1 || mod == 0)
	{
		if (check_int_order_a(d) == -1)
			algo_push_swap_a(d, l, mod, old_pack);
	}
	if (mod == 2)
	{
		if (check_int_order_b_range(d->b, d->size_max - d->size_b,
				d->size_max - d->size_b + old_pack->on_b) == -1)
		{
			algo_push_swap_b(d, l, old_pack);
		}
		else
		{
			count = 0;
			while (count < old_pack->on_b)
			{
				ft_push_bis(1, 0, d, l);
				count++;
			}
		}
	}
	return (1);
}
