/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:31:23 by bavirgil          #+#    #+#             */
/*   Updated: 2025/10/11 04:29:43 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	burning_step(double *x, double *y, double cx, double cy)
{
	double	xx;
	double	yy;
	double	ax;
	double	ay;

	xx = (*x) * (*x);
	yy = (*y) * (*y);
	if (*x >= 0.0)
		ax = *x;
	else
		ax = -*x;
	if (*y >= 0.0)
		ay = *y;
	else
		ay = -*y;
	*y = 2.0 * ax * ay + cy;
	*x = (xx - yy) + cx;
	if (*x < 0.0)
		*x = -*x;
	if (*y < 0.0)
		*y = -*y;
}

int	burning_ship_iter(double cx, double cy)
{
	const int	max_it = 128;
	double		x;
	double		y;
	int			i;

	x = 0.0;
	y = 0.0;
	i = 0;
	while (i < max_it)
	{
		if ((x * x + y * y) > 4.0)
			break ;
		burning_step(&x, &y, cx, cy);
		i++;
	}
	return (i);
}
