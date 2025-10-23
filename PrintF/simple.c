/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:44:37 by bavirgil          #+#    #+#             */
/*   Updated: 2025/08/10 21:15:02 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Write a single character to stdout.
** Used by ft_printf as the base output unit for all other print functions.
*/
int	ft_putchar(char c)
{
	int	temp;

	temp = write(1, &c, 1);
	if (temp == -1)
		return (-1);
	return (temp);
}

/*
** Write a string to stdout; if NULL, print "(null)".
** Needed for ft_printf's %s specifier to handle normal and NULL strings.
*/
int	ft_putstr(const char *s)
{
	int	count;
	int	temp;

	if (!s)
		return (ft_putstr("(null)"));
	count = 0;
	while (*s)
	{
		temp = write(1, s++, 1);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	return (count);
}

/*
** Print a signed integer in decimal format.
** Implements %d and %i in ft_printf, handling negative numbers.
*/
int	print_int(int n)
{
	int		count;
	int		temp;
	long	num;

	temp = 0;
	num = n;
	count = 0;
	if (num < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		count++;
		num = -num;
	}
	if (num >= 10)
		temp += print_int((int)(num / 10));
	if (temp == -1)
		return (-1);
	else
		count += temp;
	if (ft_putchar((char)((num % 10) + '0')) == -1)
		return (-1);
	else
		count++;
	return (count);
}

/*
** Print an unsigned integer in decimal format.
** Implements the %u specifier for ft_printf.
*/
int	print_unsigned(unsigned int n)
{
	int		count;
	int		temp;

	temp = 0;
	count = 0;
	if (n >= 10)
		temp += print_int((int)(n / 10));
	if (temp == -1)
		return (-1);
	else
		count += temp;
	if (ft_putchar((char)((n % 10) + '0')) == -1)
		return (-1);
	else
		count++;
	return (count);
}

/*
** Print a percent sign '%'.
** Handles the %% specifier in ft_printf.
*/
int	print_percent(void)
{
	return (ft_putchar('%'));
}
