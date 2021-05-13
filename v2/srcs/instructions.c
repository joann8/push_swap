/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:02:55 by jacher            #+#    #+#             */
/*   Updated: 2021/05/13 22:53:16 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

int		execute_inst(char *line, t_d *d)
{
	if (ft_strncmp(line, "ra", 3) == 0)
		ft_rotate(1, 0, d);
	else if (ft_strncmp(line, "rb", 3) == 0)
		ft_rotate(0, 1, d);
	else if (ft_strncmp(line, "rr", 3) == 0)
		ft_rotate(1, 1, d);
	else if (ft_strncmp(line, "sa", 3) == 0)
		ft_swap(1, 0, d);
	else if (ft_strncmp(line, "sb", 3) == 0)
		ft_swap(0, 1, d);
	else if (ft_strncmp(line, "ss", 3) == 0)
		ft_swap(1, 1, d);
	else if (ft_strncmp(line, "rra", 4) == 0)
		ft_rrotate(1, 0, d);
	else if (ft_strncmp(line, "rrb", 4) == 0)
		ft_rrotate(0, 1, d);
	else if (ft_strncmp(line, "rrr", 4) == 0)
		ft_rrotate(1, 1, d);
	else if (ft_strncmp(line, "pa", 3) == 0)
		ft_push(1, 0, d);
	else if (ft_strncmp(line, "pb", 3) == 0)
		ft_push(0, 1, d);
	else
		return (-1);
	return (0);
}
