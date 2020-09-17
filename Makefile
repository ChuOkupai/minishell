# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/27 16:09:01 by asoursou          #+#    #+#              #
#    Updated: 2020/09/17 17:51:44 by asoursou         ###   ########.fr        #
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
		   environment \
		   parser \
		   process \
		   shell \
		   termcaps \
		   utils
DIRS	:= $(addprefix $(BUILD)/, $(SUB_DIR))

# FILES
NAME	:= minishell
SUB_SRC	:= msh_ast_utils.c
SRC		:= $(addprefix ast/, $(SUB_SRC))
SUB_SRC	:= msh_env_new.c \
		   msh_env_utils.c
SRC		+= $(addprefix environment/, $(SUB_SRC))
SUB_SRC	:= msh_is_valid.c \
		   msh_parse_words.c \
		   msh_token_utils.c \
		   msh_tokenize.c
SRC		+= $(addprefix parser/, $(SUB_SRC))
SUB_SRC	:= msh_process_utils.c \
		   msh_pipe.c \
		   msh_redirect.c
SRC		+= $(addprefix process/, $(SUB_SRC))
SUB_SRC	:= msh_shell_run.c \
		   msh_shell_utils.c
SRC		+= $(addprefix shell/, $(SUB_SRC))
SUB_SRC	:= msh_termcaps_utils.c
SRC		+= $(addprefix termcaps/, $(SUB_SRC))
SUB_SRC	:= msh_utils.c
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
