# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: omulder <omulder@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/14 12:14:20 by omulder        #+#    #+#                 #
#    Updated: 2020/01/14 17:02:47 by omulder       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker
LIBFT= ./libft/libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
DEBUGFLAGS = -fsanitize=address -fno-omit-frame-pointer -g
INCLUDES = -I./ -I./libft/ -I./inc
OBJDIR = objects/
LINK = -L./libft -lft
VPATH = ./srcs-checker ./srcs-swap
SRCSCHECK = checker opp_p opp_r opp_rr opp_s stack
SRCSPUSH = 
OBJCHECK := $(SRCSCHECK:%=%.o)
OBJPUSH:= $(OBJPUSH:%=%.o)
SRCSCHECK := $(SRCSCHECK:%=%.c)
SRCSPUSH := $(SRCSPUSH:%=%.c)

all: $(LIBFT) $(NAME) $(CHECKER)

$(NAME): $(LIBFT) $(OBJPUSH)
	$(CC) $(FLAGS) $(INCLUDES) $(LINK) -o $(NAME) $^

$(CHECKER): $(LIBFT) $(OBJCHECK)
	$(CC) $(FLAGS) $(INCLUDES) $(LINK) -o $(CHECKER) $^

$(LIBFT):
	$(MAKE) -C libft

$(OBJPUSH): $(SRCSPUSH)
	$(CC) $(FLAGS) $(INCLUDES) -c $^

$(OBJCHECK): $(SRCSCHECK)
	$(CC) $(FLAGS) $(INCLUDES) -c $^

clean:
	rm -f $(OBJPUSH) $(OBJCHECK)
	$(MAKE) -C libft clean
	
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

norm:
	@norminette $(FILES) ft_ls.h