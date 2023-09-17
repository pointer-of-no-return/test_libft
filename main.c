/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:55:37 by lluque            #+#    #+#             */
/*   Updated: 2023/09/17 15:50:10 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../repo_github/libft.h"
#include "test_libft.h"

char	ft_prueba(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (c);
	return (' ');
}

void	ft_prueba2(unsigned int i, char *c)
{
	if (!(i % 2 == 0))
		*c = ' ';
}
/*
void	ft_printmem(void *ptr, size_t bytes)
{
	int	i;

	i = 0;
	while (i < bytes)
	{
		ft_putstr_fd(ft_itoa
	}
}
*/
int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		printf("Error en cantidad de parametros, debe ser:\n");
		printf("\t... %% tester un_caracter un_string un_entero\n");
		return (1);
	}
	printf("\n");

	ft_test_isalpha(argv[1][0]);
	ft_test_isdigit(argv[1][0]);
	ft_test_isalnum(argv[1][0]);
	ft_test_isascii(argv[1][0]);
	ft_test_isprint(argv[1][0]);
	ft_test_atoi(argv[3]);
	ft_test_strlen(argv[2]);
	//ft_test_strlen(NULL);	//ambas versiones deben dar segfault
	/*
	char	*buffer[100];
	ft_test_memset(buffer, argv[1][0], 100);
	*/
	int	itoa_nbr;
	itoa_nbr = 2147483647;
	printf("El entero '%d' con ft_itoa se convierte en '%s'\n", itoa_nbr, ft_itoa(itoa_nbr));
	itoa_nbr = 0;
	printf("El entero '%d' con ft_itoa se convierte en '%s'\n", itoa_nbr, ft_itoa(itoa_nbr));
	itoa_nbr = -2147483648;
	printf("El entero '%d' con ft_itoa se convierte en '%s'\n", itoa_nbr, ft_itoa(itoa_nbr));
	itoa_nbr = ft_atoi(argv[3]);
	printf("El string '%s' que pasado por ft_atoi se vuelve '%d' con ft_itoa se convierte en '%s'\n", argv[3], itoa_nbr, ft_itoa(itoa_nbr));
	printf("\n");
	return (0);
}
	/*
	char	*ptr;

	if (argc != 2)
		return (1);
	if (ft_isalpha(argv[1][0]))
		printf("El primer char de '%s' -> '%c' es alpha\n", argv[1], argv[1][0]);
	if (ft_isdigit(argv[1][0]))
		printf("El primer char de '%s' ->'%c' es un digito\n", argv[1], argv[1][0]);
	if (ft_isalnum(argv[1][0]))
		printf("El primer char de '%s' ->'%c' es alfanumerico\n", argv[1], argv[1][0]);
	if (ft_isascii(argv[1][0]))
		printf("El primer char de '%s' ->'%c' es ascii\n", argv[1], argv[1][0]);
	printf("Prueba para ft_isprint():\n");
	int c_print;
	c_print = 32;
	printf("\tCon c = '%d' que representa '%c' ft_isprint(c) retorna: '%d'\n", c_print, c_print, ft_isprint(c_print));
	c_print = -32;
	printf("\tCon c = '%d' que representa '%c' ft_isprint(c) retorna: '%d'\n", c_print, c_print, ft_isprint(c_print));
	c_print = 64;
	printf("\tCon c = '%d' que representa '%c' ft_isprint(c) retorna: '%d'\n", c_print, c_print, ft_isprint(c_print));
	c_print = -64;
	printf("\tCon c = '%d' que representa '%c' ft_isprint(c) retorna: '%d'\n", c_print, c_print, ft_isprint(c_print));
	c_print = '~' + 1;
	printf("\tCon c = '%d' que representa '%c' ft_isprint(c) retorna: '%d'\n", c_print, c_print, ft_isprint(c_print));
	c_print = ' ' - 1;
	printf("\tCon c = '%d' que representa '%c' ft_isprint(c) retorna: '%d'\n", c_print, c_print, ft_isprint(c_print));
	printf("El string '%s' tiene '%zu' caracteres\n", argv[1], ft_strlen(argv[1]));	
	ptr = malloc(ft_strlen(argv[1]) * sizeof (char));
	ft_memset(ptr, argv[1][0], ft_strlen(argv[1]));
	ptr[ft_strlen(argv[1])] = '\0';
	printf("El arreglo de ft_memset() quedo como: '%s'\n", ptr);

	ft_memset(ptr, 64, ft_strlen(argv[1]));
	ptr[ft_strlen(argv[1]) - 1] = '\0';
	printf("Y un ft_memset(ptr, 64, ft_strlen(argv[1])) queda como: \n\t'%s'\n", ptr);
	ft_memset(ptr, -64, ft_strlen(argv[1]));
	ptr[ft_strlen(argv[1]) - 1] = '\0';
	printf("Y un ft_memset(ptr, -64, ft_strlen(argv[1])) queda como: \n\t'%s'\n", ptr);
	ft_memset(ptr, 32, ft_strlen(argv[1]));
	ptr[ft_strlen(argv[1]) - 1] = '\0';
	printf("Y un ft_memset(ptr, 32, ft_strlen(argv[1])) queda como: \n\t'%s'\n", ptr);
	int	memset_prueba = -129;
	ft_memset(ptr, memset_prueba, ft_strlen(argv[1]));
	ptr[ft_strlen(argv[1]) - 1] = '\0';
	printf("Y un ft_memset(ptr, %d, ft_strlen(argv[1])) queda como: \n\t'%s'\n", memset_prueba, ptr);
	printf("\tY byte a byte sumando '0' para hacerlo imprimible:\n");
	size_t	i_memset= 0;
	while (i_memset < ft_strlen(argv[1]))
	{
		printf("\t%d\n", ptr[i_memset]);
		i_memset++;
	}



	printf("Pero si ahora se llama a ft_bzero() sobre el mismo arreglo y se suma '0' para hacerlo imprimible:\n");
	size_t	i_bzero = 0;
	ft_bzero(ptr, ft_strlen(argv[1]));
	while (i_bzero < ft_strlen(argv[1]))
	{
		printf("\t%c\n", ptr[i_bzero] + '0');
		i_bzero++;
	}

	printf("El resultado de ft_strmapi() sobre '%s' es '%s'\n", argv[1] , ft_strmapi(argv[1],ft_prueba));
	printf("El resultado de ft_striteri() sobre '%s' es ", argv[1]);
	
	int	len;
	int	i;
	i = 0;
	len = ft_strlen(argv[1]);
	while (i < len)
	{
		ft_striteri(argv[1], ft_prueba2);
		i++;
	}
	printf("'%s'\n", argv[1]);
	
	return (0);
}
*/
