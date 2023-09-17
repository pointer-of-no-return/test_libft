/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:58:16 by lluque            #+#    #+#             */
/*   Updated: 2023/09/17 15:33:43 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "../repo_github/libft.h"

void	ft_test_memset(void *b, int c, size_t len)
{
	printf("PRUEBA memset con b = '%zu', int = '%d', len = '%zu'\n", b, c, len);
	printf("\t original: \t\t%d\n", memset(b, c, len));
	printf("\t version ft:\t\t%d\n\n", ft_memset(b, c, len));
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
