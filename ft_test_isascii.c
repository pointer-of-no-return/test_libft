/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:41:42 by lluque            #+#    #+#             */
/*   Updated: 2023/09/17 13:05:26 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "../repo_github/libft.h"

void	ft_test_isascii(int c)
{
	printf("PRUEBA isascii con c = '%c' ('%d')\n", c, c);
	printf("\t original: \t\t%d\n", isascii(c));
	printf("\t version ft:\t\t%d\n\n", ft_isascii(c));
}
