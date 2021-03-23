/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:56:40 by jacher            #+#    #+#             */
/*   Updated: 2021/03/23 11:38:12 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H

# define SORT_H

#include <stdio.h> //a supprimer
#include <limits.h> //a supprimer

# include <stdlib.h>
# include <unistd.h>

# include "./libft/libft.h"
# include "./libft/get_next_line_bonus.h"

typedef	struct	s_level
{
	int level;
	int a;
	int b;
}				t_level;

typedef struct	s_pack
{
	int mid_value;
	int	pair;
	int size;
	int on_a;
	int	on_b;
} 				t_pack;		

typedef struct	s_mid
{
	int i;
	int nb;
	int half;
}				t_m;

typedef struct	s_stack
{
	int nb;
	int bol;
}				t_s;

typedef struct	s_data
{
	t_s *a;
	t_s *b;
	int	size_a;
	int size_max;
	int size_b;
}				t_d;

//CHECK ARGS
int		check_args(int ac, char **av, t_d *d);
void	ft_free_data(t_d *d);
void	ft_free_list(t_list *l);
int		check_doublons(t_d *d);
int		check_args_several(int ac, char **av, t_d *d);
int		check_args_single(char **av, t_d *d);

// CHECK ORDER
int		check_order(t_d *d);
int		check_int_order_a(t_d *d);
int		check_int_order_b(t_d *d);
int		check_int_order_a_range(t_s *s, int low, int high);
int		check_int_order_b_range(t_s *s, int low, int high);

//INSTRUCTIONS
int		check_inst(char *str);
void	execute_inst(char *inst, t_d *d, int a, int b);
int 	checker_test(t_list **l, t_d *d);
void	execute_inst_test(t_list **l, t_d *d);
void	ft_swap(int bol_a, int bol_b, t_d *d, int *pos);
void	ft_push(int bol_a, int bol_b, t_d *d, int *pos);
void	ft_rotate(int bol_a, int bol_b, t_d *d, int *pos);
void	ft_rrotate(int bol_a, int bol_b, t_d *d, int *pos);
void	ft_swap_bis(int bol_a, int bol_b, t_d *d, t_list **l);
void	ft_push_bis(int bol_a, int bol_b, t_d *d, t_list **l);
void	ft_rotate_bis(int bol_a, int bol_b, t_d *d, t_list **l);
void	ft_rrotate_bis(int bol_a, int bol_b, t_d *d, t_list **l);
void	update_inst(t_list **l);

// ERROR
int		ft_error(void);

// FT PUSH SWAP
int		sort_simple(t_d *d, t_list **l);
void	swap_rotate_first_a(t_d *d, t_list **l);
void	swap_rotate_first_b(t_d *d, t_list **l);
int 	algo_push_swap(t_d *d, t_list **l, int mod, t_pack *old_pack);
int	put_on_b(t_d *d, t_list **l, t_pack *pack);
int 	define_pack(t_s *s, int low, int high, t_pack *old_pack);
int		sort_complex(t_d *d, t_list **l);
int		sort_complex_phase_one(t_d *d, t_list **l, t_level *lev, int i, int *blocked);

//OTHERS
void	print_struct(int ac, t_d *d);
void	print_pack(t_pack *pack);
int		print_list(t_list *l, int mod);
int		calculate_levels(t_d *d);

#endif
