/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:08:39 by lluque            #+#    #+#             */
/*   Updated: 2023/09/17 15:26:58 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "../repo_github/libft.h"

void	ft_test_strlen(const char *s)
{
	printf("PRUEBA strlen con s = '%s'\n", s);
	printf("\t original: \t\t%zu\n", strlen(s));
	printf("\t version ft:\t\t%zu\n\n", ft_strlen(s));
}
