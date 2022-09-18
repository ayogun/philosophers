# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 15:42:30 by yogun             #+#    #+#              #
#    Updated: 2022/09/18 10:49:00 by yogun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

RM = rm -f

FLAGS = -Wall -Wextra -Werror 

SRC =	./src/philo.c \
		./src/utils.c \
		./src/ft_start.c \
		./src/ft_die.c \
		./src/error.c \
		./src/thread_create.c \


# ------------------------------ Colors ------------------------------

BOLD_PURPLE	=	\033[1;35m

BOLD_CYAN	=	\033[1;36m

BOLD_GREEN	=	\033[1;32m

BOLD_YELLOW	=	\033[1;33m

NO_COLOR	=	\033[0m

# ------------------------------ Colors ------------------------------

# ------------------------------ Message ------------------------------

COMP_START	=	echo "\n $(BOLD_YELLOW)Make: $(NO_COLOR)Starting the compilation...\n"

READY		=	echo "\n $(BOLD_GREEN)Ready$(NO_COLOR) : The program $(BOLD_CYAN) philo $(NO_COLOR) compiled!\n"

CLEANED		=	echo "\n $(BOLD_PURPLE)Clean: $(NO_COLOR)Removed all the \".o\" files \n"

FCLEANED	=	echo "\n $(BOLD_PURPLE)Fclean: $(NO_COLOR)Removed the executables \n"

# ------------------------------ Message ------------------------------

.c.o:
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o}

OBJ = ${SRC:.c=.o}

${NAME}: ${OBJ}
		@$(COMP_START)
		@${CC} ${OBJ} -o ${NAME}
		@$(READY) 

all: ${NAME}

clean:
	@${RM} ${OBJ}
	@$(CLEANED)

fclean: clean
	@${RM} ${NAME}
	@$(FCLEANED)

re: fclean all

.PHONY: all clean fclean re