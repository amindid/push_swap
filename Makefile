# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/19 14:38:00 by aouchaad          #+#    #+#              #
#    Updated: 2023/03/20 15:09:44 by aouchaad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	arguments_check.c \
	   		ft_atod.c \
	   		ft_atoi.c \
	   		ft_lstnew.c \
	   		ft_split.c \
	   		ft_strjoin.c \
	   		ft_strlen.c \
	   		stack_swap.c \
			push_stack.c \
			arg_strlen.c \
			stack_rotate.c \
			stack_revers_rotate.c \
			best_sorted_list.c \
			perfect_pos.c \
			best_move.c \
			last_rotate.c \
			push_to_a.c \
			cases.c \
			arg_check_utils.c \
			moves_count.c \
			check_if_sorted.c \
			five_and_less_sort.c \
			min_pos.c \
			free_stacks.c 

BSRCS	=	get_next_line.c \
			get_next_line_utils.c \
			ft_strcmp.c \
			arguments_check.c \
	   		ft_atod.c \
	   		ft_atoi.c \
	   		ft_lstnew.c \
	   		ft_split.c \
	   		ft_strjoin.c \
	   		ft_strlen.c \
	   		stack_swap.c \
			push_stack.c \
			arg_strlen.c \
			stack_rotate.c \
			stack_revers_rotate.c \
			arg_check_utils.c \
			check_if_sorted.c \
			free_stacks.c \
			ruls.c 
			

OBJS	=	${SRCS:.c=.o}

BOBJS	=	${BSRCS:.c=.o}

NAME	=	push_swap

BNAME	=	checker

CC		= 	cc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

all : ${NAME}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

bonus :	${BNAME}

${BNAME} : ${BOBJS} checker.c push_swap.h
	${CC} ${CFLAGS} ${BOBJS} checker.c -o $@

${NAME} : ${OBJS} main.c push_swap.h
	${CC} ${CFLAGS} ${OBJS} main.c -o $@

clean :
	${RM} ${OBJS} ${BOBJS}

fclean : clean
	${RM} ${NAME} ${BNAME}

both : ${NAME} ${BNAME} clean

re : fclean all