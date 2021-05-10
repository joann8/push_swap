/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:25:51 by jacher            #+#    #+#             */
/*   Updated: 2021/05/10 17:32:00 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

void	print_struct_b(int size, t_d *d)
{
	int j;

	j = size - 1;
	ft_putstr_fd("STACK B: ", 1);
	while (j >= 0)
	{
		if (d->b[j].bol == 1)
		{
			ft_putstr_fd(ft_itoa(d->b[j].nb), 1);
			ft_putstr_fd(" ", 1);
		}
		if (j == 0)
			ft_putstr_fd("\n", 1);
		j--;
	}
}

void	print_struct(int size, t_d *d)
{
	int j;

	j = size - 1;
	ft_putstr_fd("\nSTACK A: ", 1);
	ft_putstr_fd(DEF, 1);
	while (j >= 0)
	{
		if (d->a[j].bol == 1)
		{
			ft_putstr_fd(ft_itoa(d->a[j].nb), 1);
			ft_putstr_fd(" ", 1);
		}
		if (j == 0)
			ft_putstr_fd("\n", 1);
		j--;
	}
	print_struct_b(size, d);
	ft_putstr_fd("\n", 1);
}

int		print_list(t_list *l, int mod)
{
	t_list	*tmp;
	int		count;

	tmp = l;
	count = 0;
	while (tmp)
	{
		if (mod == 1 || mod == 2)
		{
			ft_putstr_fd(tmp->content, 1);
			ft_putstr_fd("\n", 1);
		}
		count++;
		tmp = tmp->next;
	}
	return (count);
}
