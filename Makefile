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
		ft_rra.c \
		ft_rrb.c \
		free.c \
		insertion.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[1mcompiling\033[0m: $<                                 \n"
	@printf $$'\033[2m'
	@printf '%*s' $(NB_SRCS) '' | tr ' ' '*' #print one star per file in SRCS
	@printf $$'\033[0;1;33m|\033[0m⌛\r\033[0;1m'
	@cat .loading_bar 2>/dev/null || printf "" > .loading_bar
	@printf '*\r'
	@printf "\033[0m\033[A\r"
	@printf '*' >> .loading_bar

$(NAME): $(OBJ)
	@echo "\033[0;1m"
	@printf '%*s' $(NB_SRCS) '' | tr ' ' '*' #print one star per file in SRCS
	@printf "\033[0m\033[C✅\n"
	@echo "\033[1;32mcompiled\033[0m"
	@echo "\033[34mcompiling library :\033[0m"
	@make -s -C Libft/
	@echo "\033[1;34mlinking files:\033[0m"
	@$(CC) $(CFLAGS) $(OBJ) -L./Libft -lft -o $(NAME)
	@rm -f .loading_bar
	@echo "\033[1;32mcode compiled succesfully\033[0m ✅"

clean:
	@make -s clean -C Libft/
	@echo "\033[1;31mlibft cleaned\033[0m"
	@rm -f $(OBJ)
	@echo "\033[1;31mobject files removed\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;33m${NAME} file removed\033[0m"

re:		fclean all