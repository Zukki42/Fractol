/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:29:09 by bavirgil          #+#    #+#             */
/*   Updated: 2025/10/03 18:06:35 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	c_add(t_complex a, t_complex b)
{
	t_complex	r;

	r.re = a.re + b.re;
	r.im = a.im + b.im;
	return (r);
}

t_complex	c_sq(t_complex z)
{
	t_complex	r;

	r.re = z.re * z.re - z.im * z.im;
	r.im = 2.0 * z.re * z.im;
	return (r);
}

double	c_abs2(t_complex z)
{
	return (z.re * z.re + z.im * z.im);
}
