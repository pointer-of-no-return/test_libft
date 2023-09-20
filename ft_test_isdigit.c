/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:39:48 by lluque            #+#    #+#             */
/*   Updated: 2023/09/20 11:01:28 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "../repo_github/libft.h"

void	ft_test_isdigit(int c)
{
	printf("PRUEBA isdigit con c = '%c' ('%d')\n", c, c);
	printf("\t\toriginal: \t\t%d\n", isdigit(c));
	printf("\t\tversion ft:\t\t%d\n", ft_isdigit(c));
	if (!isdigit(c) != !ft_isdigit(c))
        printf("**************** DISCREPANCIA ********************\n\n");
    else
        printf("\tTodo OK\n\n");
}
