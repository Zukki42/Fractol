/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:28:40 by bavirgil          #+#    #+#             */
/*   Updated: 2025/10/27 12:12:58 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	iterate_point(t_fractol *f, double cx, double cy)
{
	if (f->fractal_type == 0)
		return (mandelbrot_iter(cx, cy));
	else if (f->fractal_type == 1)
		return (julia_iter(cx, cy, f->julia_re, f->julia_im));
	return (burning_ship_iter(cx, cy));
}

static void	render_row(t_fractol *f, int y, double inv_w, double inv_h)
{
	const int	max_it = 128;
	double		cy;
	double		cx;
	int			x;
	int			it;

	cy = ((double)y - (double)HEIGHT * 0.5) * inv_h + f->offset_y;
	cx = (0.0 - (double)WIDTH * 0.5) * inv_w + f->offset_x;
	x = 0;
	while (x < WIDTH)
	{
		it = iterate_point(f, cx, cy);
		put_pixel(&f->img, x, y, color_smooth(it, max_it, cx, cy));
		cx += inv_w;
		x++;
	}
}

int	render(t_fractol *f)
{
	const double	inv_w = 1.0 / (0.5 * f->zoom * (double)WIDTH);
	const double	inv_h = 1.0 / (0.5 * f->zoom * (double)HEIGHT);
	int				y;

	y = 0;
	while (y < HEIGHT)
	{
		render_row(f, y, inv_w, inv_h);
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
	return (0);
}
