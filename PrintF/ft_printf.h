/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:45:33 by bavirgil          #+#    #+#             */
/*   Updated: 2025/08/10 19:02:22 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

# ifdef __APPLE__
#  define PTRNULL "0x0"
# elif defined(__linux__)
#  define PTRNULL "(nil)"
# else
#  define PTRNULL "(nil)"
# endif

// PRINTF FILE
int	ft_printf(const char *format, ...);
int	handle_format(char sp, va_list ap);

// SIMPLE.C
int	ft_putchar(char c);
int	ft_putstr(const char *s);
int	print_int(int n);
int	print_unsigned(unsigned int n);
int	print_percent(void);

// COMPLEX.C
int	print_hex(unsigned int n, int uppercase);
int	print_ptr(void *ptr);
#endif