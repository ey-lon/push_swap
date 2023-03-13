#----------------------------------------------

NOCOL = \e[0m
GREEN = \e[1;92m
RED = \e[1;31m
CYAN = \e[1;36m
TCOL = $(CYAN)
RMD = $(GREEN)successfully $(RED)removed$(NOCOL)
CMP = $(GREEN)successfully compiled$(NOCOL)

#----------------------------------------------

CC = cc

NAME = push_swap

N_BNS = checker

LIBFT = Libft/libft.a

SRC =	source/push_swap.c \
		source/err_check.c \
		source/print_stack.c \
		source/fill_stack.c \
		source/stack_utils.c \
		source/other_utils.c \
		source/call_op1.c \
		source/call_op2.c \
		source/swap.c \
		source/push.c \
		source/rotate.c \
		source/deal_2to5.c \
		source/deal_6plus.c \
		source/execute_mov.c \
		source/mov.c \
		source/lis.c \
		source/lis_utils.c

BNS = 	source_bonus/checker_bonus.c \
		source_bonus/err_check_bonus.c \
		source_bonus/print_stack_bonus.c \
		source_bonus/fill_stack_bonus.c \
		source_bonus/stack_utils_bonus.c \
		source_bonus/other_utils_bonus.c \
		source_bonus/swap_bonus.c \
		source_bonus/push_bonus.c \
		source_bonus/rotate_bonus.c \

FLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): comp

libcomp:
		@make -C Libft

comp: libcomp
	$(CC) $(FLAGS) $(SRC) $(LIBFT) -o $(NAME)
	echo "$(TCOL)$(NAME) $(CMP)"

bonus: libcomp
	$(CC) $(FLAGS) $(BNS) $(LIBFT) -o $(N_BNS)
	echo "$(TCOL)$(N_BNS) $(CMP)"

libclean:
		@make clean -C Libft

clean:		libclean

libfclean:
		@make fclean -C Libft

fclean:   	libfclean
		if [ -f $(NAME) ]; then\
			rm -rf $(NAME);\
			echo "$(TCOL)$(NAME) $(RMD)";\
		fi
		if [ -f $(N_BNS) ]; then\
			rm -rf $(N_BNS);\
			echo "$(TCOL)$(N_BNS) $(RMD)";\
		fi

re: fclean all

.PHONY: all re clean fclean bonus

.SILENT:
