/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:56:40 by jacher            #+#    #+#             */
/*   Updated: 2021/05/11 18:48:43 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H

# define SORT_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define DEF "\e[0m"
# define BLK "\e[0;30m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"
# define I_MAX 2147483647
# define I_MIN -2147483648

typedef struct	s_result
{
	int			f_nb;
	int			f_err;
	int			f_see;
	int			f_col;
}				t_res;

typedef struct	s_pack
{
	int			mid_value;
	int			pair;
	int			size;
	int			on_a;
	int			on_b;
}				t_pack;

typedef struct	s_stack
{
	int			nb;
	int			bol;
}				t_s;

typedef struct	s_data
{
	t_s			*a;
	t_s			*b;
	int			size_a;
	int			size_max;
	int			size_b;
}				t_d;

int				check_args(int ac, char **av, t_d *d, t_res *r);
int				check_doublons(t_d *d, t_res *r);
int				check_args_several(int ac, char **av, t_d *d, int start);
int				check_args_single(char **av, t_d *d, int start);
void			init_flags(t_res *r);
int				check_order(t_d *d);
int				check_int_order_a(t_d *d);
int				check_int_order_b(t_d *d);
int				check_int_order_a_range(t_s *s, int low, int high);
int				check_int_order_b_range(t_s *s, int low, int high);
int				check_inst(char *str);
int				is_inst(char *str);
void			execute_inst_test(t_list **l, t_d *d);
int				execute_inst(char *line, t_d *d);
void			ft_swap(int bol_a, int bol_b, t_d *d);
void			ft_push(int bol_a, int bol_b, t_d *d);
void			ft_rotate(int bol_a, int bol_b, t_d *d);
void			ft_rrotate(int bol_a, int bol_b, t_d *d);
void			ft_swap_bis(int bol_a, int bol_b, t_d *d, t_list **l);
void			ft_push_bis(int bol_a, int bol_b, t_d *d, t_list **l);
void			ft_rotate_bis(int bol_a, int bol_b, t_d *d, t_list **l);
void			ft_rrotate_bis(int bol_a, int bol_b, t_d *d, t_list **l);
int				update_inst(t_list **l);
int				ft_error(void);
int				ft_print_err(char *s1, char *s2, char *s3, int ret_wanted);
int				sort_simple(t_d *d, t_list **l);
void			swap_rotate_first_a(t_d *d, t_list **l, int i, int action);
int				algo_push_swap(t_d *d, t_list **l, int mod, t_pack *old_pack);
int				put_on_b(t_d *d, t_list **l, t_pack *pack, int moved);
int				put_on_a(t_d *d, t_list **l, t_pack *pack, int moved);
int				define_pack(t_s *s, int low, int high, t_pack *old_pack);
void			ft_free_list(t_list *l);
void			ft_free_data(t_d *d);
void			init_flags(t_res *r);
void			print_struct(int ac, t_d *d);
int				print_list(t_list *l, int mod);

#endif
