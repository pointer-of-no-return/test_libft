/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:08:39 by lluque            #+#    #+#             */
/*   Updated: 2023/09/20 11:04:05 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "../repo_github/libft.h"

void	ft_test_strlen(const char *s)
{
	printf("PRUEBA strlen con s = '%s'\n", s);
	printf("\t\toriginal: \t\t%zu\n", strlen(s));
	printf("\t\tversion ft:\t\t%zu\n", ft_strlen(s));
	if (strlen(s) - ft_strlen(s) != 0)
        printf("**************** DISCREPANCIA ********************\n\n");
    else
        printf("\tTodo OK\n\n");
}
