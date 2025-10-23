/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:28:30 by bavirgil          #+#    #+#             */
/*   Updated: 2025/10/03 18:06:33 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_defaults(t_fractol *f)
{
	f->fractal_type = 0;
	f->zoom = 1.0;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
	f->julia_re = -0.8;
	f->julia_im = 0.156;
}

static int	parse_args(int ac, char **av, t_fractol *f)
{
	init_defaults(f);
	if (ac < 2)
		return (print_help(), 0);
	if (!ft_strcmp(av[1], "mandelbrot"))
		f->fractal_type = 0;
	else if (!ft_strcmp(av[1], "julia"))
	{
		f->fractal_type = 1;
		if (ac >= 4)
		{
			if (!parse_double(av[2], &f->julia_re)
				|| !parse_double(av[3], &f->julia_im))
				return (print_usage_julia(), 0);
		}
	}
	else if (!ft_strcmp(av[1], "burning"))
		f->fractal_type = 2;
	else
		return (print_help(), 0);
	return (1);
}

static int	init_mlx(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		return (perr("mlx_init failed"), 0);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fractol");
	if (!f->win)
		return (perr("mlx_new_window failed"), 0);
	f->img.img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img.img)
		return (perr("mlx_new_image failed"), 0);
	f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bpp,
			&f->img.line_len, &f->img.endian);
	if (!f->img.addr)
		return (perr("mlx_get_data_addr failed"), 0);
	return (1);
}

int	main(int ac, char **av)
{
	t_fractol	f;

	if (!parse_args(ac, av, &f))
		return (EXIT_FAILURE);
	if (!init_mlx(&f))
		return (clean_exit(&f, 1));
	render(&f);
	install_hooks(&f);
	mlx_loop(f.mlx);
	return (clean_exit(&f, 0));
}
