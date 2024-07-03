# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/16 18:07:46 by dlim-yua          #+#    #+#              #
#    Updated: 2024/06/16 18:07:47 by dlim-yua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR		=		libft/
LIBFT			=		libft.a

CLIENT			=		client
SERVER			=		server
SRC_CLIENT		=		mandatory/client.c
SRC_SERVER		=		mandatory/server.c
OBJ_CLIENT		=	$(SRC_CLIENT:.c=.o)
OBJ_SERVER		=	$(SRC_SERVER:.c=.o)

CLIENT_BO		=		client_bonus
SERVER_BO		=		server_bonus
SRC_CLIENT_BO	=		bonus/client_bonus.c
SRC_SERVER_BO	=		bonus/server_bonus.c
OBJ_CLIENT_BO	=	$(SRC_CLIENT_BO:.c=.o)
OBJ_SERVER_BO	=	$(SRC_SERVER_BO:.c=.o)

FLAGS			=		-Wall -Wextra -Werror

all: 		$(OBJ_CLIENT) $(CLIENT) $(OBJ_SERVER) $(SERVER)

bonus: 		$(OBJ_CLIENT_BO) $(CLIENT_BO) $(OBJ_SERVER_BO) $(SERVER_BO)

%.o:		%.c
					cc $(FLAGS) -c $< -o $(<:c=o)

$(CLIENT):		$(OBJ_CLIENT)
					make -C $(LIBFT_DIR)
					cp $(LIBFT_DIR)$(LIBFT) $(CLIENT)
					ar -rcs $(CLIENT) $(OBJ_CLIENT)
					cc $(FLAGS) $(CLIENT) -o $(CLIENT)

$(SERVER):		$(OBJ_SERVER)
					make -C $(LIBFT_DIR)
					cp $(LIBFT_DIR)$(LIBFT) $(SERVER)
					ar -rcs $(SERVER) $(OBJ_SERVER)
					cc $(FLAGS) $(SERVER) -o $(SERVER)

$(CLIENT_BO):	$(OBJ_CLIENT_BO)
					make -C $(LIBFT_DIR)
					cp $(LIBFT_DIR)$(LIBFT) $(CLIENT_BO)
					ar -rcs $(CLIENT_BO) $(OBJ_CLIENT_BO)
					cc $(FLAGS) $(CLIENT_BO) -o $(CLIENT_BO)

$(SERVER_BO):	$(OBJ_SERVER_BO)
					make -C $(LIBFT_DIR)
					cp $(LIBFT_DIR)$(LIBFT) $(SERVER_BO)
					ar -rcs $(SERVER_BO) $(OBJ_SERVER_BO)
					cc $(FLAGS) $(SERVER_BO) -o $(SERVER_BO)

clean:
					rm -f $(OBJ_CLIENT)
					rm -f $(OBJ_SERVER)
					rm -f $(OBJ_CLIENT_BO)
					rm -f $(OBJ_SERVER_BO)
					make clean -C $(LIBFT_DIR)

fclean:			clean
					rm -f $(CLIENT)
					rm -f $(SERVER)
					rm -f $(CLIENT_BO)
					rm -f $(SERVER_BO)
					rm -f $(LIBFT_DIR)$(LIBFT)

re:			fclean all
