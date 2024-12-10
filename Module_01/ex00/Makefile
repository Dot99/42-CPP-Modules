# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/10 09:04:01 by gude-jes          #+#    #+#              #
#    Updated: 2024/12/10 09:27:55 by gude-jes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = Zombie.cpp main.cpp newZombie.cpp randomChump.cpp

NAME = Zombie

CC = c++ -Wall -Werror -Wextra  -g -std=c++98
all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all