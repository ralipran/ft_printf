/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralipran <ralipran@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:06:42 by ralipran          #+#    #+#             */
/*   Updated: 2024/10/31 14:18:25 by ralipran         ###   ########.fr       */
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
char *str_base, int base, int *count);
void	ft_putnbr(int nb, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putptr(void *ptr, int *count);
void	ft_putchar(char c, int *count);
void	ft_which_flag(const char *str, va_list args, int *count);
int		ft_printf(const char *input, ...);
#endif
