/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:33:02 by bavirgil          #+#    #+#             */
/*   Updated: 2025/10/27 12:05:42 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_img *img, int x, int y, unsigned int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	perr(const char *msg)
{
	(void)msg;
	perror("fractol");
}

int	clean_exit(t_fractol *f, int err)
{
	if (f->img.img)
		mlx_destroy_image(f->mlx, f->img.img);
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
		free(f->mlx);
	if (err)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	safe_quit(t_fractol *f)
{
	exit(clean_exit(f, 0));
}

int	parse_double(const char *s, double *out)
{
	char	*end;
	double	v;

	v = strtod(s, &end);
	if (end == s || *end != '\0')
		return (0);
	*out = v;
	return (1);
}
