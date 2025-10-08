/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-vda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:41:08 by jose-vda          #+#    #+#             */
/*   Updated: 2025/05/12 10:41:13 by jose-vda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putchar(char c, size_t *counter);
void	ft_putstr(const char *s, size_t *counter);
void	ft_putnbr(long int n, size_t *counter);
void	ft_putunbr(size_t n, size_t *counter);
void	ft_puthex(size_t hex, char uppercase, size_t *counter);
void	ft_puthexp(void *hex, size_t *counter);
int		ft_printf(const char *str, ...);

#endif
