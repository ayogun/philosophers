# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 15:42:30 by yogun             #+#    #+#              #
#    Updated: 2022/09/16 15:43:52 by yogun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

SRC =	philo.c \
		utils.c \
		ft_start.c \
		ft_die.c \
		error.c \
		thread_create.c \

OBJ = ${SRC:.c=.o}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
		${CC} ${OBJ} -o ${NAME} 

all: ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re