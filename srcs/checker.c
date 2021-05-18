/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:51:22 by jacher            #+#    #+#             */
/*   Updated: 2021/05/10 18:13:22 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

void	get_instructions_see(t_d *d, char *line, int mod)
{
	if (mod == 0)
	{
		ft_putstr_fd(BLU, 1);
		ft_putstr_fd("Initial state", 1);
		ft_putstr_fd(DEF, 1);
		print_struct(d->size_max, d);
	}
	if (mod == 1)
	{
		if (is_inst(line) == 1)
		{
			ft_putstr_fd(BLU, 1);
			ft_putstr_fd("-> ", 1);
			ft_putstr_fd(line, 1);
			ft_putstr_fd(DEF, 1);
			print_struct(d->size_max, d);
		}
	}
}

int		get_instructions(t_d *d, int *count, t_res *r)
{
	char	*line;
	int		ret;
	int		mod;

	mod = 0;
	if (r->f_see == 1)
		get_instructions_see(d, NULL, 0);
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (execute_inst(line, d) == -1)
			mod = 1;
		if (r->f_see == 1)
			get_instructions_see(d, line, 1);
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
		if (r->f_col == 1)
			ft_putstr_fd(GRN, 1);
		if (r->f_nb == 1)
		{
			ft_putstr_fd(ft_itoa(count), 1);
			ft_putstr_fd(" instructions --> OK\n", 1);
		}
		else
			ft_putstr_fd("OK\n", 1);
	}
	else
	{
		if (r->f_col == 1)
			ft_putstr_fd(RED, 1);
		if (r->f_nb == 1)
		{
			ft_putstr_fd(ft_itoa(count), 1);
			ft_putstr_fd(" instructions --> KO\n", 1);
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
	if (check_args(ac, av, &d, &r) < 0)
		return (1);
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
	ft_free_data(&d);
	return (1);
}
