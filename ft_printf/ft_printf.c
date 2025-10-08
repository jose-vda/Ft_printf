/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-vda <jose-vda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:25:32 by jose-vda          #+#    #+#             */
/*   Updated: 2025/05/01 16:27:23 by jose-vda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

void	ft_flags(const char *str_char, va_list args, size_t *counter)
{
	if (*str_char == 'c')
		ft_putchar((char)va_arg(args, int), counter);
	else if (*str_char == 's')
		ft_putstr(va_arg(args, const char *), counter);
	else if (*str_char == 'd' || *str_char == 'i')
		ft_putnbr(va_arg(args, int), counter);
	else if (*str_char == 'u')
		ft_putunbr(va_arg(args, unsigned int), counter);
	else if (*str_char == 'x' || *str_char == 'X')
		ft_puthex(va_arg(args, unsigned int), *str_char, counter);
	else if (*str_char == 'p')
		ft_puthexp(va_arg(args, void *), counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar(str[i], &counter);
		else if (str[i] == '%' && str[i + 1] != '\0')
		{
			if (str[i + 1] != '%')
				ft_flags(&str[i + 1], args, &counter);
			else
				ft_putchar(str[i], &counter);
			i++;
		}
		i++;
	}
	va_end(args);
	return (counter);
}

/*int main(void)
{
	int x = 420;

	ft_printf("Char: 				%c\n", 'B');
	ft_printf("String: 				%s\n", "Eu amo estudar");
	ft_printf("Inteiro: 			%d\n", -1234);
	ft_printf("Unsigned int:		%u\n", 3000000000U);
	ft_printf("Hex lowercase:		%x\n", 4972);
	ft_printf("Hex uppercase:		%X\n", 4972);
	ft_printf("Pointer: 			%p\n", &x);
	printf("Original:			%p\n", &x);
	ft_printf("Percent:					%%\n");
	return (0);
}*/
