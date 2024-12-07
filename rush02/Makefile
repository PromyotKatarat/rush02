# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psuksarn <psuksarn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/07 12:26:41 by psuksarn          #+#    #+#              #
#    Updated: 2024/12/07 13:32:23 by psuksarn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_atoi.c \
       ft_split.c \
       ft_strncy.c \
       read.c \
       rush02_funbasie.c \
       rush02.c \
       usefun.c \
	   ft_strcat.c
OBJS = $(SRCS:.c=.o)
all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all