/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:43:17 by lluque            #+#    #+#             */
/*   Updated: 2023/09/17 13:05:44 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "../repo_github/libft.h"

void	ft_test_isprint(int c)
{
	printf("PRUEBA isprint con c = '%c' ('%d')\n", c, c);
	printf("\t original: \t\t%d\n", isprint(c));
	printf("\t version ft:\t\t%d\n\n", ft_isprint(c));
}
