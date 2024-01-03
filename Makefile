# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 10:49:29 by eliagarc          #+#    #+#              #
#    Updated: 2024/01/03 21:54:23 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

SILENCE = --no-print-directory

SOURCE =  Src/push_swap.c Src/push_swap_utils.c Src/ps_inst.c Src/ps_inst2.c \
Src/sorts.c Src/sort_utils.c Src/push_swap_aux.c Src/sort_utils_aux.c Src/sort_utils2.c
INCLUDE = Inc/push_swap.h

CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJS = $(SOURCE:.c=.o)

%.o: %.c Makefile $(INCLUDE)
	@echo "Compiling $<..."
	@${CC} -c ${CFLAGS} $< -o $@

all: sub_make $(NAME)

$(NAME): ${OBJS} $(INCLUDE) Makefile
	@echo "Creating $(NAME)..."
	@$(CC) $(CFLAGS) $(SOURCE) libft/libft.a -o $(NAME)
	@echo "$(COLOUR_GREEN)$(NAME) created!$(COLOUR_END)"
	
sub_make:
	@echo "Compiling libft..."
	@make -C libft $(SILENCE)

clean:
	@echo "$(COLOUR_RED)Cleaning object files...$(COLOUR_END)"
	@make clean -C libft $(SILENCE)
	@rm -f $(OBJS) $(OBJS_BONUS)
	@echo "$(COLOUR_GREEN)Object files removed!$(COLOUR_END)"

fclean:	clean
	@echo "$(COLOUR_RED)Cleaning trash...$(COLOUR_END)"
	@make fclean -C libft $(SILENCE)
	@rm -f $(NAME)
	@echo "$(COLOUR_GREEN)Trash removed!$(COLOUR_END)"

re: 	fclean all

.PHONY: all clean fclean re sub_make