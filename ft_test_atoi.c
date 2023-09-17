/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:42:26 by lluque            #+#    #+#             */
/*   Updated: 2023/09/17 13:10:55 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../repo_github/libft.h"

void	ft_test_atoi(const char *str)
{
	printf("PRUEBA atoi con str = '%s'\n", str);
	printf("\t original: \t\t%d\n", atoi(str));
	printf("\t version ft:\t\t%d\n\n", ft_atoi(str));
}
/*
	int		sign;
	int		len;
	int		i;
	long	ret_val;
	char	buffer[11];

	i = 0;
	len = 0;
	while (ft_isspace(str[i]))
		i++;
	if (!ft_isdigit(str[i]))
	{
		sign = ft_issign(str[i]);
		if (sign == 0)
			return (0);
	}
	while (ft_isdigit(str[i]))
		len++;
	while (i < len)
	{
		ret_val = ret_val + (buffer[i] - '\0') * ft_exp(10, len - 1 - i);
		i++;
	}
	return (sign * ret_val);
}
*/