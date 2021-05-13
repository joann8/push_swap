/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:08:11 by jacher            #+#    #+#             */
/*   Updated: 2021/05/13 12:00:20 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

void	ft_rotate_a(t_d *d)
{
	int tmp;
	int	i;

	i = 0;
	while (d->a[i].bol == 0 && i < d->size_max)
		i++;
	if (d->size_max - i <= 1)
		return ;
	tmp = d->a[i].nb;
	while (i < d->size_max - 1)
	{
		d->a[i].nb = d->a[i + 1].nb;
		i++;
	}
	d->a[i].nb = tmp;
}

void	ft_rotate_b(t_d *d)
{
	int tmp;
	int	i;

	i = 0;
	while (d->b[i].bol == 0 && i < d->size_max)
		i++;
	if (d->size_max - i <= 1)
		return ;
	tmp = d->b[i].nb;
	while (i < d->size_max - 1)
	{
		d->b[i].nb = d->b[i + 1].nb;
		i++;
	}
	d->b[i].nb = tmp;
}

void	ft_rotate(int bol_a, int bol_b, t_d *d)
{
	if (bol_a == 1)
		ft_rotate_a(d);
	if (bol_b == 1)
		ft_rotate_b(d);
}

void	ft_rotate_bis(int bol_a, int bol_b, t_d *d, t_list **l)
{
	t_list	*new;
	char	*tmp;

	if (bol_a == 1)
	{
		if (d->size_a < 2)
			return;
		ft_rotate_a(d);
		tmp = ft_strdup("ra");
		new = ft_lstnew(tmp);
		ft_lstadd_back(l, new);
	}
	if (bol_b == 1)
	{
		if (d->size_b < 2)
			return;
		ft_rotate_b(d);
		tmp = ft_strdup("rb");
		new = ft_lstnew(tmp);
		ft_lstadd_back(l, new);
	}
}
