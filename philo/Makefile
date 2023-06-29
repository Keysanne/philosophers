# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 12:33:08 by tbatteux          #+#    #+#              #
#    Updated: 2023/06/29 12:57:21 by tbatteux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers
FICHIERS_C = utils.c start.c routine_solo.c check_value.c
FICHIERS_O = ${FICHIERS_C:.c=.o}
FLAG = -Wall -Wextra -Werror -pthread -g

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
