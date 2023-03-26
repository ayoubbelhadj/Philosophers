# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 16:07:04 by abelhadj          #+#    #+#              #
#    Updated: 2023/03/24 16:21:23 by abelhadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

CC		= cc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

UTILS	= utils/ft_atoi utils/ft_calloc utils/ft_current_time utils/ft_error utils/ft_isdigit
DINER	= diner/ft_diner diner/ft_eating diner/ft_fork_down diner/ft_fork_up diner/ft_message diner/ft_sleep_think
INIT	= init/ft_check_arg init/ft_get_arg init/ft_init_philo init/ft_init
FILES	= philo $(UTILS) $(INIT) $(DINER)

SRC			= $(FILES:=.c)
OBJ			= $(FILES:=.o)

HEADER		= includes/philo.h
INCLUDES	= -I includes
PTHREAD		= -pthread

GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
CURSIVE		=	\e[33;3m
RESET		=	\e[0m

all: $(NAME)

$(NAME):  $(OBJ) $(HEADER)
	@printf "$(CURSIVE)$(GRAY) 	- Compiling $(NAME)... $(RESET)\n"
	@ $(CC) $(OBJ) $(INCLUDES) $(PTHREAD) $(OPTS) -o $(NAME)
	@printf "$(GREEN)    - Executable ready.\n$(RESET)"

%.o: %.c $(HEADER)
	@printf "$(CURSIVE)$(GRAY) 	- Making object file $(notdir $@) from source file $(notdir $<) ... $(RESET)\n"
	@ $(CC) -Wall -Wextra -Werror $(PTHREAD) $(OPTS) $(INCLUDES) -c $< -o $@



clean:
	@$(RM) $(OBJ)
	@printf "$(CURSIVE)$(GRAY)	- Removing object files ... $(RESET)\n"
	@printf "$(YELLOW)    - Object files removed.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(CURSIVE)$(GRAY)	- Removing $(NAME)... $(RESET)\n"
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

re: fclean all