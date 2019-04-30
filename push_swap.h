/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 23:51:17 by tsimonis          #+#    #+#             */
/*   Updated: 2019/03/03 22:36:00 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "printf/ft_printf.h"

typedef struct		s_list
{
	int				value;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

int					print_command(char fistse[3], t_list *top, t_list *b,
								int flfd[2]);
void				free_argv(char **argv);
size_t				ft_strlen(const char *str);
long long int		ft_atoi_new(const char *str);
t_list				*ft_lstnew(int value, t_list *prev, t_list *next);
void				print_stack(t_list *top, char fistse[3],
								char *color, int fd);
int					swap_stack(t_list **top);
int					push_stack(t_list **a, t_list **b);
int					rotate_forward(t_list **top);
int					rotate_backward(t_list **top);
int					check_a_letter(char ss[3], t_list **top,
								t_list *b, int flfd[3]);
int					check_b_letter(char ss[3], t_list **top,
								t_list *b, int flfd[3]);
int					read_commands(t_list **a, t_list **b, int fd, int fl);
int					is_sorted(t_list *top, int fl);
int					no_duplicates(t_list *top);
int					read_args(int argc, char *argv[], t_list **top, int fl);
void				merge_sort(t_list **top, t_list **b,
							int (*vars)[7], char stack);
void				merge_sort_without_rr(t_list **top, t_list **b,
										int (*vars)[7], char stack);
int					ft_lstdel(t_list **top);
void				ft_lstdelone(t_list **top);
int					ft_lstlen(t_list *top);
char				**ft_strsplit(char const *s, char c);
void				arrays_init(char (*ss)[4], char (*fistse)[3],
								int (*flfd)[3]);
int					check_condition(int fd, char (*ss)[4],
						char (*fistse)[3], int (*flfd)[3]);
int					condition(char ss[4], int fd, char (*fistse)[3]);
int					init_of_vars(int (*flfd)[3], char (*fistse)[3], char ss[4]);
int					read_end(char ss[4], int fd, t_list *b);
int					final(int fd, int faut_free, char **argv);
int					complex_condition(char **argv, int (*vars)[7],
								char (*fistse)[3], int flfd[2]);
int					vars_init(char (*fistse)[3], int (*flfd)[2],
								int (*vars)[7]);
int					main_func(char (*fistse)[3], int (*flfd)[2],
						int (*vars)[7], char ***argv);
int					over_main(char (*fistse)[3], int (*flfd)[2],
						int (*vars)[7], char ***argv);
void				comp_condition(char (*fistse)[3], t_list **a,
						t_list *b, int flfd[2]);
void				initia(int (*flfd)[2], char (*fistse)[3],
						char stack, int (*vars)[7]);
int					process_triple(t_list **a, t_list *b,
						char stack, int (*vars)[7]);
int					ft_min(int a, int b);
int					ft_abs(int a);
int					find_median(t_list *top, int n);
int					find_next_median(t_list *top, int n, int sign);
int					first_check(char (*fistse)[4], int (*vars)[7],
							t_list **top, t_list **b);
void				first_func(int (*vars)[7], t_list **top,
							char (*fistse)[4], int (*flfd)[4]);
int					second_func(int (*vars)[7], t_list **top,
							t_list **b, int (*flfd)[4]);
void				third_func(int (*vars)[7], t_list **top,
							t_list **b, int (*flfd)[4]);
int					fourth_func(int (*vars)[7], int flfd[4]);
int					fifth_func(int (*vars)[7], int flfd[4], char (*fistse)[4]);
int					sixth_func(int (*vars)[7], int (*flfd)[4],
							char (*fistse)[4]);
int					seventh_func(char (*fistse)[4]);
int					eighth_func(int (*vars)[7], t_list **top, int flfd[4]);
int					ninth_func(int (*vars)[7], t_list **top, int flfd[4]);
int					tenth_func(int (*vars)[7]);
int					eleventh_func(t_list **arr[2], int (*vars)[7],
							int (*flfd)[4], char (*fistse)[4]);
void				twelfth(int (*vars)[7], t_list **arr[2],
							int (*flfd)[4], char fistse[4]);
void				func_one(char (*fistse)[3], t_list **a,
							t_list *b, int (*flfd)[2]);
void				func_two(char (*fistse)[3], t_list **arr[2],
							int (*flfd)[2], int (*vars)[7]);
void				func_three(char (*fistse)[3], t_list **a,
							t_list *b, int (*flfd)[2]);
void				func_four(char (*fistse)[3], t_list **a,
							t_list *b, int (*flfd)[2]);
int					first_part_(int (*flfd)[7], char (*fistse)[3],
							t_list **arr[2], int (*vars)[7]);
int					second_part(int (*flfd)[7], char (*fistse)[3],
							t_list **arr[2], int (*vars)[7]);
void				merge_sort(t_list **top, t_list **b,
							int (*vars)[7], char stack);
int					process_triple_without_rr(t_list **a, t_list *b,
							char stack, int (*vars)[7]);
int					is_sorted_n(t_list *top, int n, int fl);
int					third_part(int (*flfd)[7], char (*fistse)[3],
							t_list **arr[2], int (*vars)[7]);
void				fourth_part(int (*flfd)[7], char (*fistse)[3],
							t_list **arr[2], int (*vars)[7]);
void				fifth_part(int (*flfd)[7], t_list **arr[2],
							int (*vars)[7]);
void				sixth_part(int (*flfd)[7], t_list **arr[2],
							int (*vars)[7]);
void				seventh_part(int (*flfd)[7], char (*fistse)[3],
							t_list **arr[2], int (*vars)[7]);
void				merge_sort_without_rr(t_list **top, t_list **b,
							int (*vars)[7], char stack);
void				last_init(int (*vars)[7], t_list *b,
							char (*fistse)[3], int (*flfd)[2]);
void				merge_sort_addition(char (*fistse)[4], t_list **arr[2],
							int (*flfd)[4], int (*vars)[7]);

#endif
