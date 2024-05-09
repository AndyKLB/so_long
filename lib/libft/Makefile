##########################################################
## ARGUMENTS

NAME = libft.a 
CC = cc
FLAGS = -Wall -Wextra -Werror -I.
AR = ar
RM = rm -f

##########################################################
## SOURCES

FILES = ft_strdup.c \
		ft_strchr.c \
		ft_strlen.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_split.c \
		get_next_line.c \
		ft_itoa.c \

OBJS = ${FILES:.c=.o}


BOBJS	=	$(BONUS:.c=.o)

##########################################################
## RULES

all: 		$(NAME)

.c.o: 	
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: 	${OBJS}
		ar -rcs ${NAME} ${OBJS} 


clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY:		all clean fclean re
