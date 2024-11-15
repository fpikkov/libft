CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

INCLUDE = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj

SRCS =	${SRC_DIR}/ft_isalpha.c \
		${SRC_DIR}/ft_isdigit.c \
		${SRC_DIR}/ft_isalnum.c \
		${SRC_DIR}/ft_isascii.c \
		${SRC_DIR}/ft_isprint.c \
		${SRC_DIR}/ft_strlen.c \
		${SRC_DIR}/ft_memset.c \
		${SRC_DIR}/ft_bzero.c \
		${SRC_DIR}/ft_memcpy.c \
		${SRC_DIR}/ft_memmove.c \
		${SRC_DIR}/ft_strlcpy.c \
		${SRC_DIR}/ft_strlcat.c \
		${SRC_DIR}/ft_toupper.c \
		${SRC_DIR}/ft_tolower.c \
		${SRC_DIR}/ft_strchr.c \
		${SRC_DIR}/ft_strrchr.c \
		${SRC_DIR}/ft_strncmp.c \
		${SRC_DIR}/ft_memchr.c \
		${SRC_DIR}/ft_memcmp.c \
		${SRC_DIR}/ft_strnstr.c \
		${SRC_DIR}/ft_atoi.c \
		${SRC_DIR}/ft_calloc.c \
		${SRC_DIR}/ft_strdup.c \
		${SRC_DIR}/ft_substr.c \
		${SRC_DIR}/ft_strjoin.c \
		${SRC_DIR}/ft_strtrim.c \
		${SRC_DIR}/ft_split.c \
		${SRC_DIR}/ft_itoa.c \
		${SRC_DIR}/ft_strmapi.c \
		${SRC_DIR}/ft_striteri.c \
		${SRC_DIR}/ft_putchar_fd.c \
		${SRC_DIR}/ft_putstr_fd.c \
		${SRC_DIR}/ft_putendl_fd.c \
		${SRC_DIR}/ft_putnbr_fd.c

B_SRCS =	${SRC_DIR}/ft_lstnew_bonus.c \
			${SRC_DIR}/ft_lstadd_front_bonus.c \
			${SRC_DIR}/ft_lstsize_bonus.c \
			${SRC_DIR}/ft_lstlast_bonus.c \
			${SRC_DIR}/ft_lstadd_back_bonus.c \
			${SRC_DIR}/ft_lstdelone_bonus.c \
			${SRC_DIR}/ft_lstclear_bonus.c \
			${SRC_DIR}/ft_lstiter_bonus.c \
			${SRC_DIR}/ft_lstmap_bonus.c

OBJS = ${patsubst ${SRC_DIR}/%.c,${OBJ_DIR}/%.o,${SRCS}}
B_OBJS = ${patsubst ${SRC_DIR}/%.c,${OBJ_DIR}/%.o,${B_SRCS}}


all: ${NAME}
	@echo "Creating libft..."

${NAME}: ${OBJS}
	@ar rcs $@ $^

${OBJS}: ${OBJ_DIR}/%.o : ${SRC_DIR}/%.c
	@if [ ! -d ${OBJ_DIR} ]; then \
		mkdir -p ${OBJ_DIR}; \
	fi
	@${CC} ${CFLAGS} -c $< -o $@ -I${INCLUDE}

${B_OBJS}: ${OBJ_DIR}/%.o : ${SRC_DIR}/%.c
	@if [ ! -d ${OBJ_DIR} ]; then \
		mkdir -p ${OBJ_DIR}; \
	fi
	@${CC} ${CFLAGS} -c $< -o $@ -I${INCLUDE}

.bonus:	${NAME} ${OBJS} ${B_OBJS}
	@ar rcs $^
	@touch .bonus
	@echo "Libft bonus created."

clean:
	@rm -rf ${OBJ_DIR}
	@rm -f .bonus
	@echo "Libft cleaned."

fclean: clean
	rm -f ${NAME}
	@echo "Libft fcleaned."

re: fclean all

bonus: .bonus

.PHONY: all re clean fclean bonus
