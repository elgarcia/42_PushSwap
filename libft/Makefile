# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/08 19:16:50 by eliagarc          #+#    #+#              #
#    Updated: 2024/01/03 21:53:45 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

INCLUDES = libft.h
SRCS = ft_isalpha.c ft_memcmp.c  ft_strdup.c  ft_strncmp.c ft_tolower.c \
ft_atoi.c    ft_isascii.c ft_memcpy.c  ft_strjoin.c ft_strnstr.c ft_toupper.c \
ft_bzero.c   ft_isdigit.c ft_memmove.c ft_strlcat.c ft_strrchr.c  \
ft_calloc.c  ft_isprint.c ft_memset.c  ft_strlcpy.c ft_strtrim.c \
ft_isalnum.c ft_memchr.c  ft_strchr.c  ft_strlen.c  ft_substr.c \
ft_split.c	 ft_itoa.c	  ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_checks.c ft_printf.c \
ft_puthexa.c ft_putnumbers.c ft_putpointer.c ft_putstrchr.c get_next_line.c \
get_next_line_utils.c

SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = ${SRCS:.c=.o}

OBJS_ALL = $(OBJS) $(OBJS_BONUS)

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC = cc
CFLAGS = -Wall -Werror -Wextra

%.o: %.c Makefile $(INCLUDE) 
	@echo "Compiling $<..."
	@${CC} -c ${CFLAGS} $< -o $@

$(NAME): ${OBJS} $(INCLUDES) Makefile
	@echo "$(COLOUR_GREEN)$(NAME) created!$(COLOUR_END)"
	@ar rc ${NAME} ${OBJS}

all:    ${NAME}

bonus: $(OBJS_ALL)
	ar rcs ${NAME} $(OBJS_BONUS)

clean:
	@echo "$(COLOUR_RED)Removing Object files...$(COLOUR_END)"
	@rm -f $(OBJS_ALL)
	@echo "$(COLOUR_GREEN)Done!$(COLOUR_END)"
 
fclean: clean
	@echo "$(COLOUR_RED)Removing all the trash$(COLOUR_END)"
	@rm -f $(NAME)
	@echo "$(COLOUR_GREEN)Clean!$(COLOUR_END)"

re:	fclean all