# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/27 16:09:01 by asoursou          #+#    #+#              #
#    Updated: 2020/11/24 16:38:57 by asoursou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -Wpedantic -Wvla -Ofast -fno-builtin
DFLAGS	= -MP -MMD -MF $(BUILD)/$*.d -MT $@
IFLAGS	= -isystem./$(FT)/inc -I./inc
LDFLAGS	= -L./$(FT) -lft -ltermcap

# DIRECTORIES
FT		:= libft
BUILD	:= .build
SUB_DIR	+= ast \
		   builtin \
		   environment \
		   history \
		   parser \
		   process \
		   readline \
		   shell \
		   utils
DIRS	:= $(addprefix $(BUILD)/, $(SUB_DIR))

# FILES
NAME	:= minishell
SUB_SRC	:= ast_build_seq.c \
		   ast_build.c \
		   ast_exec.c \
		   ast_utils.c \
		   astnode_alloc.c \
		   astnode_utils.c
SRC		:= $(addprefix ast/, $(SUB_SRC))
SUB_SRC := builtin_cd.c \
		   builtin_echo.c \
		   builtin_env.c \
		   builtin_exit.c \
		   builtin_export.c \
		   builtin_pwd.c \
		   builtin_unset.c \
		   builtin_utils.c
SRC		+= $(addprefix builtin/, $(SUB_SRC))
SUB_SRC	:= env_clear.c \
		   env_expand.c \
		   env_init.c \
		   env_setstatus.c \
		   env_utils.c
SRC		+= $(addprefix environment/, $(SUB_SRC))
SUB_SRC	:= history_add.c \
		   history_clear.c \
		   history_edit.c \
		   history_init.c \
		   history_resize.c
SRC		+= $(addprefix history/, $(SUB_SRC))
SUB_SRC	:= is_valid.c \
		   parse_words.c \
		   token_utils.c \
		   tokenize.c
SRC		+= $(addprefix parser/, $(SUB_SRC))
SUB_SRC	:= process_alloc.c \
		   process_exec.c \
		   process_run.c \
		   process_utils.c \
		   redirect.c
SRC		+= $(addprefix process/, $(SUB_SRC))
SUB_SRC	:= readline_clear.c \
		   readline_init.c \
		   readline.c
SRC		+= $(addprefix readline/, $(SUB_SRC))
SUB_SRC	:= shell_clear.c \
		   shell_hook.c \
		   shell_init.c \
		   shell_read_command.c \
		   shell_run.c
SRC		+= $(addprefix shell/, $(SUB_SRC))
SUB_SRC	:= utils.c
SRC		+= $(addprefix utils/, $(SUB_SRC))
SRC		+= main.c
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
	rm -rf $(BIN_DIR) $(NAME)

re: fclean all

$(BUILD):
	mkdir $@ $(DIRS)

$(BUILD)/%.o: src/%.c | $(BUILD)
	$(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS) -c $< -o $@

-include $(DEP)

.PHONY: all bonus clean fclean re
