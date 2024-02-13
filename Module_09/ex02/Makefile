# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 17:19:17 by nmota-bu          #+#    #+#              #
#    Updated: 2024/02/13 22:55:31 by nmota-bu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

get_terminal_width = $(shell tput cols)

MAKEFLAGS += --silent	# Silence makefile [Commented by default]\n

# ═══ NAMES ═══════════════════════════════════════════════════════════════════#

NAME	=	PmergeMe

# ═══ COMPILATE ═══════════════════════════════════════════════════════════════#

CFLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic-errors -g3
# FSANIT	= -fsanitize=address
CC		= c++
INC		= -I inc
RM		= rm -rf

# ═══ DIRECTORIES ═════════════════════════════════════════════════════════════#

SRC		= $(wildcard src/*.cpp)
OBJS_D	= objs
OBJ		= $(SRC:src/%.cpp=$(OBJS_D)/%.o)

UNAME	:= $(shell uname)

$(OBJS_D)/%.o:src/%.cpp
			@mkdir -p $(OBJS_D)
			$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(NAME):	$(OBJ)
			@printf "$(CYAN)Compiling $(MAGENTA)$(NAME)$(RESET)\n"
			$(CC) $(CFLAGS) $(FSANIT) $(OBJ) -o $(NAME)
			@printf "$(DONE)DONE$(RESET)\n"

all:		$(NAME)

test:		re
			@clear
			@printf "$(CYAN)Testing $(MAGENTA)$(NAME)$(RESET)\n"
			@printf "$(CYAN)%*s\n$(RESET)" $(call get_terminal_width) | tr ' ' '▀'
			@./$(NAME) "7 73 4 23"
			@./$(NAME) "8 9 9 4 1"
			@./$(NAME) "$$(ruby -e 'puts (1..100).to_a.shuffle.join(" ")')"
			@./$(NAME) "8 9 9.34 12.2 1"
			@./$(NAME) "3 4 2147483648"
			@./$(NAME) "–2147483648 23 2"
			@./$(NAME) "(1 + 1)"
			@./$(NAME) "string err"
			@printf "$(CYAN)%*s\n$(RESET)" $(call get_terminal_width) | tr ' ' '▄'
			@printf "$(CYAN)Finished Test...$(RESET)\n\n"
			@$(MAKE) show
			@$(MAKE) fclean

leaks:		re
			@clear
			@printf "$(CYAN)Testing with Leaks...? $(MAGENTA)$(NAME)$(RESET)\n"
			@printf "$(YELLOW)%*s\n$(RESET)" $(call get_terminal_width) | tr ' ' '▀'
			@leaks -atExit -- ./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
			@leaks -atExit -- ./$(NAME) "7 7 * 7 -"
			@leaks -atExit -- ./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
			@leaks -atExit -- ./$(NAME) "(1 + 1)"
			@printf "$(YELLOW)%*s\n$(RESET)" $(call get_terminal_width) | tr ' ' '▄'
			@printf "$(CYAN)Finished Test with Leaks...?$(RESET)\n\n"
			@$(MAKE) fclean

all:		$(NAME)

clean:
			$(RM) $(OBJS_D)
			@printf "$(DEL)Cleaning objs$(RESET)\n"

fclean: 	clean
			$(RM) $(NAME)
			@printf "$(DEL)Deleted Everything$(RESET)\n"

re: fclean all

show:
	@printf "$(GREEN)"
	@printf "UNAME	: $(MAGENTA)$(UNAME)$(GREEN)\n"
	@printf "NAME  	: $(MAGENTA)$(NAME)$(GREEN)\n"
	@printf "CC	: $(MAGENTA)$(CC)$(GREEN)\n"
	@printf "CFLAGS	: $(MAGENTA)$(CFLAGS)$(GREEN)\n"
	@printf "INCLUDES: $(MAGENTA)$(INC)$(GREEN)\n"
	@printf "SRC	: $(MAGENTA)$(SRC)$(GREEN)\n"
	@printf "OBJ	: $(MAGENTA)[$(OBJS_D)] ➟ $(OBJ)$(RESET)\n\n"

.PHONY: all test re show leaks

# ═══ COLORS ══════════════════════════════════════════════════════════════════#

RED			=\033[0;31m
GREEN		=\033[0;32m
YELLOW		=\033[0;33m
BLUE 		=\033[0;34m
MAGENTA		=\033[0;35m
ORANGE		=\033[38;5;214m
WHITE		=\033[0;37m
CYAN		=\033[1;36m
RESET		=\x1B[0m

DONE		=\x1B[42m\x1B[1;30m
DEL			=\x1B[41m\x1B[1m\x1B[37m