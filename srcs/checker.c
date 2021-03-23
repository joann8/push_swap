/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:51:22 by jacher            #+#    #+#             */
/*   Updated: 2021/03/15 18:22:38 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

int	get_instructions(t_d *d)
{
	char	*line;
	char	*inst;
	char	*tmp;
	int		count;

	count = 0;
	inst = ft_strdup("");
	while (get_next_line(0, &line) > 0)
	{
		if (count != 0)
		{
			tmp = inst;
			inst = ft_strjoin(tmp, "\n");
			free(tmp);
			
		}
		tmp = inst;
		inst = ft_strjoin(tmp, line);
		free(tmp);
		count++;
		free(line);
		if (inst == NULL)
			return (-1);
	}
	free(line);
	if (check_inst(inst) == -1)
	{
		free(inst);
		return (ft_error());
	}
	execute_inst(inst, d, 0, 0);
	free(inst);
	return (1);
}

int	main(int ac, char **av)
{
	t_d		d;

	if (check_args(ac, av, &d) == -1)
		return (1);
	if (get_instructions(&d) == -1)
	{
		ft_free_data(&d);
		return (1);
	}
	if (check_order(&d) == 1)
		printf("OK\n");
	else
		printf("KO\n");
	ft_free_data(&d);
	return (1);
}
