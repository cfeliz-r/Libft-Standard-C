# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfeliz-r <cfeliz-r@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 11:33:17 by cfeliz-r          #+#    #+#              #
#    Updated: 2024/03/21 01:23:01 by cfeliz-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Library		= libft

#files 	   = ft_strlen \
			 ft_memmove \
			 ft_memcpy \
			 ft_strlcpy \
			 ft_strlcat \
			 ft_isalpha \
			 ft_isdigit \
			 ft_isalnum \
			 ft_isascii \
			 ft_isprint \
			 ft_memset \
			 ft_bzero \
			 ft_toupper \
			 ft_tolower \
			 ft_strchr \
			 ft_strrchr \
			 ft_strncmp \
			 ft_memchr \
			 ft_memcmp \
			 ft_strnstr \
			 ft_atoi \
			 ft_calloc \
			 ft_strdup \
			 ft_substr \
			 ft_strjoin \
			 ft_strtrim \
			 ft_split \
			 ft_itoa \
			 ft_strmapi \
			 ft_striteri \
			 ft_putchar_fd \
			 ft_putstr_fd \
			 ft_putendl_fd \
			 ft_putnbr_fd \

#Compiler	= gcc

#CmpFlags	= -Wall -Wextra -Werror

#OUTN	= $(Library).a

#CFILES	= $(files:%=%.c)

#OFILES	= $(files:%=%.o)

#NAME	= $(OUTN)

#$(NAME):
#	$(Compiler) $(CmpFlags) -c $(CFILES) -I./
#	ar -rc $(OUTN) $(OFILES)

#all: $(NAME)

# Variables

SRCS		= ft_atoi.c \
		  ft_bzero.c \
		  ft_calloc.c \
		  ft_isalnum.c \
		  ft_isalpha.c \
		  ft_isascii.c \
		  ft_isdigit.c \
		  ft_isprint.c \
		  ft_itoa.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_memset.c \
		  ft_putchar_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_putstr_fd.c \
		  ft_split.c \
		  ft_strchr.c \
		  ft_strdup.c \
		  ft_striteri.c \
		  ft_strjoin.c \
		  ft_strlcat.c \
		  ft_strlcpy.c \
		  ft_strlen.c \
		  ft_strmapi.c \
		  ft_strncmp.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strtrim.c \
		  ft_substr.c \
		  ft_tolower.c \
		  ft_toupper.c
SRCS_BONUS	= ft_lstadd_back.c \
		  ft_lstadd_front.c \
		  ft_lstclear.c \
		  ft_lstdelone.c \
		  ft_lstiter.c \
		  ft_lstlast.c \
		  ft_lstmap.c \
		  ft_lstnew.c \
		  ft_lstsize.c
OBJS		= ${SRCS:.c=.o}
OBJS_BONUS	= ${SRCS_BONUS:.c=.o}
NAME		= libft.a
CC		= gcc
CFLAGS		= -Wall -Wextra -Werror

%.o: %.c libft.h
		${CC} ${CFLAGS} -I. -c $< -o $@

all:		${NAME}

$(NAME):	${OBJS} libft.h
		ar rcs ${NAME} ${OBJS}

bonus:		${OBJS_BONUS} libft.h
		ar rcs ${NAME} ${OBJS_BONUS}

clean:
		rm -f ${OBJS} ${OBJS_BONUS}

fclean:		clean
		rm -f ${NAME} libft.so

re:		fclean all

.PHONY:	all clean fclean re bonus
