/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:40:41 by lluque            #+#    #+#             */
/*   Updated: 2023/09/17 13:05:09 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "../repo_github/libft.h"

void	ft_test_isalnum(int c)
{
	printf("PRUEBA isalnum con c = '%c' ('%d')\n", c, c);
	printf("\t original: \t\t%d\n", isalnum(c));
	printf("\t version ft:\t\t%d\n\n", ft_isalnum(c));
}
