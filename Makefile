# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 14:27:23 by lluque            #+#    #+#              #
#    Updated: 2023/09/28 14:37:06 by lluque           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variable SRC con los nombres de los .c
SRC = main.c \
	  ft_test_isalpha.c \
	  ft_test_isdigit.c \
	  ft_test_isalnum.c \
	  ft_test_isascii.c \
	  ft_test_isprint.c \
	  ft_test_atoi.c \
	  ft_test_strlen.c \
	  ft_print_memory.c \
	  ft_ltoa.c \
	  ft_test_memset.c \
	  ft_test_bzero.c #\
	  ft_test_memcpy.c \
	  ft_test_memmove.c \
	  ft_test_strlcpy.c \
	  ft_test_strlcat.c \
	  ft_test_toupper.c \
	  ft_test_tolower.c \
	  ft_test_strchr.c \
	  ft_test_strrchr.c \
	  ft_test_strncmp.c \
	  ft_test_memchr.c \
	  ft_test_memcmp.c \
	  ft_test_strnstr.c \
	  ft_test_calloc.c \
	  ft_test_strdup.c \
	  ft_test_substr.c \
	  ft_test_strjoin.c \
	  ft_test_strtrim.c \
	  ft_test_split.c \
	  ft_test_strmapi.c \
	  ft_test_striteri.c \
	  ft_test_putchar_fd.c \
	  ft_test_putstr_fd.c \
	  ft_test_putendl_fd.c \
	  ft_test_putnbr_fd.c

# Variable con los nombres de los .o construidos a partir de SRC
OBJ = $(SRC:%.c=%.o)

# Variable con los flags para compilar
CC_FLAGS = -Wall -Werror -Wextra

# Flags para el comando ar
AR_FLAGS = -ru

# Variable con el nombre del binario del proyecto
NAME = tester

# INTRODUCCIÓN A LAS REGLAS:
#
# Toda regla tiene la estructura:
#
# targets:requisitos
#		comando 1
#		comando 2
#		...
#
# Una regla solo se ejecutará si NO existe un archivo con el nombre de su target (ver excepción más abajo)
# y si además existen los archivos indicados en requisitos (ver matiz a continuación).
# Si no existe un archivo cuyo nombre se indica entre los requisitos pero sí una regla con ese nombre,
# el requisito ahora quiere decir que antes deberá ejecutarse la regla con dicho nombre
#
# EXCEPCIÓN: Si make detecta que el archivo con el nombre de la regla 
# es más antiguo que el (algún) archivo con el nombre de su requisito
# SÍ se ejecuta la regla (como si el archivo con nombre de la regla no existiese)
# pues esto indicaría que el target es obsoleto
#
# Si los requisitos (o alguno) no existe, busca una regla con la que
# podría generarlos. Lo típico es que el target de una regla sea además el
# nombre de archivo que dicha regla, al ejecutarse, crearía.

# La primera regla:
# Por ser la primera regla es la default (se ejecuta solo con make)
# no tiene comandos porque están en la regla que hace de pre-requisito
all:$(NAME)

# Con esta regla se compila el binario del proyecto desde los .o utilizando
# un solo comando (a diferencia de la regla $(OBJ) que iba de 1 en 1)
#
# Como pre-requisitos tiene todos los archivos .o (valor de OBJ)
# Si no los encuentra todos ejecuta la regla $(OBJ) antes

#$(NAME):$(OBJ) ../repo_github/libft.a ../repo_github/libft.h
$(NAME):$(OBJ) ../repo1/libft.a ../repo1/libft.h
# ar $(AR_FLAGS) $(NAME) $(OBJ)
#	cc $(CC_FLAGS) $(OBJ) ../repo_github/libft.a -o $(NAME) 
	cc $(CC_FLAGS) $(OBJ) ../repo1/libft.a -o $(NAME) 
# En esta regla se usa pattern rule: TARGET: PATRÓN_DE_TARGETS: PATRÓN_DE REQS
# Es decir, para cada .o en OBJ se tiene como requisito su correspondiente .c
# (este último no es una regla sino un archivo: cada .c)
#
# Por usar pattern rules, se utilizan en el comando las 
# siguientes variables automáticas:
#		$^	Uno a uno cada pre-requisito (i.e. cada archivo .c)
#		$@	Uno a uno cada target
# Es decir, este target ejecuta el comando para cada .c produciendo cada .o
# con la magia del make: solo si por la fecha de modificación es necesario
$(OBJ): %.o: %.c
	cc -c $(CC_FLAGS) $^ -o $@

# Borra solo los .o
clean:
	rm -f $(OBJ)

# Borra el binario del proyecto, pero antes hace el pre-requisito
# que borra también los .o
fclean:clean
	rm -f $(NAME)

# Hace la regla fclean (borra .o y binario del proyecto)
# y luego recompila todos los .o y el binario del proyecto (regla all)
# Es decir: borra .o y binario del proyecto
re: fclean all

help:
	@echo
	@echo "    usar 'make', 'make all' o 'make $(NAME) para compilar solo lo que haya sido modificado (.o y binario final)"
	@echo "    usar 'make clean' para borrar los archivos .o"
	@echo "    usar 'make fclean para borar los archivos .o y el binario"
	@echo "    usar 'make re' para borrar todos los .o y el binario final y volver a compilar todo"
	@echo

# Esto evita problemas si existieran archivos con estos nombres.
# Pues son targets aquí y no se supone que representen archivos
.PHONY: all clean fclean re
