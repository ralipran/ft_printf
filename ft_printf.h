/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralipran <ralipran@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:06:42 by ralipran          #+#    #+#             */
/*   Updated: 2024/11/05 16:45:20 by ralipran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <limits.h>

void	ft_write(char c, int *count);
void	ft_putnbr_base(unsigned long int n,
			const char *str_base, int base, int *count);
void	ft_putnbr(long nb, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putptr(void *ptr, int *count);
void	ft_putchar(char c, int *count);
void	ft_read_flag(const char *str, va_list args, int *count);
void	ft_flag_treat(char flag, va_list args, int *count);
int		ft_printf(const char *input, ...);
#endif
