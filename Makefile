# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/27 16:09:01 by asoursou          #+#    #+#              #
#    Updated: 2020/12/08 01:24:51 by asoursou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION
FT		:= libft
CC		:= clang
CFLAGS	:= -Wall -Wextra -Werror -Wpedantic -Wvla -Ofast -fno-builtin
DFLAGS	= -MP -MMD -MF $(BUILD)/$*.d -MT $@
IFLAGS	:= -isystem./$(FT)/inc -I./inc -I./inc/private
LDFLAGS	:= -L./$(FT) -lft

# DIRECTORIES
BUILD	:= .build
SUB_DIR	:= $(wildcard src/*/.)
SUB_DIR	:= $(SUB_DIR:src/%/.=$(BUILD)/%/)

# FILES
NAME	:= minishell
SRC		:= $(wildcard src/*/*.c) $(wildcard src/*.c)
SRC		:= $(SRC:src/%=%)
DEP		:= $(SRC:%.c=$(BUILD)/%.d)
OBJ		:= $(SRC:%.c=$(BUILD)/%.o)

$(NAME): $(OBJ)
	make -j -C $(FT)
	$(CC) $(CFLAGS) $(IFLAGS) $^ -o $@ $(LDFLAGS)

all: $(NAME)

bonus: all

clean:
	make -C $(FT) $@
	rm -rf $(BUILD)

fclean: clean
	make -C $(FT) $@
	rm -rf $(NAME)

re: fclean all

$(BUILD):
	mkdir $@

$(SUB_DIR): | $(BUILD)
	mkdir $@

$(BUILD)/%.o: src/%.c | $(SUB_DIR)
	$(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS) -c $< -o $@

-include $(DEP)

.PHONY: all bonus clean fclean re
