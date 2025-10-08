/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-vda <jose-vda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:24:35 by jose-vda          #+#    #+#             */
/*   Updated: 2025/05/01 16:24:35 by jose-vda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_base(unsigned long hex, const char *base, size_t *counter)
{
	if (hex >= 16)
		ft_puthex_base(hex / 16, base, counter);
	ft_putchar(base[hex % 16], counter);
}

void	ft_puthex(size_t hex, char format, size_t *counter)
{
	const char	*base;

	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	ft_puthex_base(hex, base, counter);
}

void	ft_puthexp(void *hex, size_t *counter)
{
	unsigned long int	address;

	address = (unsigned long int)hex;
	if (!address)
	{
		*counter = *counter + write(1, "(nil)", 5);
		return ;
	}
	*counter = *counter + write(1, "0x", 2);
	ft_puthex_base(address, "0123456789abcdef", counter);
}
