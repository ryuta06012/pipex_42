NAME = pipex

NAME_BONUS = pipex_bonus

SRCS = ./srcs/free_utils.c ./srcs/pipex_utils1.c ./srcs/pipex_utils2.c ./srcs/pipex.c

SRCS_BONUS = ./srcs_bonus/first_process_bonus.c ./srcs_bonus/free_utils_bonus.c ./srcs_bonus/here_doc_process_bonus.c ./srcs_bonus/init_utils_bonus.c ./srcs_bonus/pipex_utils1_bonus.c ./srcs_bonus/pipex_utils2_bonus.c ./srcs_bonus/pipex_bonus.c ./srcs_gnl/get_next_line.c ./srcs_gnl/get_next_line_utils.c

HEADER = ./includes

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = gcc -g -fsanitize=address

CFLAGS = -Wall -Wextra -Werror -I $(LIBFT_DIR) -I $(HEADER)

RM = rm -f

all:
	$(MAKE) -C $(LIBFT_DIR)
	@make $(NAME)

bonus:
	$(MAKE) -C $(LIBFT_DIR)
	@make $(NAME_BONUS)

$(NAME): $(HEADER) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT_DIR) -lft

$(NAME_BONUS): $(HEADER) $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) -L $(LIBFT_DIR) -lft

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean:		clean
	$(RM) $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean

re:	fclean all

.PHONY: all clean fclean re

