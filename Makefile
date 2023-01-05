# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmounib <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 12:50:33 by mmounib           #+#    #+#              #
#    Updated: 2022/12/22 12:50:36 by mmounib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =    Containers

CC            =    c++

SRCS        =    main.cpp


CFLAGS        =    -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME):$(SRCS)
	@${CC} ${FLAGS} $(SRCS) -o ${NAME}

clean:
	rm -fr

fclean: clean
	rm -fr $(NAME)

re: fclean all

.PHONY: clean fclean re
