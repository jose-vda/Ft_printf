/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-vda <jose-vda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:25:10 by jose-vda          #+#    #+#             */
/*   Updated: 2025/05/01 16:25:10 by jose-vda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, size_t *counter)
{
	*counter = *counter + write(1, &c, 1);
}

void	ft_putstr(const char *s, size_t *counter)
{
	int	i;

	i = 0;
	if (!s)
	{
		*counter = *counter + write(1, "(null)", 6);
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i], counter);
		i++;
	}
}

void	ft_putnbr(long int n, size_t *counter)
{
	char	res;

	if (n < 0)
	{
		ft_putchar('-', counter);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10, counter);
	res = (n % 10) + '0';
	ft_putchar(res, counter);
}

void	ft_putunbr(size_t n, size_t *counter)
{
	char	res;

	if (n > 9)
		ft_putunbr(n / 10, counter);
	res = (n % 10) + '0';
	ft_putchar(res, counter);
}
