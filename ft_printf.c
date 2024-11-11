/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralipran <ralipran@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:02:17 by ralipran          #+#    #+#             */
/*   Updated: 2024/11/11 11:26:15 by ralipran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	ft_write(c, count);
}

void	ft_read_flag(const char *str, va_list args, int *count)
{
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_flag_treat(*str, args, count);
		}
		else
			ft_write(*str, count);
		str++;
	}
}

void	ft_flag_treat(char flag, va_list args, int *count)
{
	const char	*base_hex_lower;
	const char	*base_hex_upper;

	base_hex_lower = "0123456789abcdef";
	base_hex_upper = "0123456789ABCDEF";
	if (flag == 'c')
		ft_putchar (va_arg(args, int), count);
	else if (flag == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (flag == 'p')
		ft_putptr(va_arg(args, void *), count);
	else if (flag == 'd' || flag == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (flag == 'u')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789", 10, count);
	else if (flag == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), base_hex_lower, 16, count);
	else if (flag == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), base_hex_upper, 16, count);
	else if (flag == '%')
		ft_write('%', count);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, input);
	ft_read_flag(input, args, &count);
	va_end(args);
	return (count);
}
