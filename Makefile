# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: omulder <omulder@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/14 12:14:20 by omulder       #+#    #+#                  #
#    Updated: 2020/08/02 12:47:15 by omulder       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker
LIBFT= ./libft/libft.a
CC = gcc
DEBUGFLAGS = -fsanitize=address -g
FLAGS = -Wall -Werror -Wextra
INCLUDES = -I./ -I./libft/ -I./inc -I../libft
LINK = -L./libft -lft
VPATH = ./srcs-checker ./srcs-push_swap ./srcs-stack
SRCSCHECK = checker
SRCSSTACK = opp_p opp_r opp_rr opp_s stack stack_checker
SRCSPUSH = push_swap oplist_helpers opp_do opp_wrap_p opp_wrap_r opp_wrap_rr \
opp_wrap_s stacks_helpers add_sorted_positions quick_sort push_back \
sort_2_inplace sort_3_inplace optimize optimize_rot optimize_push \
optimize_rev_rot optimize_rot_a optimize_rot_b insertion_sort small_sort \
insertion_helpers prepare_inserting small_helpers return_error rot_a_sorted
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
	rm -f $(NAME) $(CHECKER)
	$(MAKE) -C libft fclean

re: fclean all
