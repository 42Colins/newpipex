# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 15:04:51 by cprojean          #+#    #+#              #
#    Updated: 2023/06/05 13:23:07 by cprojean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAME_BONUS = pipex_bonus

CFLAGS = -Wall -Wextra -Werror -g3 

RM = $(RM) -f

HEADERS = $(DIR_INCLUDES)pipex.h

LIB = libft/libft.a

MKDIR = mkdir -p

RM = rm -rf

DIR_OBJ = ./.obj/

DIR_MANDATORY = ./mandatory/

DIR_BONUS = ./bonus/

DIR_INCLUDES = ./inc/

SRCS =			$(DIR_MANDATORY)main.c \
				$(DIR_MANDATORY)execution.c \
				$(DIR_MANDATORY)parsing.c \
				$(DIR_MANDATORY)wait.c \
				$(DIR_MANDATORY)errors.c \
				$(DIR_MANDATORY)error.c


OBJS = $(SRCS:$(DIR_MANDATORY)%.c=$(DIR_OBJ)%.o)

all :			makelib $(NAME)

$(DIR_OBJ):
				mkdir $@

$(DIR_OBJ)%.o: $(DIR_MANDATORY)%.c $(LIB) $(HEADERS) | $(DIR_OBJ)
				$(CC) $(CFLAGS) -c $< -o $@
				
SRCS_BONUS =		$(DIR_BONUS)main_bonus.c \
					$(DIR_BONUS)wait_bonus.c \
					$(DIR_BONUS)execution_bonus.c \
					$(DIR_BONUS)parsing_bonus.c \
					$(DIR_BONUS)errors_bonus.c \
					$(DIR_BONUS)error_bonus.c


OBJS_BONUS = $(SRCS_BONUS:$(DIR_BONUS)%.c=$(DIR_OBJ)%.o)
				
$(DIR_OBJ)%.o: $(DIR_BONUS)%.c $(LIB) $(HEADERS) | $(DIR_OBJ)
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME) :		$(LIB) $(OBJS)
				$(CC) $(OBJS) -o $(NAME) -L./libft -lft

$(NAME_BONUS) : $(LIB) $(OBJS_BONUS)
				$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS) -L./libft -lft

bonus :			makelib $(NAME_BONUS)

makelib:
				$(MAKE) -C libft

clean :
				$(MAKE) clean -C libft
				$(RM) $(OBJS) $(OBJS_BONUS)

fclean :		clean
				$(MAKE) fclean -C libft
				@$(RM) $(DIR_OBJ)
				$(RM) $(NAME) $(NAME_BONUS)

re :			fclean all

rebonus :		fclean bonus

# .SILENT : $(OBJS) $(NAME)