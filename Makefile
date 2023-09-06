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
		insertion2.c \
		utils.c \
		ft_init.c \
		error.c \
		small_list.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@cat .loading_bar 2>/dev/null || printf "" > .loading_bar
	@printf '*' >> .loading_bar

$(NAME): $(OBJ)
	@echo "\033[0;1m"
	@printf '%*s' $(NB_SRCS) '' | tr ' ' '*' #print one star per file in SRCS
	@make -s -C Libft/
	@$(CC) $(CFLAGS) $(OBJ) -L./Libft -lft -o $(NAME)
	@rm -f .loading_bar
	@echo "\033[1;32mPush_Swap: successful compilation\033[0m 🎇"

clean:
	@make -s clean -C Libft/
	@rm -f $(OBJ)
	@echo "\033[1;36m===>Push_Swap: .o correctly cleaned\033[0m"

fclean: clean
	@rm -f $(NAME)
	@rm -f ./Libft/libft.a
	@echo "\033[1;30mLibft: .a correctly cleaned\033[0m"
	@echo "\033[1;36m===>Push_Swap: .a correctly cleaned\033[0m"

re:		fclean all