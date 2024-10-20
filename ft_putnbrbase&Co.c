/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbrbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralipran <ralipran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:02:17 by ralipran          #+#    #+#             */
/*   Updated: 2024/10/20 23:08:58 by ralipran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_base(unsigned long int n,
	char *str_base, int base, int *count)
{
	if (n >= base)
		ft_putnbr_base(n / base, str_base, base, count);
	*count += write(1, str_base + (n % base), 1);
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

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write (1, &str[i], 1);
	return (str)
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}