/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:55:37 by lluque            #+#    #+#             */
/*   Updated: 2023/09/22 17:30:33 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../repo_github/libft.h"
#include "test_libft.h"

void	*ft_print_memory(void *addr, unsigned int size);

void	ft_print_integer(void *integer)
{
	printf("\t\t\t\tEl entero es '%d'\n", *(int *)integer);
}

void	ft_lst_item_del(void *content)
{
	if (content == NULL)
		return ;
	free(content);
}

void	*ft_lst_item_cpy(void *content)
{
	void	*ret_val;

	if (content == NULL)
		return (NULL);
	ret_val = malloc(sizeof (content));
	*(int *)ret_val = *(int *)content;
	return (ret_val);
}

/*
void	*ft_add_thousand_to_integer(void *integer)
{
	*(int *)integer += 1000;
	return (
	//printf("\t\t\t\tEl entero es '%d'\n", *(int *)integer);
}
*/
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
	ft_test_isalpha(-352);
	ft_test_isalpha(0);

	ft_test_isdigit(argv[1][0]);
	ft_test_isdigit(-352);
	ft_test_isdigit(0);

	ft_test_isalnum(argv[1][0]);
	ft_test_isalnum(-352);
	ft_test_isalnum(0);

	ft_test_isascii(argv[1][0]);
	ft_test_isascii(-352);
	ft_test_isascii(0);

	ft_test_isprint(argv[1][0]);
	ft_test_isprint(-352);
	ft_test_isprint(0);

	ft_test_atoi(argv[3]);
	//ft_test_atoi(NULL);					// Ambas versiones dan seg fault
	ft_test_atoi("");
	ft_test_atoi("  	23fsdf sdfsdf");
	ft_test_atoi("12345678901234567890");	///Discrepancia detectada
	ft_test_atoi("-12345678901234567890");

	ft_test_strlen(argv[2]);
	//ft_test_strlen(NULL);					// Ambas versiones dan seg fault
	ft_test_strlen("");						

	char original[] = "Hola! esto es una prueba para ver el contenido de memoria. Esto es una tabulacion '\t' y esto una nueva linea '\n'";

	char    ft[] = "Hola! esto es una prueba para ver el contenido de memoria. Esto es una tabulacion '\t' y esto una nueva linea '\n'";
	ft_test_memset(original + 15, ft + 15, '@', 5);	
	ft_test_memset(original + 25, ft + 25, '@', 0);
	//ft_test_memset(NULL, NULL, '@', 10);	// Ambas versiones dan seg fault


	char original_b[] = "Hola! esto es una prueba para ver el contenido de memoria. Esto es una tabulacion '\t' y esto una nueva linea '\n'";

	char    ft_b[] = "Hola! esto es una prueba para ver el contenido de memoria. Esto es una tabulacion '\t' y esto una nueva linea '\n'";
	ft_test_bzero(original_b + 1, ft_b + 1, 5);
	ft_test_bzero(original_b + 17, ft_b + 17, 5);
	//ft_test_bzero(NULL, NULL, 5);	// Ambas versiones dan seg fault

	printf("\n\nAhora se probara el calloc:\n");
	
	char	*lienzo_en_blanco;
	char	*lienzo_en_negro;
	char    *block_calloc1;
	char    *block_calloc2;
	char    *block_calloc3;

	lienzo_en_blanco = ft_calloc(10, 16);	// Ambas versiones dan un puntero válido con 0,0 x,0 0,y (por malloc
										// La calloc original reserva e inicializa en bloques de 16 siempre
										// (no hay que replicar ese comportamiento)
	printf("El sizeof de char es '%lu'\n", sizeof (char));
	printf("El sizeof de short es '%lu'\n", sizeof (short));
	printf("El sizeof de int es '%lu'\n", sizeof (int));
	printf("El sizeof de long es '%lu'\n", sizeof (long));
	printf("El sizeof de long long es '%lu'\n", sizeof (long long));
	printf("El sizeof de float es '%lu'\n", sizeof (float));
	printf("El sizeof de double es '%lu'\n", sizeof (double));
	printf("El sizeof de la variable es '%lu'\n", sizeof (*lienzo_en_blanco));
	printf("Imprimiendo lienzo original (dir: '%#lx')\n", (long unsigned)lienzo_en_blanco);
	ft_print_memory(lienzo_en_blanco, 10 * 16);
	
	printf("\n\nAhora se probara el memset:\n");

	lienzo_en_negro = malloc(10 * 16 * sizeof (char));
	ft_memset(lienzo_en_negro, 64, 10 * 16);
	printf("Imprimiendo lienzo en negro (dir: '%#lx')\n", (long unsigned)lienzo_en_negro);
	ft_print_memory(lienzo_en_negro, 10 * 16);
	
	//ft_memset(lienzo_en_negro + 2, 0, 14);
	//ft_memset(lienzo_en_negro + 2 + 16, 0, 12);
	ft_memset(lienzo_en_negro + 2 + 32, 0, 12);
	ft_memset(lienzo_en_negro + 2 + 48, 0, 12);
	ft_memset(lienzo_en_negro + 2 + 64, 0, 12);
	ft_memset(lienzo_en_negro + 2 + 64 + 16, 0, 12);
	ft_memset(lienzo_en_negro + 2 + 64 + 32, 0, 12);
	ft_memset(lienzo_en_negro + 2 + 64 + 48, 0, 12);
	//ft_memset(lienzo_en_negro + 2 + 64 + 64, 0, 12);
	printf("Cuadrado blanco en lienzo negro (dir: '%#lx')\n", (long unsigned)lienzo_en_negro);
	ft_print_memory(lienzo_en_negro, 10 * 16);
	
	printf("Memset con casos rars\n");
	//ft_memset(lienzo_en_blanco + 17, '*', 1);
	//ft_memset(lienzo_en_blanco + 17, '*', 0);
	printf("\tCaso 1:\n");
	ft_memset(lienzo_en_blanco + 17, '*', (0));		// Ambas bien, no hacen nada con len=0
	ft_print_memory(lienzo_en_blanco, 10 * 16);
	printf("\tCaso 2:\n");
	ft_memset(lienzo_en_blanco + 17, -64, 5);
	ft_print_memory(lienzo_en_blanco, 10 * 16);
	ft_memset(lienzo_en_blanco + 17, 0, 5);
	printf("\tCaso 3:\n");
	memset(lienzo_en_blanco + 17, -64, 5);			// Valores negativos interpretados idénticamente
	ft_print_memory(lienzo_en_blanco, 10 * 16);
	printf("\tCaso 4:\n");
	//memset(NULL, '*', 5);
	//ft_memset(NULL, '*', 5);						// Ambas versiones explotan con NULL
	ft_print_memory(lienzo_en_blanco, 10 * 16);
	
	return (0);
	block_calloc2 = ft_calloc(30, 0);
	block_calloc1 = ft_calloc(30, 0);
	printf("Imprimiendo block_calloc1 (dir: '%#lx')\n", (long unsigned)block_calloc1);
	ft_print_memory(block_calloc1, 30);
	//block_calloc2 = malloc(30 * sizeof (char));
	//ft_memset(block_calloc2, 64, 30);
	block_calloc3 = calloc(30, 1);
	printf("Imprimiendo block_calloc3 (dir: '%#lx')\n", (long unsigned)block_calloc3);
	ft_print_memory(block_calloc3, 30);
	printf("\n");

	return (0);
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
	
	printf("Ahora se probara el bonus\n");
	int	*lst_contenido;
	t_list	*lst_item;
	t_list	*lst_first_item;
	int	lst_i;
	int	lst_contenido_temp;

	lst_contenido = malloc(1 * sizeof (int));
	*lst_contenido = 69;
	lst_item = ft_lstnew(lst_contenido);
	lst_first_item = lst_item;
	printf("\tCreado el primer nodo '%lu' con contenido '%d'\n", (unsigned long)lst_first_item, *(int *)lst_first_item->content);
	printf("\tLa lista tiene ahora '%d' elementos\n", ft_lstsize(lst_first_item));
	lst_i = 1;
	while (lst_i < 10)
	{
		lst_contenido_temp = *lst_contenido;
		lst_contenido = malloc(1 * sizeof(int));
		*lst_contenido = lst_contenido_temp + 10;
		lst_item = ft_lstnew(lst_contenido);
		printf("\tCreado el nodo '%lu' con contenido '%d'\n", (unsigned long)lst_item, *(int *)lst_item->content);
		ft_lstadd_back(&lst_first_item, lst_item);
		printf("\t\tAgregado  el nodo '%lu' al FINAL de la  lista '%lu'\n", (unsigned long)lst_item, (unsigned long)lst_first_item);
		printf("\tLa lista tiene ahora '%d' elementos\n", ft_lstsize(lst_first_item));
		lst_i++;
	}

	printf("\tAhora se añadirán elementos al inicio de la lista\n");
	*lst_contenido = 59;
	lst_i = 1;
	while (lst_i < 10)
	{
		lst_contenido_temp = *lst_contenido;
		lst_contenido = malloc(1 * sizeof(int));
		*lst_contenido = lst_contenido_temp - 10;
		lst_item = ft_lstnew(lst_contenido);
		printf("\tCreado el nodo '%lu' con contenido '%d'\n", (unsigned long)lst_item, *(int *)lst_item->content);
		ft_lstadd_front(&lst_first_item, lst_item);
		printf("\t\tAgregado el nodo '%lu' al COMIENZO de la lista '%lu'\n", (unsigned long)lst_item, (unsigned long)lst_first_item);
		printf("\tLa lista tiene ahora '%d' elementos\n", ft_lstsize(lst_first_item));
		lst_i++;
	}
	printf("Ahora se iterara por todos los elementos imprimiendo el contenido\n");
	ft_lstiter(lst_first_item, ft_print_integer);
	
	printf("Ahora se creara una copia de la lista\n");
	t_list	*new_list;

	new_list = ft_lstmap(lst_first_item, ft_lst_item_cpy, ft_lst_item_del);
	
	printf("Este es el contenido de la lista original\n");
	ft_lstiter(lst_first_item, ft_print_integer);
	
	printf("Este es el contenido de la nueva lista\n");
	ft_lstiter(new_list, ft_print_integer);

	printf("Ahora se borrara la nueva lista completamente\n");
	ft_lstclear(&new_list, ft_lst_item_del);

	return (0);
}
