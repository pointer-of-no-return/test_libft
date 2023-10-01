/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_andres.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:46:18 by lluque            #+#    #+#             */
/*   Updated: 2023/10/01 18:08:19 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../repo_github/libft.h"
#include "test_libft.h"

void    *ft_print_memory(void *addr, unsigned int size);

int	main(void)
{
	char	c = 'x';
	char	q = 'y';
	char	w = 'z';
	int		t = 0;
	int		p = 32758;
	unsigned int	u = 4294967295;
	char    str2[] = "************";	
	char	str[] = "1234";
	printf("la direccion de t = '%lX' / p = '%lX' / u = '%lX'\n\n", (unsigned long)&t, (unsigned long)&p, (unsigned long)&u); 
	ft_print_memory(str, 100);
	/*
	 * char	str[5];
	 *
	 * str[0] = '1';
	 * ...
	 * str[5] = '\0';
	*/
	int		arr_int[] = {1, 2, 3, 4};
	short	sh = 12545;
	int		i = 2123456;
	long	l = 312345678902;
	float	f = 1.3;
	double	d = 3.1415973126726389;

	printf("sizeof (char) = %lu / sizeof (c) = %lu\n", sizeof (char), sizeof (c));
	printf("sizeof (short) = %lu / sizeof (sh) = %lu\n", sizeof (short), sizeof (sh));
	printf("sizeof (int) = %lu / sizeof (i) = %lu\n", sizeof (int), sizeof (i));
	printf("sizeof (long) = %lu / sizeof (l) = %lu\n", sizeof (long), sizeof (l));
	printf("sizeof (float) = %lu / sizeof (d) = %lu\n", sizeof (float), sizeof (f));
	printf("sizeof (double) = %lu / sizeof (f) = %lu\n", sizeof (double), sizeof (d));
	printf("\n\n");
	printf("&i evalua como: %lu / *(&i) evalua como '%i' / i evalua como '%i'\n", (unsigned long)&i, *(&i), i);
	printf("str evalua como: %lu / *str evalua como '%c' / str[0] evalua como '%c'\n", (unsigned long)str, *str, str[0]);
	printf("arr_int evalua como: %lu / *arr_int evalua como '%i' / arr_int[0] evalua como '%i'\n", (unsigned long)arr_int, *arr_int, arr_int[0]);
	printf("\n\n");
	printf("sizeof (int *) = %lu\n", sizeof (int*));
	printf("sizeof (str) = %lu\n", sizeof (str));
	printf("sizeof (array_int) = %lu\n", sizeof (arr_int));

	ft_print_memory(&d, 5000);
	return (0);
}
