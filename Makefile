#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/23 10:11:34 by okryzhan          #+#    #+#              #
#    Updated: 2018/10/23 10:11:36 by okryzhan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
CC = gcc
INC_DIR = ./includes
PRINTF = ./ft_printf/
SRCS = ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_memccpy.c \
ft_memmove.c \
ft_memchr.c \
ft_memcmp.c \
ft_memalloc.c \
ft_memdel.c \
ft_strlen.c \
ft_strdup.c \
ft_strcpy.c \
ft_strncpy.c \
ft_strcat.c \
ft_strncat.c \
ft_strlcat.c \
ft_strchr.c \
ft_strrchr.c \
ft_strstr.c \
ft_strnstr.c \
ft_strcmp.c \
ft_strncmp.c \
ft_strnew.c \
ft_strdel.c \
ft_strclr.c \
ft_striter.c \
ft_striteri.c \
ft_strmap.c \
ft_strmapi.c \
ft_strequ.c \
ft_strnequ.c \
ft_strsub.c \
ft_strjoin.c \
ft_strtrim.c \
ft_strsplit.c \
ft_strrev.c \
ft_atoi.c \
ft_itoa.c \
ft_itoa_base.c \
ft_sqrt.c \
ft_power.c \
ft_abs.c \
ft_swap.c \
ft_nbrlen.c \
ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_toupper.c \
ft_tolower.c \
ft_putchar.c \
ft_putstr.c \
ft_putnstr.c \
ft_putendl.c \
ft_putnbr.c \
ft_putnbr_base.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_print_bits.c \
ft_lstnew.c \
ft_lstdelone.c \
ft_lstdel.c \
ft_lstadd.c \
ft_lstiter.c \
ft_lstmap.c \
ft_isspace.c \
ft_fibonacci.c \
ft_print_params_delim.c \
get_next_line.c \
$(PRINTF)ft_printf.c \
$(PRINTF)parser.c \
$(PRINTF)display_d.c \
$(PRINTF)display_c.c \
$(PRINTF)display_s.c \
$(PRINTF)display_o.c \
$(PRINTF)display_u.c \
$(PRINTF)display_x.c \
$(PRINTF)display_p.c \
$(PRINTF)display_f.c \
$(PRINTF)display_b.c \
$(PRINTF)get_value.c \
$(PRINTF)dtoa.c \
$(PRINTF)utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS) ./ft_printf/libftprintf.a
	ranlib $(NAME)

%.o: %.c $(INC_DIR)/*.h
	$(CC) $(FLAGS) -o $@ -c $< -I $(INC_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re