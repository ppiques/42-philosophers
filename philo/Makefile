# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 10:22:05 by ppiques           #+#    #+#              #
#    Updated: 2022/04/10 19:43:26 by ppiques          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		philo

SRCS_PATH = $(shell find srcs -type d) \
			$(shell find srcs/utils -type d)

OBJ_DIR	= 	$(BUILD)/obj

OBJS = 		$(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

INC_DIR = 	$(shell find includes -type d)

BUILD = 	.objects

vpath %.c $(SRCS_PATH)

SRCS = philosophers.c  philosophing.c check_args.c \
parsing.c timer.c actions.c cleaner.c nurse.c \
ft_isdigit.c ft_atoi.c

cc = gcc

CFLAGS = -Wall -Wextra -Werror -g
LIBS = -lpthread
IFLAGS = $(foreach dir, $(INC_DIR), -I $(dir))

all :
	@make $(NAME)

$(NAME) : $(OBJS)
		@cc $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
		@echo "Executable successfully created\n"

$(OBJ_DIR)/%.o : %.c | $(BUILD)
		@cc $(CFLAGS) -c $< $(IFLAGS) -o $@

$(BUILD):
		@mkdir $@ $(OBJ_DIR)
		@echo "\nObject directory created\n"
		@echo "Compiling...\n"

clean :
		@rm -rf $(BUILD)
		@echo "\nObject directory deleted\n"

fclean : clean
		@rm -rf $(NAME)
		@echo "Executable removed\n"

re : fclean all

.PHONY :	all clean fclean re
