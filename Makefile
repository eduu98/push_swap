NAME = push_swap

SRC = main.c actions.c list_functions.c args_checks.c sort.c find_moves.c
SORT_SRC = aux_functions.c order_big.c order_medium.c order_small.c
OBJ_DIR = _objFiles/
SORT_DIR = sort_algorithm/
ALL_SRCS = $(SRC) $(addprefix $(SORT_DIR), $(SORT_SRC))

OBJ_SRC = $(SRC:.c=.o)
OBJ_SORT = $(SORT_SRC:.c=.o)
OBJ = $(OBJ_SRC) $(OBJ_SORT)

SORT_PATH = $(OBJ_SRC:%=$(SORT_DIR)%)
SRC_PATH = $(SRC) $(SORT_PATH)

SORT_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(OBJ_SORT))
OBJ_PATH =		$(addprefix $(OBJ_DIR), $(OBJ_SORT)) $(SORT_OBJ_PATH)

FLAGS = -Wall -Wextra -Werror


# --- LIBFT ---
LIBFT_A = libft.a
LIBF_DIR = Libft/
LIBFT  = $(addprefix $(LIBF_DIR), $(LIBFT_A))


# --- COlORS ---
NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'


# --- RULES ---
all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBF_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(LIBFT) $(addprefix $(OBJ_DIR), $(OBJ_SORT)) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJ): $(SRC)
	@echo $(CURSIVE)$(GRAY) "     - Creating object directory..." $(NONE)
	@mkdir -p $(OBJ_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FLAGS) -c $(ALL_SRCS)
	@echo $(CURSIVE)$(GRAY) "     - Moving object files to $(OBJ_DIR)..." $(NONE)	
	@mv $(OBJ) $(OBJ_DIR)

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBF_DIR) clean
	@echo "   - Clean"

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)
	@make -C $(LIBF_DIR) fclean
	@echo "   - All clean"

re: fclean all

norm: $(SRC)
	@echo $(GRAY) ""
	@norminette $(SRC) *.h
	@echo $(NONE)$(GREEN) "\n     NORM OK" $(NONE)


# --- TEST ---
n = 0
exe: all
	@if [ $(n) -le 0 ]; then \
		echo "\033[31m     MAKE ERROR"; \
		echo "Usage: \033[0;3;4m< make exe n=x >\033[0;31m. x is the length of the number list and must be above 0."; \
	else \
		ARG=$$(seq -$(n) $(n) | sort -R | head -n $(n) | tr '\n' ' '); \
		echo $(YELLOW) "     -Using $(n) numbers..." $(NONE); \
		./push_swap $$ARG; \
	fi;
