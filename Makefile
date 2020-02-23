# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: omulder <omulder@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/14 12:14:20 by omulder        #+#    #+#                 #
#    Updated: 2020/02/23 18:28:58 by omulder       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker
LIBFT= ./libft/libft.a
CC = gcc
# FLAGS = -Wall -Werror -Wextra -g
FLAGS = -g
DEBUGFLAGS = -fsanitize=address -fno-omit-frame-pointer -g
INCLUDES = -I./ -I./libft/ -I./inc -I../libft
LINK = -L./libft -lft
VPATH = ./srcs-checker ./srcs-push_swap ./srcs-stack
SRCSCHECK = checker
SRCSSTACK = opp_p opp_r opp_rr opp_s stack
SRCSPUSH = push_swap oplist_helpers opp_do opp_wrap_p opp_wrap_r opp_wrap_rr \
opp_wrap_s stacks_helpers fake_sort stupid_sort less_stupid_sort quick_sort \
sort_2_inplace sort_3_inplace optimize rotation_optimizer
OBJCHECK := $(SRCSCHECK:%=%.o)
OBJPUSH:= $(SRCSPUSH:%=%.o)
OBJSTACK:= $(SRCSSTACK:%=%.o)
SRCSCHECK := $(SRCSCHECK:%=%.c)
SRCSPUSH := $(SRCSPUSH:%=%.c)
SRCSSTACK := $(SRCSSTACK:%=%.c)

all: $(LIBFT) $(OBJPUSH) $(OBJSTACK) $(OBJCHECK) $(NAME) $(CHECKER)

$(NAME): $(LIBFT) $(OBJSTACK) $(OBJPUSH)
	$(CC) $(FLAGS) $(INCLUDES) $(LINK) -o $(NAME) $^

$(CHECKER): $(LIBFT) $(OBJSTACK) $(OBJCHECK)
	$(CC) $(FLAGS) $(INCLUDES) $(LINK) -o $(CHECKER) $^

$(LIBFT):
	$(MAKE) -C libft

$(OBJPUSH): $(SRCSPUSH)
	$(CC) $(FLAGS) $(INCLUDES) -c $^

$(OBJCHECK): $(SRCSCHECK)
	$(CC) $(FLAGS) $(INCLUDES) -c $^

$(OBJSTACK): $(SRCSSTACK)
	$(CC) $(FLAGS) $(INCLUDES) -c $^

clean:
	rm -f $(OBJPUSH) $(OBJCHECK) $(OBJSTACK)
	$(MAKE) -C libft clean
	
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

norm:
	@norminette $(FILES) ft_ls.h
