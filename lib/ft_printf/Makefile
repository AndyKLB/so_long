#######################################################
## ARGUMENTS
NAME = ft_printf.a
CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -rf
#######################################################
## SOURCES

SRCS =	ft_printf.c ft_printstr.c ft_print_unsigned.c \
		ft_printhex.c ft_printnbr.c ft_printptr.c \
		ft_printchar.c \

OBJS =	$(SRCS:.c=.o)

#######################################################
## RULES

.c.o:	
		$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	clean all

.PHONY:	all clean fclean re
