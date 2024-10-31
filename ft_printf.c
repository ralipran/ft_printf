/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralipran <ralipran@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:02:17 by ralipran          #+#    #+#             */
/*   Updated: 2024/10/31 13:03:21 by ralipran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	ft_write(c, count);
}

/*
 *	#include<stdint.h>
 *
 * 	void		*ptr;
 * 	uintptr_t	ptr_as_nbr;
 *
 * 	ptr_as_nbr = (uintptr_t) ptr;
 */

void	ft_which_flag(const char *str, va_list args, int *count)
{
	while (*str)
	{

		if (*str == '%')
		{
			str++;
			if (*str == 'c')
			ft_putchar (va_arg(args, int), count);
			else if (*str == 's')
			ft_putstr(va_arg(args, char *), count);
			else if (*str == 'p')
			ft_putptr(va_arg(args, void *), count);
			else if (*str == 'd' || *str == 'i')
			ft_putnbr(va_arg(args, int), count);
			else if (*str == 'u')
			ft_putnbr_base(va_arg(args, unsigned int), "0123456789", 10, count);
			else if (*str == 'x')
			ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef", 16, count);
			else if (*str == 'X')
			ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", 16, count);
			else if (*str == '%')
			ft_write('%', count);
		}
		else
			ft_write(*str, count);
		str++;
	}
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, input);
	ft_which_flag(input, args, &count);
	va_end(args);
	return (count);
}
