/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rrotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:08:11 by jacher            #+#    #+#             */
/*   Updated: 2021/03/12 18:59:47 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

void	ft_rrotate_a(t_d *d)
{
	int tmp1;
	int tmp2;
	int	i;

	//	printf(">>> Reverse Rotate a <<<\n");//A ENLEVER
	i = 0;
	while (d->a[i].bol == 0 && i < d->size_max)
		i++;
	if (d->size_max - i <= 1)
		return ;
	tmp1 = d->a[i].nb;
	d->a[i].nb = d->a[d->size_max - 1].nb;
	i++;
	while (i < d->size_max)
	{
		tmp2 = d->a[i].nb;
		d->a[i].nb = tmp1;
		tmp1 = tmp2;
		i++;
	}
}

void	ft_rrotate_b(t_d *d)
{
	int tmp1;
	int tmp2;
	int	i;

	//printf(">>> Reverse Rotate b <<<\n");//A ENLEVER
	i = 0;
	while (d->b[i].bol == 0 && i < d->size_max)
		i++;
	if (d->size_max - i <= 1)
		return ;
	tmp1 = d->b[i].nb;
	d->b[i].nb = d->b[d->size_max - 1].nb;
	i++;
	while (i < d->size_max)
	{
		tmp2 = d->b[i].nb;
		d->b[i].nb = tmp1;
		tmp1 = tmp2;
		i++;
	}
}

void	ft_rrotate(int bol_a, int bol_b, t_d *d, int *pos)
{
	if (bol_a == 1)
		ft_rrotate_a(d);
	if (bol_b == 1)
		ft_rrotate_b(d);
	*pos += 4;
}

void	ft_rrotate_bis(int bol_a, int bol_b, t_d *d, t_list **l)
{
	if (bol_a == 1)
	{
		ft_rrotate_a(d);
		ft_lstadd_back(l, ft_lstnew((void*)("rra")));
	}
	if (bol_b == 1)
	{
		ft_rrotate_b(d);
		ft_lstadd_back(l, ft_lstnew((void*)("rrb")));
	}
	//	print_struct(d->size_max + 1, d);
}
