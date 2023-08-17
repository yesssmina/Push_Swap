NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC =  base.c \
		ft_sa.c \
		ft_sb.c \
		ft_pa.c \
		ft_pb.c \
		ft_ra.c \
		ft_rb.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	make -C Libft/
	$(CC) $(CFLAGS) $(OBJ) -L./Libft -lft -o $(NAME)
clean:
	make clean -C Libft/
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:		fclean all