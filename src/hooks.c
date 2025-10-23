/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:29:11 by bavirgil          #+#    #+#             */
/*   Updated: 2025/10/03 18:06:34 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_at(t_fractol *f, double mx, double my, double factor)
{
	double	x = (mx - WIDTH / 2.0) / (0.5 * f->zoom * WIDTH) + f->offset_x;
	double	y = (my - HEIGHT / 2.0) / (0.5 * f->zoom * HEIGHT) + f->offset_y;
	double	nx;
	double	ny;

	f->zoom *= factor;
	nx = (mx - WIDTH / 2.0) / (0.5 * f->zoom * WIDTH);
	ny = (my - HEIGHT / 2.0) / (0.5 * f->zoom * HEIGHT);
	f->offset_x = x - nx;
	f->offset_y = y - ny;
}

int	key_press(int keycode, t_fractol *f)
{
	if (keycode == XK_Escape)
		safe_quit(f);
	return (0);
}

/* Linux: mouse button 4 = scroll up, 5 = scroll down */
int	mouse_hook(int button, int x, int y, t_fractol *f)
{
	if (button == 4)
		zoom_at(f, x, y, 1.2);
	else if (button == 5)
		zoom_at(f, x, y, 1.0 / 1.2);
	else
		return (0);
	render(f);
	return (0);
}

int	close_btn(t_fractol *f)
{
	safe_quit(f);
	return (0);
}

void	install_hooks(t_fractol *f)
{
	mlx_hook(f->win, KeyPress, KeyPressMask, key_press, f);
	mlx_mouse_hook(f->win, mouse_hook, f);
	mlx_hook(f->win, DestroyNotify, StructureNotifyMask, close_btn, f);
}
