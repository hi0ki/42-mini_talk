/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:29:58 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/01/05 21:42:05 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_putung(unsigned int n);
int		ft_putchar(char c);
int		ft_putx(unsigned int nb, char c);
int		ft_putp(unsigned long nb);

#endif
