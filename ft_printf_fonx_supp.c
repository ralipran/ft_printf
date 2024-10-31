/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fonx_supp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralipran <ralipran@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:27:57 by ralipran          #+#    #+#             */
/*   Updated: 2024/10/31 14:17:33 by ralipran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write(char c, int *count)
{
	int success;

	if (*count != -1 )
	{
		success = write(1, &c, 1);
		if (success == -1)
			*count = -1;
		else
			*count += success;
	}
}

void	ft_putnbr_base(unsigned long int n,
	char *str_base, int base, int *count)
{
	if (n >= (unsigned long int)base)
		ft_putnbr_base(n / base, str_base, base, count);
	ft_write(*(str_base + (n % base)), count);
}

void	ft_putnbr(int nb, int *count)
{
	if (nb < 0)
	{
		write (1, "-", 1);
		ft_putnbr_base(-nb, "0123456789", 10, count);
	}
	else
		ft_putnbr_base(nb, "0123456789", 10, count);
}

void	ft_putstr(char *str, int *count)
{
	char	*null_msg;

	if (str == NULL)
	{
		null_msg = "(null)";
		while (*null_msg)
		{
			ft_write(*null_msg, count);
			null_msg++;
		}
		return ;
	}
	while (*str)
		ft_write(*str++, count);
}

void	ft_putptr(void *ptr, int *count)
{
	uintptr_t	ptr_as_nbr;

	ptr_as_nbr = (uintptr_t) ptr;
	ft_write('0', count);
	ft_write('x', count);
	ft_putnbr_base(ptr_as_nbr, "0123456789abcdef", 16, count);
}
