/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:51:22 by jacher            #+#    #+#             */
/*   Updated: 2021/05/07 12:30:12 by jacher           ###   ########.fr       */
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
	printf("count = %d\n", count);
	execute_inst(inst, d, 0, 0);
	free(inst);
	return (1);
}

int	get_instructions_test(t_d *d)
{
	char	*line;
	int		count;

	count = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (execute_inst_test2(line, d) == -1)
		 {
		 	free(line);
			return (-1);
		}
		count++;
		free(line);
	}
	free(line);
	printf("count = %d\n", count);
	return (1);
}



int	main(int ac, char **av)
{
	t_d		d;
	
	if (check_args(ac, av, &d) == -1)
		return (1);
//	print_struct(d.size_max, &d);
	if (get_instructions_test(&d) == -1)
	{
		ft_free_data(&d);
		return (1);
	}
	if (check_order(&d) == 1)
		printf("OK\n");
	else
		printf("KO\n");
	//print_struct(d.size_max, &d);
	ft_free_data(&d);
	return (1);
}
