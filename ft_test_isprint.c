/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:43:17 by lluque            #+#    #+#             */
/*   Updated: 2023/09/20 11:02:09 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "../repo_github/libft.h"

void	ft_test_isprint(int c)
{
	printf("PRUEBA isprint con c = '%c' ('%d')\n", c, c);
	printf("\t\toriginal: \t\t%d\n", isprint(c));
	printf("\t\tversion ft:\t\t%d\n", ft_isprint(c));
	if (!isprint(c) != !ft_isprint(c))
        printf("**************** DISCREPANCIA ********************\n\n");
    else
        printf("\tTodo OK\n\n");
}
