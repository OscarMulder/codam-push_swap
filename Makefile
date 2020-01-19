# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: omulder <omulder@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/14 12:14:20 by omulder        #+#    #+#                 #
#    Updated: 2020/01/19 15:47:59 by omulder       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker
LIBFT= ./libft/libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
DEBUGFLAGS = -fsanitize=address -fno-omit-frame-pointer -g
INCLUDES = -I./ -I./libft/ -I./inc -I../libft
LINK = -L./libft -lft
VPATH = ./srcs-checker ./srcs-push_swap ./srcs-stack
SRCSCHECK = checker
SRCSSTACK = opp_p opp_r opp_rr opp_s stack
SRCSPUSH = push_swap
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
