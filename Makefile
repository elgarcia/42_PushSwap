# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 10:49:29 by eliagarc          #+#    #+#              #
#    Updated: 2023/11/16 17:39:27 by eliagarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SOURCE =  Src/push_swap.c Src/push_swap_utils.c Src/ps_inst.c Src/ps_inst2.c \
Src/sorts.c Src/sort_utils.c Src/push_swap_aux.c Src/sort_utils_aux.c Src/sort_utils2.c
INCLUDE = Inc/push_swap.h

CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJS = $(SOURCE:.c=.o)

%.o: %.c Makefile $(INCLUDE)
	@echo "Compiling push_swap..."
	@${CC} -c ${CFLAGS} -I $(INCLUDE) $< -o $@

all: sub_make $(NAME) exec

$(NAME): ${OBJS} $(INCLUDE) Makefile
	@echo "Creating library..."
	@ar rc ${NAME}.a ${OBJS}
	@echo "Library push_swap.a created!"
	
sub_make:
	@echo "Compiling libft..."
	@make -C libft

exec:
	@echo "Creating executable..."
	@$(CC) $(CFLAGS) $(SOURCE) $(NAME).a libft/libft.a -o $(NAME)
	@echo "Push_swap created!"

clean:
	@echo "Cleaning object files..."
	@make clean -C libft
	@rm -f $(OBJS) $(OBJS_BONUS)
	@echo "Object files removed!"

fclean:	clean
	@echo "Cleaning trash..."
	@make fclean -C libft
	@rm -f $(NAME) checker
	@rm -f $(NAME).a
	@echo "Trash removed!"

re: 	fclean all

.PHONY: all clean fclean re sub_make