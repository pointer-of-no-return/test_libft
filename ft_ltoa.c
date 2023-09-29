/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:43:09 by lluque            #+#    #+#             */
/*   Updated: 2023/09/29 22:20:03 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../repo_github/libft.h"

char	ft_conv_less_sig_digl(long *nbr, int base, char *sym_table)
{
	int		digit;
	char	ret_val;

	digit = *nbr % base;
	if (digit < 0)
		digit *= -1;
	*nbr /= base;
	ret_val = sym_table[digit];
	return (ret_val);
}

int	ft_size_str_for_decl(long dec_nbr, int base_for_string, int include_sign)
{
	int	size;

	size = 2;
	if (dec_nbr < 0 && include_sign)
		size++;
	dec_nbr /= base_for_string;
	while (dec_nbr != 0)
	{
		dec_nbr /= base_for_string;
		size++;
	}
	return (size);
}

char	*ft_ltoa_b(long n, unsigned int base)
{
	char	*ret_val;
	int		size;
	int		i;
	int		is_negative;
	char	sym_table[16];

	size = ft_size_str_for_decl(n, base, 1);
	ret_val = malloc(size * sizeof (char));
	if (ret_val == NULL)
		return (NULL);
	i = size - 2;
	is_negative = 0;
	if (n < 0)
		is_negative = 1;
	ft_get_sym_table(sym_table);
	while ((!is_negative && i >= 0) || (is_negative && i > 0))
	{
		ret_val[i] = ft_conv_less_sig_digl(&n, base, sym_table);
		i--;
	}
	if (is_negative)
		ret_val[0] = '-';
	ret_val[size - 1] = '\0';
	return (ret_val);
}

char	*ft_ltoa(long n)
{
	return (ft_ltoa_b(n, 10));
}
