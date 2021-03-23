/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:35:55 by jacher            #+#    #+#             */
/*   Updated: 2021/03/22 13:20:29 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

int			main(int ac, char **av)
{
	t_d		d;
	t_d		d2;
	t_list	*l;
	t_list *l2;
	int		count;
	t_level *lev;

	l = NULL;
	l2 = NULL;
	count = check_args(ac, av, &d);
	if (count == -1)
		return (1);
/*	if (check_order(&d) == 1)
	{
		ft_free_data(&d);
		ft_free_list(l);
		return (1);
	}
//	printf("sort simple res:\n");
	sort_simple(&d, &l);
	print_list(l);
	ft_free_list(l);
	ft_free_data(&d);
	*/
	count = check_args(ac, av, &d2);
	if (count == -1)
		return (1);
	if (check_order(&d2) == 1)
	{
		ft_free_data(&d2);
		ft_free_list(l2);
		return (1);
	}
//	printf("sort complex res:\n");
	int size;
	size = calculate_levels(&d);
	lev = malloc(sizeof(t_level) * (size + 1));
	if (lev == NULL)
		return (1);
	lev[size].level = INT_MAX;
	lev[size].a = INT_MAX;
	lev[size].b = INT_MAX;
	printf("lev[%d].level = %d\n", size, lev[size].level);
	int blocked;
	blocked = 0;
	sort_complex_phase_one(&d2, &l2, lev, 0, &blocked);
//	printf("exit\n");
	//update_inst(l);
//	print_list(l2);
	print_struct(d2.size_max, &d2);
	ft_free_data(&d2);
	ft_free_list(l2);
	return (1);
}
