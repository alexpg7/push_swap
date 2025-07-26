NAME = push_swap
NAMEBONUS = checker
FLAG = -Wall -Wextra -Werror
OPTION = -c -I
LIBFT_PATH = lib/Libft

# Library files
LIBFT = $(LIBFT_PATH)/libft.a

INCLUDE = $(LIBFT_PATH)/libft.h \
	$(LIBFT_PATH)/libft.a \
	lib/list.h \
	push_swap.h \
	Makefile \
	push_swap.c

INCLUDEBONUS = bonus/checker.c \
	bonus/checker.h \
	functions/ft_errors.c \
	Makefile \
	$(LIBFT_PATH)/libft.h \
	$(LIBFT_PATH)/libft.a \
	lib/list.h \
	bonus/checkerlib/instructionsbonus.c

LIB =  $(LIBFT_PATH)/libft.a

SRC = lib/list1.c \
	lib/list2.c \
	push_swap.c \
	functions/ft_instructions.c \
	functions/sort1.c \
	functions/ft_errors.c \
	functions/ft_misc.c \
	functions/sort2.c \
	functions/ranker.c \
	functions/sortcat.c \
	functions/sortcat2.c \
	functions/sortcathegory.c \
	functions/sortcathegory2.c \
	functions/sort3.c

SRCBONUS = lib/list1.c \
	lib/list2.c \
	bonus/checker.c \
	functions/ft_errors.c \
	functions/ft_misc.c \
	bonus/checkerlib/instructionsbonus.c \
	bonus/checkerlib/ft_operate.c

OBJ = $(SRC:.c=.o)
OBJBONUS = $(SRCBONUS:.c=.o)

# $< significa copiar el primero de los requisitos en el comando (ej. en %.o)
# $? copia TODOS los requisitos
# $@ copia el nombre de la regla

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	cc $(FLAG) $(OBJ) $(LIB) -o $(NAME)
	
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

%.o: %.c
	cc $(FLAG) -c $< -o $@
	

clean:
	/bin/rm -f $(OBJ) $(OBJBONUS) $(DEP)
	$(MAKE) -C $(LIBFT_PATH) clean

# Full clean
fclean: clean
	/bin/rm -f $(NAME) $(NAMEBONUS)
	$(MAKE) -C $(LIBFT_PATH) fclean

bonus: $(INCLUDEBONUS) $(OBJBONUS) $(LIB)
	cc $(FLAG) $(OBJBONUS) $(LIB) -o $(NAMEBONUS)
	
re: fclean all
#bonus: $(OBJ) $(BONUSOBJ) $(INCLUDE)
#	ar rcs $(NAME) $(BONUSOBJ) $(OBJ)
	
#rebonus: fclean bonus
