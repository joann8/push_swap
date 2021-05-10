/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:02:55 by jacher            #+#    #+#             */
/*   Updated: 2021/05/10 14:43:40 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

int	is_inst(char *line)
{
	if (ft_strncmp(line, "ra", 3) == 0)
		return (1);
	else if (ft_strncmp(line, "rb", 3) == 0)
		return (1);
	else if (ft_strncmp(line, "rr", 3) == 0)
		return (1);
	else if (ft_strncmp(line, "sa", 3) == 0)
		return (1);
	else if (ft_strncmp(line, "sb", 3) == 0)
		return (1);
	else if (ft_strncmp(line, "ss", 3) == 0)
		return (1);
	else if (ft_strncmp(line, "rra", 4) == 0)
		return (1);
	else if (ft_strncmp(line, "rrb", 4) == 0)
		return (1);
	else if (ft_strncmp(line, "rrr", 4) == 0)
		return (1);
	else if (ft_strncmp(line, "pa", 3) == 0)
		return (1);
	else if (ft_strncmp(line, "pb", 3) == 0)
		return (1);
	else
		return (0);
}
