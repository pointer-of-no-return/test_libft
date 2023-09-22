/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:58:16 by lluque            #+#    #+#             */
/*   Updated: 2023/09/21 21:09:17 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "../repo_github/libft.h"

void    *ft_print_memory(void *addr, unsigned int size);

void	ft_test_bzero(void *original, void *ft, size_t len)
{
	printf("PRUEBA bzero con original = '%zu', ft = '%zu', len = '%zu'\n", (unsigned long)original, (unsigned long)ft, len);
	printf("\t Antes de modificar:\n");
	printf("\t original:\n");
	ft_print_memory(original, 150);
	printf("\n\t version ft:\n");
	ft_print_memory(ft, 150);
	bzero(original, len);
	ft_bzero(ft, len);
	printf("\t original:\n");
	ft_print_memory(original, 150);
	printf("\n\t version ft:\n");
	ft_print_memory(ft, 150);
	printf("\n");
}
/*
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *)b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}
*/
