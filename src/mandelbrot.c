/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:29:37 by bavirgil          #+#    #+#             */
/*   Updated: 2025/10/11 04:10:57 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_iter(double cx, double cy)
{
	const int	max_it = 128;
	double		zx;
	double		zy;
	double		zx2;
	double		zy2;
	int			i;

	zx = 0.0;
	zy = 0.0;
	i = 0;
	while (i < max_it)
	{
		zx2 = zx * zx;
		zy2 = zy * zy;
		if (zx2 + zy2 > 4.0)
			break ;
		zy = 2.0 * zx * zy + cy;
		zx = zx2 - zy2 + cx;
		i++;
	}
	return (i);
}

