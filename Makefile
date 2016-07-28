##
## Makefile for fdf in /home/plasko_a/rendu/MUL_2013_fdf
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.net>
## 
## Started on  Thu Nov 21 08:52:14 2013 Antoine Plaskowski
## Last update Sun Dec  8 16:34:29 2013 Antoine Plaskowski
##

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-Wextra -Wall -O3
CFLAGS	+=	-ansi -pedantic
CFLAGS	+=	-I header/

LDFLAGS	+=	-L minilibx -l mlx
LDFLAGS	+=	-L/usr/lib64/X11 -l Xext -l X11

NAME	=	fdf

SRC	+=	src/main.c
SRC	+=	src/my_gere.c
SRC	+=	src/my_move.c
SRC	+=	src/my_reset.c
SRC	+=	src/my_change_z.c
SRC	+=	src/my_change_k.c
SRC	+=	src/my_change_deca.c
SRC	+=	src/my_make_line.c
SRC	+=	src/my_put_pixel_in_img.c
SRC	+=	src/my_struct_color.c
SRC	+=	src/my_struct_coord.c
SRC	+=	src/my_struct_data.c
SRC	+=	src/my_control.c
SRC	+=	src/my_tool_coord.c
SRC	+=	src/my_tool.c
SRC	+=	src/my_char_in_str.c
SRC	+=	src/my_malloc.c
SRC	+=	src/my_putchar.c
SRC	+=	src/my_putstr.c
SRC	+=	src/my_abs.c
SRC	+=	src/my_getnbr.c
SRC	+=	src/my_getnbr_base.c
SRC	+=	src/my_power_rec.c
SRC	+=	src/my_square_root.c
SRC	+=	src/my_putnbr.c
SRC	+=	src/my_strlen.c
SRC	+=	src/get_next_line.c
SRC	+=	src/my_strupcase.c

OBJ	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(MAKE) -C minilibx
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
