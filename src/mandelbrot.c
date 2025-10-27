/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:29:37 by bavirgil          #+#    #+#             */
/*   Updated: 2025/10/27 12:10:57 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_iter(double cx, double cy)
{
	double	zx;
	double	zy;
	double	r2;
	double	nx;
	int		i;

	zx = 0.0;
	zy = 0.0;
	i = 0;
	while (i < 128)
	{
		r2 = zx * zx + zy * zy;
		if (r2 > 4.0)
			break ;
		nx = zx * zx - zy * zy + cx;
		zy = 2.0 * zx * zy + cy;
		zx = nx;
		i++;
	}
	return (i);
}
