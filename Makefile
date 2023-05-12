# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 13:11:40 by angnguye          #+#    #+#              #
#    Updated: 2023/05/13 00:55:01 by angnguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------- Nickname --------------
NAME			= pipex
RM				= rm -f
CC				= gcc
# ---------------- Color --------------
GREEN			=		\033[1;32m
DARKGRAY		=		\033[1;30m
LIGHTGRAY		=		\033[1;37m
PURPLE			=		\033[0;35m
LIGHTPURPLE		=		\033[1;35m
LIGHTCYAN		=		\033[1;36m
LILAC			= 		\033[0;94m    
ENDCOLOR		=		\033[0m

# ---------------- FLAGS --------------
CFLAGS			= -Wall -Wextra -Werror -g  -w #-fsanitize=address

# ---------------- Sources -----------
SRC				=	./src/main.c \
					./src/ft_printf/ft_printf.c \
					./src/ft_printf/s_c_p_d_i.c \
				 	./src/ft_printf/u_x_X.c \
					./src/pipex_utils.c \
					./src/get_command.c \
					./src/pipex_utils_bis.c 
				 
LIB				= ./includes/pipex.h
				

# ---------------- Objets -----------
OBJS			= ${SRC:.c=.o}

# --------------- Regles --------------------

all:			${NAME}	

${NAME}:		${OBJS}
				@${CC} ${CFLAGS} -o ${NAME} ${OBJS}

rleak:
				@leaks --atExit -- ./${NAME}
.c.o:
				@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

# --------------- VISUEL --------------------
BS_TXT			= echo "\n\n\n\n"
start_msg:
				@$(BS_TXT)
				@tput setaf 92; cat ascii_art/cat_make; tput setaf 7
				@$(BS_TXT)





# --------------- Service nettoyage --------------------
clean:
				@$(BS_TXT)
				@tput setaf 128; cat ascii_art/cat_clean; tput setaf 13
				@$(BS_TXT)
				@${RM} ${OBJS}


fclean:			clean
				@tput setaf 189; cat ascii_art/cat_fclean; tput setaf 9
				@$(BS_TXT)	
				@${RM} ${NAME}
				@echo "$(GREEN)Cleaning succes🌸$(ENDCOLOR)"

re:				fclean all 
				@tput setaf 183; cat ascii_art/cat; tput setaf 7
				@$(BS_TXT)

rel:			fclean leaks

norm :
				@norminette ${SRC}
				@norminette ${LIB}
				@echo "$(PURPLE)Nooooorminetto$(ENDCOLOR)"
				@$(BS_TXT)

.PHONY : all clean fclean re norm leaks rel