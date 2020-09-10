# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/27 16:09:01 by asoursou          #+#    #+#              #
#    Updated: 2020/09/10 18:33:49 by asoursou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -Wpedantic -Wvla -Ofast -fno-builtin
DFLAGS	= -MP -MMD -MF $(DEP_DIR)/$*.d -MT $@
IFLAGS	= -isystem./$(FT)/inc -I./inc
LDFLAGS	= -L./$(FT) -lft

# DIRECTORIES
FT		:= libft
BUILD	:= .build
DEP_DIR	:= $(BUILD)/dep
OBJ_DIR	:= $(BUILD)/obj
SUB_DIR	+= ast \
		   command \
		   environment \
		   lexer \
		   shell \
		   utils
DIRS	:= $(DEP_DIR) $(addprefix $(DEP_DIR)/, $(SUB_DIR)) \
		   $(OBJ_DIR) $(addprefix $(OBJ_DIR)/, $(SUB_DIR))

# FILES
NAME	:= minishell
SUB_SRC	:= msh_ast.c \
		   msh_ast_new.c
SRC		:= $(addprefix ast/, $(SUB_SRC))
SUB_SRC	:= msh_command_clear.c \
		   msh_command_new.c
SRC		+= $(addprefix command/, $(SUB_SRC))
SUB_SRC	:= msh_env_copy.c \
		   msh_env_get.c \
		   msh_env_search.c \
		   msh_env_set.c \
		   msh_env_unset.c
SRC		+= $(addprefix environment/, $(SUB_SRC))
SUB_SRC	:= msh_token.c \
		   msh_token_clear.c \
		   msh_token_find.c \
		   msh_token_new.c \
		   msh_token_print.c \
		   msh_tokenize.c
SRC		+= $(addprefix lexer/, $(SUB_SRC))
SUB_SRC	:= msh_shell_clear.c \
		   msh_shell_init.c \
		   msh_shell_run.c
SRC		+= $(addprefix shell/, $(SUB_SRC))
SUB_SRC	:= msh_abort.c \
		   msh_perror.c \
		   msh_perror_format.c \
		   msh_perror_unexpected.c
SRC		+= $(addprefix utils/, $(SUB_SRC))
SRC		+= main.c
DEP		:= $(SRC:%.c=$(DEP_DIR)/%.d)
OBJ		:= $(SRC:%.c=$(OBJ_DIR)/%.o)

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
	rm -rf $(BIN_DIR) $(NAME)

re: fclean all

$(BUILD):
	echo $(SRC)
	mkdir $@ $(DIRS)

$(OBJ_DIR)/%.o: src/%.c | $(BUILD)
	$(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS) -c $< -o $@

-include $(DEP)

.PHONY: all bonus clean fclean re
