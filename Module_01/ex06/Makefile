# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 09:20:20 by gude-jes          #+#    #+#              #
#    Updated: 2024/12/12 09:20:28 by gude-jes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp Harl.cpp

NAME = harlFilter

CC = c++ -Wall -Werror -Wextra  -g -std=c++98
all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all