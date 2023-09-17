/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:39:48 by lluque            #+#    #+#             */
/*   Updated: 2023/09/17 13:04:48 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "../repo_github/libft.h"

void	ft_test_isdigit(int c)
{
	printf("PRUEBA isdigit con c = '%c' ('%d')\n", c, c);
	printf("\t original: \t\t%d\n", isdigit(c));
	printf("\t version ft:\t\t%d\n\n", ft_isdigit(c));
}
