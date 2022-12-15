# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 14:32:38 by cfontain          #+#    #+#              #
#    Updated: 2022/11/18 17:20:34 by cfontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = violence

SRCS_DIR	= ./
SRCS 		= 	main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
HEADER		=  ./includes/HumanA.hpp ./includes/HumanB.hpp ./includes/Weapon.hpp

FLAGS = -Wall -Wextra -Werror -std=c++98

OBJS_DIR 	= 	objects/
OBJ 		= 	$(SRCS:.cpp=.o)
OBJS 		= 	$(addprefix $(OBJS_DIR), $(OBJ))

$(OBJS_DIR)%.o :	$(SRCS_DIR)%.cpp $(HEADER)
	@mkdir -p $(OBJS_DIR)
	@c++ $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "\033[34m----Compiling----"
	@echo	"          _                                     _ _   		"
	@echo "    _ __ | | ___  __ _ ___  ___  __      ____ _(_) |_ 		"
	@echo "   |  _ \| |/ _ \/ _\` / __|/ _ \ \ \ /\ / / _\` | | __|	"
	@echo "     | |_) | |  __/ (_| \__ \  __/  \ V  V / (_| | | |_  	"
	@echo "   |  __/|_|\___|\__,_|___/\___|   \_/\_/ \__,_|_|\__|		"
	@echo "   |_|				                       					"
	@echo "                           {				"
	@echo "                        {   }				"
	@echo "                         }_{ __{			"
	@echo "                      .-{   }   }-.		"
	@echo "                     (   }     {   )		"
	@echo "                     |\`-.._____..-'|		"
	@echo "                     |             ;--.	"
	@echo "                     |            (__  \	"
	@echo "                     |             | )  )	"
	@echo "                     |             |/  /	"
	@echo "                     |             /  /	"
	@echo "                     |            (  /		"
	@echo "                     \             Y		"
	@echo "                      \`-.._____..-'		"
	@c++ $(FLAGS) -o $(NAME) $(OBJS)
	@echo "                 ____                   	"	
	@echo "                |  _ \  ___  _ __   ___ 	"
	@echo "                | | | |/ _ \|  _ \ / _ \\	"
	@echo "                | |_| | (_) | | | |  __/	"
	@echo "                |____/ \___/|_| |_|\___|	"
	@echo "OK"

all: $(NAME)

clean:
	@echo "\033[31m----Cleaning objects----"
	@rm -rf $(OBJS_DIR)
	@echo "OK"
	
fclean: clean
	@echo "\033[33m----Cleaning all----"
	@rm -f $(NAME)
	@echo "OK"

re: fclean all