/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_complex5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:35:55 by jacher            #+#    #+#             */
/*   Updated: 2021/03/22 19:59:37 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"
void	print_pack(t_pack *pack)
{
	printf("Pack INFO:\n   - size %d | on_a %d | on_b %d\n   - pair: %d\n   - mid_value: %d\n", pack->size, pack->on_a, pack->on_b, pack->pair, pack->mid_value);
}


int	put_on_a(t_d *d, t_list **l, t_pack *pack)
{
	int moved;
	int count;

	count = 0;
	moved = 0;
//	printf("---PUT ON A---\n");
//	printf("before:\n");
//	print_struct(d->size_max, d);
	while (moved < pack->on_a)
	{
		if (pack->pair == 0 && d->b[d->size_max - d->size_b].nb < pack->mid_value)
		{
			ft_rotate_bis(0, 1, d, l);
			count++;
		}
		else if (pack->pair == 1 && d->b[d->size_max - d->size_b].nb <= pack->mid_value)
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
//	printf("after:\n");
//	print_struct(d->size_max, d);
	return (1);
}

int	put_on_b(t_d *d, t_list **l, t_pack *pack)
{
	int moved;
	int count;

	count = 0;
	moved = 0;
//	printf("----PUT ON B----\n");
//	printf("before:\n");
//	print_struct(d->size_max, d);
//	printf("d->size_max %d - d->size_a %d = %d\n", d->size_max, d->size_a, d->size_max - d->size_a);
	while (moved < pack->on_b)
	{
		if (pack->pair == 0 && d->a[d->size_max - d->size_a].nb >= pack->mid_value)
		{
			ft_rotate_bis(1, 0, d, l);
			count++;
		}
		else if (pack->pair == 1 && d->a[d->size_max - d->size_a].nb > pack->mid_value)
		{
			ft_rotate_bis(1, 0, d, l);
			count++;
		}
		else
		{		
//		 	printf("d->a = %d | d->size_max %d - d->size_a %d = %d\n", d->a[d->size_max - d->size_a].nb ,d->size_max, d->size_a, d->size_max - d->size_a);
			ft_push_bis(0, 1, d, l);
			moved++;
		}
	}
	while (count > 0)
	{
		ft_rrotate_bis(1, 0, d, l);
		count--;
	}
//	printf("after:\n");
//	print_struct(d->size_max, d);
	return (1);
}

int			define_pack(t_s *s, int low, int high, t_pack *pack)
{
	int test;
	int i;
	int j;
	int count;
	int pack_half;

	pack_half = (high - low) / 2;
	if (pack_half < 1)
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
		if (count == pack_half)
		{
			pack->mid_value = s[i].nb;
			pack->size = high - low;
			if (pack->size % 2 == 0)
			{
				pack->pair = 0;
				pack->on_a = pack_half;
				pack->on_b = pack_half;
			}
			else
			{
				pack->pair = 1;
				pack->on_a = pack_half;
				pack->on_b = pack_half + 1;
			}
			return(1);
		}
		i++;
	}
//	printf("pack within define\n");
//	print_pack(pack);
	return (-1);
}

int algo_push_swap(t_d *d, t_list **l, int mod, t_pack *old_pack)
{
	t_pack	new_pack;
	int		res;

//	printf("ENTER ALGO with pack info\n");
//	print_pack(old_pack);
//	print_struct(d->size_max, d);
	if (mod == 1 || mod == 0)//regarde slack a
	{
//		printf("***ENTER LOOK A***\n");
		if (mod == 1)
			res = define_pack(d->a, d->size_max - d->size_a, d->size_max - d->size_a + old_pack->on_a, &new_pack);
		if (mod == 0)
			res = define_pack(d->a, 0, d->size_max, &new_pack);
//		printf("new pack:\n");
//		print_pack(&new_pack);
		if (res == 1)
		{
			put_on_b(d, l, &new_pack);
		}
		else
		{
			new_pack.on_a = old_pack->on_a;
			new_pack.on_b = old_pack->on_b;
			new_pack.pair = old_pack->pair;
			new_pack.size = old_pack->size;
			new_pack.mid_value = old_pack->mid_value;
		}
//		printf("new pack:\n");
//		print_pack(&new_pack);
		if (new_pack.on_a > 2)
		{
			algo_push_swap(d, l, 1, &new_pack);
			algo_push_swap(d, l, 2, &new_pack);
		}
		else
		{
			if (new_pack.on_a == 2)
				if (d->a[d->size_max - d->size_a].nb > d->a[d->size_max - d->size_a + 1].nb)
					ft_swap_bis(1, 0, d, l);
			if (new_pack.on_b == 2)
			{
				if (d->b[d->size_max - d->size_b].nb < d->b[d->size_max - d->size_b + 1].nb)
					ft_swap_bis(0, 1, d, l);
				ft_push_bis(1, 0, d, l);
				ft_push_bis(1, 0, d, l);
			}
			else
				algo_push_swap(d, l, 2, &new_pack);
		}
	}
	if (mod == 2)// regarde slack b
	{
//		printf("***ENTER LOOK B***\n");
		res = define_pack(d->b, d->size_max - d->size_b, d->size_max - d->size_b + old_pack->on_b, &new_pack);
		if (res == 1)
		{
			put_on_a(d, l, &new_pack);
		}
		else
		{
			new_pack.on_a = old_pack->on_a;
			new_pack.on_b = old_pack->on_b;
			new_pack.pair = old_pack->pair;
			new_pack.size = old_pack->size;
			new_pack.mid_value = old_pack->mid_value;
		}
		if (new_pack.on_a > 2)
		{
			algo_push_swap(d, l, 1, &new_pack);
			algo_push_swap(d, l, 2, &new_pack);
		}
		else
		{
			if (new_pack.on_a == 2)
				if (d->a[d->size_max - d->size_a].nb > d->a[d->size_max - d->size_a + 1].nb)
					ft_swap_bis(1, 0, d, l);
			if (new_pack.on_b == 2)
			{
				if (d->b[d->size_max - d->size_b].nb < d->b[d->size_max - d->size_b + 1].nb)
					ft_swap_bis(0, 1, d, l);
				ft_push_bis(1, 0, d, l);
				ft_push_bis(1, 0, d, l);
			}
			else
				algo_push_swap(d, l, 2, &new_pack);
		}
	}
	return (1);
}

			
		

