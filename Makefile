SRC =  main.c tools.c parsing.c GNL.c GNL_utils.c take_map.c tools_map.c draw_map.c final_tab.c print_vecteur.c \
bresenham.c movement.c trotate.c draw_img.c move_player.c

CC = gcc

HEADER = cub3D.h

OBJ = $(SRC:%.c=./.build/%.o)

NAME = cub3D

RM = rm -rf

LIBC = ar -rc

CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS	= -g -L ./minilibx-linux -lmlx -lXext -lX11 -lm

# COLORS
NONE			= \033[0m
CL_LINE			= \033[2K
B_RED			= \033[1;31m
B_GREEN			= \033[1;32m
B_MAGENTA 		= \033[1;35m
B_CYAN 			= \033[1;36m

./.build/%.o : %.c
	@$(CC) ${CFLAGS} -o $@ -c $?
	@printf "${B_MAGENTA}Compilling $? ...\n${NONE}"

all :	
	@mkdir -p .build
	cd minilibx-linux && make --no-print-directory
	@make ${NAME} --no-print-directory


${NAME} : $(OBJ)
	@cd Libft && make --no-print-directory
	${CC} -o ${NAME} ${OBJ} ${MLX_FLAGS} ./Libft/libft.a
	@printf "${B_GREEN}==>{${NAME}} LINKED SUCCESFULLY<==${NONE}\n"

clean :
	@cd Libft && make clean --no-print-directory
	@${RM} .build
	@printf "${B_RED}XX{${NAME}} CLEANED SUCCESFULLY XX${NONE}\n"

fclean :	clean
	@${RM} ${NAME}
	@cd Libft && make clean --no-print-directory
	@printf "${B_RED}XX{${NAME}} FCLEAN SUCCESFULL XX${NONE}\n"
	@make clean -C minilibx-linux --no-print-directory


re :	fclean all
