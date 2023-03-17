/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:52:06 by aouchaad          #+#    #+#             */
/*   Updated: 2023/03/16 17:27:52 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_strjoin
{
	int		totlen;
	int		i;
	int		j;
	int		s1_len;
}	t_strjoin;

typedef struct s_utils
{
	int	num_a_arg;
	int	num_b_arg;
	int	wanted_index;
	int	perfect_pos;
	int	min;
	int	i;
	int	count;
	int	a_pos;
	int	b_pos;
	int	index;
	int	pos;
	int	mini;
	int	arg_num;
	int	min_index;
	int	top_index;
	int	old_index_value;
	int	top_index_value;
}	t_utils;

typedef struct s_util1
{
	int	*numbers;
	int	*list_len;
	int	*list_index;
	int	*numbers_index;
	int	number_of_args;
	int	max_index;
	int	numbers_index_len;
	int	i;
	int	j;
}	t_util1;

typedef struct s_split
{
	char	**strings;
	int		i;
	int		j;
	int		word_count;
}	t_split;

int		ft_atoi(char *string);
int		how_meny_args(char **arguments_splited);
int		best_move(t_list **stack_a, t_list **stack_b, t_utils *utils);
int		arg_strlen(char *string);
int		perfect_pos(t_list **stack_a, t_list **stack_b, int node_index);
int		how_meny_args(char **arguments_splited);
int		int_min_max(char **av, long **numbers, int number_of_args);
int		check_if_sorted(t_list **stack_a);
int		min_pos(t_list **stack_a);
int		moves_count(t_list **stack_a, t_list **stack_b,
			int index, t_utils *utils);
char	**ft_split(char *s, char c);
char	**arguments_check(char **av);
char	*ft_strjoin(char *s1, char *s2);
void	stack_swap(t_list **stack);
void	push_stack(t_list **stack_1, t_list **stack_2);
void	stack_rotate(t_list **stack);
void	stack_revers_rotate(t_list **stack);
void	best_sorted_list(t_list **stack_a, t_list **stack_b);
void	last_rotate(t_list **stack_a);
void	sa(t_list **stack_a, int print);
void	sb(t_list **stack_b, int print);
void	ra(t_list **stack_a, int print);
void	rb(t_list **stack_b, int print);
void	rra(t_list **stack_a, int print);
void	rrb(t_list **stack_b, int print);
void	ss(t_list **stack_a, t_list **stack_b, int print);
void	pa(t_list **stack_a, t_list **stack_b, int print);
void	pb(t_list **stack_a, t_list **stack_b, int print);
void	rr(t_list **stack_a, t_list **stack_b, int print);
void	rrr(t_list **stack_a, t_list **stack_b, int print);
void	first_case(t_list **stack_a, t_list **stack_b, t_utils *utils);
void	second_case(t_list **stack_a, t_list **stack_b, t_utils *utils);
void	third_case(t_list **stack_a, t_list **stack_b, t_utils *utils);
void	fourth_case(t_list **stack_a, t_list **stack_b, t_utils *utils);
void	push_to_a(t_list **stack_a, t_list **stack_b);
void	print_error(void);
void	long_arg_check(char **arg, int *i);
void	five_and_less_sort(t_list **stack_a, t_list **stack_b, int ac);
void	free_stacks(t_list **stack_a, t_list **stack_b);
long	ft_atod(char *string);
int		_ft_strlen(char *string);
char	*_ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *string);
t_list	*ft_lstnew(t_list *stack_a, int content);
char	*get_next_line(int fd);
char	*ft_strchr(char *string, int chrstr);
int		ft_strcmp(char **s1, char *s2);
#endif
