/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:33:02 by bavirgil          #+#    #+#             */
/*   Updated: 2025/10/03 18:06:29 by bavirgil         ###   ########.fr       */
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
#ifdef __linux__
	if (f->mlx)
		mlx_destroy_display(f->mlx);
#endif
	if (f->mlx)
		free(f->mlx);
	return (err ? EXIT_FAILURE : EXIT_SUCCESS);
}

void	safe_quit(t_fractol *f)
{
	clean_exit(f, 0);
	exit(0);
}

void	print_usage_julia(void)
{
	ft_printf("Usage: ./fractol julia <re> <im>\n");
}

void	print_help(void)
{
	ft_printf("Usage:\n");
	ft_printf("  ./fractol mandelbrot\n");
	ft_printf("  ./fractol julia <re> <im>\n");
	ft_printf("  ./fractol burning\n");
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

int	ft_strcmp(const char *a, const char *b)
{
	size_t	i;

	if (!a || !b)
		return (a != b);
	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		++i;
	return ((unsigned char)a[i] - (unsigned char)b[i]);
}
