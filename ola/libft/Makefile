# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fl-hote <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 17:18:07 by fl-hote           #+#    #+#              #
#    Updated: 2022/03/09 21:17:44 by fl-hote          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 			  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			  ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			  ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			  ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			  ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c	 
	
OBJS		= ${SRCS:.c=.o}

OBJS_B		= ${SRCS_B:.c=.o}

NAME		= libft.a

CC 			= gcc

CFLAGS		= -Wall -Wextra -Werror -I.

all: ${NAME}

%.o:%.c
		${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
		ar rcs ${NAME} ${OBJS}

bonus: ${NAME} ${OBJS_B}
		ar rcs ${NAME} ${OBJS_B}

clean:
		rm -f ${OBJS}
		rm -f ${OBJS_B}

fclean: clean
		rm -f ${NAME}

re: fclean all
