############################################################################
##                                                                        ##
##                                MAKEFILE                                ##
##                                                                        ##
############################################################################

# ****************************** AnaTerMay ****************************** #

# >>>·>>>·>>> VARIABLES <<<·<<<·<<< #
NAME 				= minitalk
NAME_BONUS			= minitalk_bonus
CLIENT_NAME			= client
SERVER_NAME			= server
BONUS_CLIENT_NAME	= client_bonus
BONUS_SERVER_NAME	= server_bonus

# >>>·>>>·>>> COMPILE <<<·<<<·<<< #
CC 				= gcc
CFLAGS 			= -Wall -Werror -Wextra -g

# >>>·>>>·>>> SOURCES <<<·<<<·<<< #
CLIENT_SOURCES = client.c

SERVER_SOURCES = server.c

BONUS_CLIENT_SOURCES = client_bonus.c

BONUS_SERVER_SOURCES = server_bonus.c

LIBFT_SOURCES = libft/ft_atoi.c \
	libft/ft_isdigit.c \

PRINTF_SOURCES = ft_printf/ft_printf.c\
	ft_printf/ft_printchar.c\
	ft_printf/ft_printhexl.c\
	ft_printf/ft_printhexu.c\
	ft_printf/ft_printnbr.c\
	ft_printf/ft_printptr.c\
	ft_printf/ft_printstr.c\
	ft_printf/ft_printunsigned.c\
	ft_printf/ft_print_pid.c \

SOURCES = $(CLIENT_SOURCES) $(SERVER_SOURCES) $(LIBFT_SOURCES) $(PRINTF_SOURCES)

BONUS_SOURCES = $(BONUS_CLIENT_SOURCES) $(BONUS_SERVER_SOURCES) $(LIBFT_SOURCES) $(PRINTF_SOURCES)

# >>>·>>>·>>> OBJECTS <<<·<<<·<<< #
CLIENT_OBJECTS = $(CLIENT_SOURCES:.c=.o)
SERVER_OBJECTS = $(SERVER_SOURCES:.c=.o)
BONUS_CLIENT_OBJECTS = $(BONUS_CLIENT_SOURCES:.c=.o)
BONUS_SERVER_OBJECTS = $(BONUS_SERVER_SOURCES:.c=.o)
LIBFT_OBJECTS = $(LIBFT_SOURCES:.c=.o)
PRINTF_OBJECTS = $(PRINTF_SOURCES:.c=.o)

OBJECTS = $(CLIENT_OBJECTS) $(SERVER_OBJECTS)
BONUS_OBJECTS = $(BONUS_CLIENT_OBJECTS) $(BONUS_SERVER_OBJECTS)

# >>>·>>>·>>> PRE-RULES <<<·<<<·<<< #
$(NAME): $(CLIENT_OBJECTS) $(SERVER_OBJECTS) $(LIBFT_OBJECTS) $(PRINTF_OBJECTS)
	@${CC} ${CFLAGS} -o ${CLIENT_NAME} ${CLIENT_OBJECTS} $(LIBFT_OBJECTS) $(PRINTF_OBJECTS)
	@${CC} ${CFLAGS} -o ${SERVER_NAME} ${SERVER_OBJECTS} $(LIBFT_OBJECTS) $(PRINTF_OBJECTS)
	@chmod +x $(CLIENT_NAME)
	@chmod +x $(SERVER_NAME)

$(NAME_BONUS): $(BONUS_CLIENT_OBJECTS) $(BONUS_SERVER_OBJECTS) $(LIBFT_OBJECTS) $(PRINTF_OBJECTS)
	@${CC} ${CFLAGS} -o ${BONUS_CLIENT_NAME} ${BONUS_CLIENT_OBJECTS} $(LIBFT_OBJECTS) $(PRINTF_OBJECTS)
	@${CC} ${CFLAGS} -o ${BONUS_SERVER_NAME} ${BONUS_SERVER_OBJECTS} $(LIBFT_OBJECTS) $(PRINTF_OBJECTS)
	@chmod +x $(BONUS_CLIENT_NAME)
	@chmod +x $(BONUS_SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJECTS) $(LIBFT_OBJECTS) $(PRINTF_OBJECTS)
	@${CC} ${CFLAGS} -o ${CLIENT_NAME} ${CLIENT_OBJECTS} $(LIBFT_OBJECTS) $(PRINTF_OBJECTS)
	@chmod +x $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJECTS) $(LIBFT_OBJECTS) $(PRINTF_OBJECTS)
	@${CC} ${CFLAGS} -o ${SERVER_NAME} ${SERVER_OBJECTS} $(LIBFT_OBJECTS) $(PRINTF_OBJECTS)
	@chmod +x $(SERVER_NAME)

$(BONUS_CLIENT_NAME): $(BONUS_CLIENT_OBJECTS) $(LIBFT_OBJECTS) $(PRINTF_OBJECTS)
	@${CC} ${CFLAGS} -o ${BONUS_CLIENT_NAME} ${BONUS_CLIENT_OBJECTS} $(LIBFT_OBJECTS) $(PRINTF_OBJECTS)
	@chmod +x $(BONUS_CLIENT_NAME)

$(BONUS_SERVER_NAME): $(BONUS_SERVER_OBJECTS) $(LIBFT_OBJECTS) $(PRINTF_OBJECTS)
	@${CC} ${CFLAGS} -o ${BONUS_SERVER_NAME} ${BONUS_SERVER_OBJECTS} $(LIBFT_OBJECTS) $(PRINTF_OBJECTS)
	@chmod +x $(BONUS_SERVER_NAME)

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

# >>>·>>>·>>> RULES <<<·<<<·<<< #
all: $(NAME)
	@echo "AnaTerMay's Makefile - aternero - 42 Málaga - 2024 - minitalk ..."
	@echo "OK"
bonus: $(NAME_BONUS)
	@echo "AnaTerMay's Makefile - aternero - 42 Málaga - 2024 - minitalk ..."
	@echo "OK"
clean:
	@rm -f $(OBJECTS) $(BONUS_OBJECTS) $(FT_PRINTF_OBJECTS) $(LIBFT_OBJECTS)
	@echo "OK"
fclean: 
	@rm -f $(OBJECTS) $(BONUS_OBJECTS) $(FT_PRINTF_OBJECTS) $(LIBFT_OBJECTS)
	@rm -f $(NAME) $(NAME_BONUS) $(CLIENT_NAME) $(SERVER_NAME) $(BONUS_CLIENT_NAME) $(BONUS_SERVER_NAME)
	@rm -f ft_printf/*.o
	@echo ">>>·>>>·>>>· DONE ·<<<·<<<·<<< "
re: fclean all
	@echo ">>>·>>>·>>>· DONE ·<<<·<<<·<<< "

# >>>·>>>·>>> PHONY <<<·<<<·<<< #
.PHONY: all bonus clean fclean re

# ********* AnaTerMay ********* #