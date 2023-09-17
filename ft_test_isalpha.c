/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:37:32 by lluque            #+#    #+#             */
/*   Updated: 2023/09/17 13:04:31 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "../repo_github/libft.h"

void	ft_test_isalpha(int c)
{
	printf("PRUEBA isalpha con c = '%c' ('%d')\n", c, c);
	printf("\t original: \t\t%d\n", isalpha(c));
	printf("\t version ft:\t\t%d\n\n", ft_isalpha(c));
}
