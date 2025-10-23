/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:44:40 by bavirgil          #+#    #+#             */
/*   Updated: 2025/08/10 21:44:04 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Convert and print an unsigned long long in lowercase hexadecimal.
** Used internally by print_ptr to output the address part of %p.
*/
static int	print_hex_ptr(unsigned long long n)
{
	int		count;
	int		temp;
	char	c;

	temp = 0;
	count = 0;
	if (n >= 16)
		temp += print_hex_ptr(n / 16);
	if (temp == -1)
		return (-1);
	count += temp;
	if ((n % 16) < 10)
		c = (char)('0' + (n % 16));
	else
		c = (char)('a' + ((n % 16) - 10));
	if (ft_putchar(c) == -1)
		return (-1);
	count++;
	return (count);
}

/*
** Print a pointer address in hexadecimal format with "0x" prefix.
** Implements the %p specifier in ft_printf, handling NULL with PTRNULL.
*/
int	print_ptr(void *ptr)
{
	int					count;
	int					temp;
	unsigned long long	n;

	if (ptr == NULL)
		return (ft_putstr(PTRNULL));
	temp = 0;
	count = 0;
	temp = ft_putstr("0x");
	if (temp == -1)
		return (-1);
	count += temp;
	n = (unsigned long long)ptr;
	temp = print_hex_ptr(n);
	if (temp == -1)
		return (-1);
	count += temp;
	return (count);
}

/*
** Print an unsigned integer in hexadecimal format.
** Implements %x (lowercase) and %X (uppercase) for ft_printf.
*/
int	print_hex(unsigned int n, int uppercase)
{
	int		count;
	int		temp;
	char	c;
	char	base_a;

	if (n == 0)
		return (ft_putchar('0'));
	count = 0;
	temp = 0;
	base_a = 'a';
	if (uppercase)
		base_a = 'A';
	if (n >= 16)
		temp = print_hex(n / 16, uppercase);
	if (temp == -1)
		return (-1);
	count += temp;
	if ((n % 16) < 10)
		c = (char)('0' + (n % 16));
	else
		c = (char)(base_a + ((n % 16) - 10));
	if (ft_putchar(c) == -1)
		return (-1);
	count++;
	return (count);
}
