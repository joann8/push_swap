/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:51:22 by jacher            #+#    #+#             */
/*   Updated: 2021/05/07 17:16:49 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

int		get_instructions(t_d *d, int *count, t_res *r)
{
	char	*line;
	int		ret;
	int 	mod;

	mod = 0;
	if (r->f_see == 1)
	{
		ft_putstr_fd("Initial state", 1);
		print_struct2(d->size_max, d);
	}
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (execute_inst(line, d) == -1)
			mod = 1;

		if (r->f_see == 1)
		{
			ft_putstr_fd(line, 1);
			print_struct2(d->size_max, d);
		}
		*count += 1;
		free(line);
	}
	if (mod == 1)
		return (-1);
	return (ret);
}

void	print_result(t_d *d, t_res *r, int count)
{
	if (check_order(d) == 1)
		
	{
		if (r->f_nb == 1)
		{
			ft_putstr_fd("OK #nb of instructions = ", 1);
			ft_putstr_fd(ft_itoa(count), 1);
			ft_putstr_fd("\n", 1);
		}
		else
			ft_putstr_fd("OK\n", 1);
	}
	else
	{
		if (r->f_nb == 1)
		{
			ft_putstr_fd("KO #nb of instructions = ", 1);
			ft_putstr_fd(ft_itoa(count), 1);
			ft_putstr_fd("\n", 1);
		}
		else
			ft_putstr_fd("K0\n", 1);
	}
}


int		main(int ac, char **av)
{
	t_d		d;
	t_res	r;
	int		count;

	count = 0;
	init_flags(&r);
	if (check_args(ac, av, &d, &r) == -1)
		return (1);
//	print_struct(d.size_max, &d);
	if (get_instructions(&d, &count, &r) == -1)
	{
		if (r.f_err == 1)
			ft_putstr_fd("Error : wrong instruction\n", 2);
		else
			ft_error();
		ft_free_data(&d);
		return (1);
	}
	print_result(&d, &r, count);
	/*
	if (check_order(&d) == 1)
		printf("OK\n");
	else
		printf("KO\n");*/
	//print_struct(d.size_max, &d);
	ft_free_data(&d);
	return (1);
}
