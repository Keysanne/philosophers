# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 12:33:08 by tbatteux          #+#    #+#              #
#    Updated: 2023/06/24 14:23:31 by tbatteux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers
FICHIERS_C = utils.c start.c 
FICHIERS_O = ${FICHIERS_C:.c=.o}
FLAG = -Wall -Wextra -Werror -pthread -fsanitize=thread -g

all: ${NAME}

${NAME}: ${FICHIERS_O}
	gcc -o ${NAME} main.c *.o ${FLAG}

${FICHIERS_O}: ${FICHIERS_C}
	gcc -c ${FICHIERS_C} ${FLAG}
clean:
	rm -f ${FICHIERS_O}

fclean: clean
	rm -f ${NAME}

re: fclean all 
