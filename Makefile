############################################################################
##                                                                        ##
##                                MAKEFILE                                ##
##                                                                        ##
############################################################################

# ********* VARIABLES ********* #
NAME 					= minitalk
NAME_BONUS				= minitalk_bonus

# ********* COMPILATION ********* #
CC 						= gcc
CFLAGS 					= -Wall -Werror -Wextra -g

# ********* SOURCES ********* #
CLIENT_SRCS				= client.c
BONUS_CLIENT_SRCS		= client_bonus.c
SERVER_SRCS				= server.c
BONUS_SERVER_SRCS		= server_bonus.c

# ********* OBJECTS ********* #
CLIENT_OBJS				= $(CLIENT_SRCS:.c=.o)
BONUS_CLIENT_OBJS		= $(BONUS_CLIENT_SRCS:.c=.o)
SERVER_OBJS				= $(SERVER_SRCS:.c=.o)
BONUS_SERVER_OBJS		= $(BONUS_SERVER_SRCS:.c=.o)

OBJECTS_DIRECTORY		= objects

# ********* FT_PRINTF ********* #
FT_PRINTF				= ft_printf
FT_PRINTF_LIB			= libftprintf.a
FT_PRINTF_PATH			= $(FT_PRINTF)/$(FT_PRINTF_LIB)

# ********* LIBFT ********* #
LIBFT					= libft
LIBFT_LIB				= libft.a
LIBFT_PATH				= $(LIBFT)/$(LIBFT_LIB)

# ********* RULES ********* #

all: $(NAME)

$(NAME): $(SERVER_OBJS) $(CLIENT_OBJS) $(FT_PRINTF_PATH) $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(SERVER_OBJS) $(FT_PRINTF_PATH) $(LIBFT_PATH) -o server
	@$(CC) $(CFLAGS) $(CLIENT_OBJS) $(FT_PRINTF_PATH) $(LIBFT_PATH) -o client
	@chmod +x server
	@chmod +x client
	echo "OK\nServer and client compiled"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_SERVER_OBJS) $(BONUS_CLIENT_OBJS) $(FT_PRINTF_PATH) $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(BONUS_SERVER_OBJS) $(FT_PRINTF_PATH) $(LIBFT_PATH) -o server_bonus
	@$(CC) $(CFLAGS) $(BONUS_CLIENT_OBJS) $(FT_PRINTF_PATH) $(LIBFT_PATH) -o client_bonus
	@chmod +x server_bonus
	@chmod +x client_bonus
	echo "OK\nBONUS: Server and client compiled"

$(OBJECTS_DIRECTORY)/%.o: %.c
	@mkdir -p $(OBJECTS_DIRECTORY)
	@$(CC) $(CFLAGS) -c $< -o $@

ft_printf:
	@make -C $(FT_PRINTF)
	echo "OK\nft_printf compiled"

libft:
	@make -C $(LIBFT)
	echo "OK\nlibft compiled"

# ********* CLEAN ********* #

clean:
	@rm -rf $(OBJECTS_DIRECTORY)
	@rm -f $(SERVER_OBJS) $(CLIENT_OBJS) $(BONUS_SERVER_OBJS) $(BONUS_CLIENT_OBJS)
	@echo "OK\nObjects removed"

fclean: clean
	@rm -f server client server_bonus client_bonus
	@echo "OK\nServer and client removed"

re: fclean all

# ********* PHONY ********* #
.PHONY: all bonus clean fclean re

# ********* AnaTerMay ********* #