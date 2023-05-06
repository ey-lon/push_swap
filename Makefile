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

RM = /bin/rm -f

FLAGS = -Wall -Werror -Wextra -g

NAME = push_swap

N_BNS = checker

LIBFT = libft.a

#paths-----------------------------------------

LBT_F = Libft/
SRC_F = source/
BNS_F = source_bonus/

#files-----------------------------------------

SRC =	push_swap.c \
		err_check.c \
		print_stack.c \
		fill_stack.c \
		stack_utils.c \
		other_utils.c \
		call_op1.c \
		call_op2.c \
		swap.c \
		push.c \
		rotate.c \
		deal_2to5.c \
		deal_6plus.c \
		execute_mov.c \
		mov.c \
		lis.c \
		lis_utils.c

BNS = 	checker_bonus.c \
		err_check_bonus.c \
		print_stack_bonus.c \
		fill_stack_bonus.c \
		stack_utils_bonus.c \
		other_utils_bonus.c \
		swap_bonus.c \
		push_bonus.c \
		rotate_bonus.c \

#----------------------------------------------

LIBFT := $(addprefix $(LBT_F),$(LIBFT))
SRC := $(addprefix $(SRC_F),$(SRC))
BNS := $(addprefix $(BNS_F),$(BNS))

OBJ_S = $(SRC:.c=.o)
OBJ_B = $(BNS:.c=.o)

#rules-----------------------------------------

all: $(NAME) bonus

$(NAME): comp

libcomp:
		@make -C Libft

comp: libcomp $(OBJ_S)
	$(CC) $(FLAGS) $(OBJ_S) $(LIBFT) -o $(NAME)
	echo "$(TCOL)$(NAME) $(CMP)"

bonus: libcomp $(OBJ_B)
	$(CC) $(FLAGS) $(OBJ_B) $(LIBFT) -o $(N_BNS)
	echo "$(TCOL)$(N_BNS) $(CMP)"

libclean:
		@make clean -C Libft

clean:		libclean
	$(RM) $(OBJ_S)
	$(RM) $(OBJ_B)

libfclean:
		@make fclean -C Libft

fclean:   	clean
		if [ -f $(NAME) ]; then\
			rm -rf $(NAME);\
			echo "$(TCOL)$(NAME) $(RMD)";\
		fi
		if [ -f $(N_BNS) ]; then\
			rm -rf $(N_BNS);\
			echo "$(TCOL)$(N_BNS) $(RMD)";\
		fi

re: fclean all

.PHONY: $(NAME) all re clean fclean bonus

.SILENT:
