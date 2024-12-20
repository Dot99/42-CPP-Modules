# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 11:22:17 by gude-jes          #+#    #+#              #
#    Updated: 2024/12/20 10:51:02 by gude-jes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98
ROOT = $(shell pwd)
INC = -I$(ROOT)/includes
VPATH = src
RM = rm -rf

SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp

all: $(NAME)
NAME = Animal

OBJ_DIR = obj
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.SILENT:
