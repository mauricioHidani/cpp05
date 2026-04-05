# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/01 15:58:03 by mhidani           #+#    #+#              #
#    Updated: 2026/04/05 18:59:53 by mhidani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= intern
SINCE		= 2026.04.05
AUTHOR		= mhidani
LOCAL		= 42SP
VERSION		= 1.0.0v

TIMESTAMP	= $(shell date +%Y%m%d_%H%M%S)

INC_DIR		= includes
SRC_DIR		= src
OBJ_DIR		= obj

FILES		= Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp \
			  RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
MAIN		= main.cpp

SRCS		= $(addprefix $(SRC_DIR)/, $(FILES))

SRC_OBJS	= $(addprefix $(OBJ_DIR)/, $(FILES:.cpp=.o))
MAIN_OBJ	= $(OBJ_DIR)/$(MAIN:.cpp=.o)
OBJS		= $(SRC_OBJS) $(MAIN_OBJ)

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
CXXINCS		= -I$(INC_DIR)/

VALGRIND	= valgrind
VGDLOG		= valgrind_$(TIMESTAMP).log
VGDFLAGS	= --leak-check=full --track-origins=yes --show-leak-kinds=all \
			  --log-file=$(VGDLOG)

MKD			= mkdir
MKDFLAGS	= --parents
RM			= rm
RMFLAGS		= --force --recursive

define check_created
	if [ -f $(1) ]; then \
		echo "🟢 $(1): is created"; \
	else \
		echo "🔴 $(1): doesn't created"; \
	fi
endef

define remove_dir_exists
	if [ -d $(1) ]; then \
		$(RM) $(RMFLAGS) $(1); \
		echo "🟢 $(1): is cleaned"; \
	else \
		echo "🟠 $(1): doesn't exists and not cleaned"; \
	fi
endef

define remove_file_exists
	if [ -f $(1) ]; then \
		$(RM) $(RMFLAGS) $(1); \
		echo "🟢 $(1): is cleaned"; \
	else \
		echo "🟠 $(1): doesn't exists and not cleaned"; \
	fi 
endef

all: banner $(NAME)

clean:
	@$(call remove_dir_exists, $(OBJ_DIR))

clean_logs:
	@$(RM) $(RMFLAGS) valgrind_*.log
	@echo "🟧 valgrind logs is cleaned"

fclean: clean
	@$(call remove_file_exists, $(NAME))

re: fclean all

banner:
	@echo "🛸 $(LOCAL) - [CPP-05 Exercise 03]"
	@echo "At least that's better than making coffee"
	@echo "$(NAME) $(VERSION)"
	@echo "$(AUTHOR) $(SINCE)"
	@echo 

run: banner $(NAME)
	@$(VALGRIND) $(VGDFLAGS) ./$(NAME)
	@$(call check_created, $(VGDLOG))

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) $(CXXINCS) -o $@
	@echo "🔷 $(NAME): The executable is ready"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(MKD) $(MKDFLAGS) $(dir $@)
	@$(CXX) $(CXXFLAGS) $(CXXINCS) -c $< -o $@

$(OBJ_DIR)/main.o: main.cpp
	@$(MKD) $(MKDFLAGS) $(dir $@)
	@$(CXX) $(CXXFLAGS) $(CXXINCS) -c $< -o $@

.PHONY: clean clean_logs fclean all re run banner