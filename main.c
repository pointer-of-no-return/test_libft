/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:55:37 by lluque            #+#    #+#             */
/*   Updated: 2023/09/18 17:01:46 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../repo_github/libft.h"
#include "test_libft.h"

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
	/*
	lst_i = 0;
	lst_size = ft_lstsize(lst_first_item);
	while (lst_i < lst_size)
	{

		lst_i++;
	}
*/
	
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
