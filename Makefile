# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edessain <edessain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/20 13:33:12 by edessain          #+#    #+#              #
#    Updated: 2020/06/17 08:52:21 by evrard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= cub3D
LIBFT_PATH 		= ./libft
MINILIBX_PATH   = ./minilibx
#SRCS_LIST 		= main.c
#SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})
SRCS 			= ./srcs/main.c \
					./srcs/ft_init_struct.c \
				 	./srcs/ft_parsing.c \
				 	./srcs/ft_parsing_info.c \
				 	./srcs/ft_parsing_map.c \
					./srcs/ft_parsing_dir.c \
				 	./srcs/ft_raycast.c \
				 	./srcs/ft_raycast_2.c \
					./srcs/textures.c \
					./srcs/check_error.c \
					./srcs/check_error_2.c \
					./srcs/check_error_3.c \
					./srcs/check_parsing_error.c \
					./srcs/ft_exit.c \
					


OBJS			= ${SRCS:.c=.o}
INCLUDE 		= cube3d.h
#FOLDER			= srcs
LIBFT 			= libft
MINILIBX 		= minilibx
CC				= gcc -g -Wall -Wextra -Werror # -fsanitize=address
RM				= rm -f
MLXFLAGS 		= -I ./minilibx -L ./minilibx -lmlx -framework OpenGl -framework Appkit
LIBFLAGS 		= -I ./libft -L ./libft -L . ./libft/*.c
# -I Add the directory dir to the list of directories to be searched for header files
# -L Searches the library when linking

all:			libft_all minilibx_all ${NAME}
$(NAME):		${OBJS}
				@$(CC) $(MLXFLAGS) $(LIBFLAGS) libft.a libmlx.a -I./ $(OBJS) -o $@
clean:			libft_clean minilibx_clean
				@${RM} ${OBJS}
fclean:			libft_fclean clean
				@${RM} ${NAME}
re:				fclean all

# In this last section we make other makefiles compile with the -C flag
# The -C flag makes you go to the appropriate path and do the asked command
libft_all:
	make -C $(LIBFT_PATH) all
	cp ./libft/libft.a libft.a

libft_clean:
	make -C $(LIBFT_PATH) clean

libft_fclean:
	make -C $(LIBFT_PATH) fclean
	$(RM) libft.a

minilibx_all:
	make -C $(MINILIBX_PATH) all
	cp ./minilibX/libmlx.a libmlx.a

minilibx_clean:
	make -C $(MINILIBX_PATH) clean
	$(RM) libmlx.a

.PHONY: all fclean clean re
