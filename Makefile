# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hameur <hameur@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/17 17:54:54 by hameur            #+#    #+#              #
#    Updated: 2022/07/28 14:01:11 by hameur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#____________Makefile__________

NAME := philosophers

HEADER := philo.h

CC := gcc

CFLAGS := -Wall -Werror -Wextra

SRC :=	cerculaire_linked_list.c\
		philo_utils.c\
		read_args.c\
		threads.c\
		philo.c

OBJS := $(SRC:.c=.o)

all : $(NAME)
	@echo "Making Philospphers"

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJS)
	@echo "Removing objects files"

fclean : clean
	@rm -rf $(NAME)
	@echo "Removing Philosophers"

re : fclean all