/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:47:14 by bavirgil          #+#    #+#             */
/*   Updated: 2025/10/03 18:06:30 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>     /* malloc, free, exit */
# include <unistd.h>     /* read, write, close */
# include <string.h>     /* strerror, strcmp-like */
# include <stdio.h>      /* perror */
# include <math.h>       /* libm functions, fabs */
# include <sys/time.h>   /* gettimeofday */

# include <X11/X.h>      /* event & mask constants for mlx_hook */
# include <X11/keysym.h> /* key symbols (e.g., XK_Escape) */

# include "mlx.h"        /* MiniLibX */
# include "ft_printf.h"  /* your printf */

/* ===== Window size ===== */
# define WIDTH 800
# define HEIGHT 800

/* ===== Types ===== */
typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	t_img	img;

	int		fractal_type; /* 0=mandelbrot, 1=julia, 2=burning ship */
	double	zoom;
	double	offset_x;
	double	offset_y;

	double	julia_re;
	double	julia_im;
}	t_fractol;

/* ===== Prototypes/WIP ===== */
/* main / flow */
int		render(t_fractol *f);
void	install_hooks(t_fractol *f);

/* hooks */
int		key_press(int keycode, t_fractol *f);
int		mouse_hook(int button, int x, int y, t_fractol *f);
int		close_btn(t_fractol *f);

/* color */
unsigned int	color_smooth(int it, int max_it, double zx, double zy);

/* complex ops */
t_complex	c_add(t_complex a, t_complex b);
t_complex	c_sq(t_complex z);
double		c_abs2(t_complex z);

/* fractal iteration cores */
int		mandelbrot_iter(double cx, double cy);
int		julia_iter(double zx, double zy, double cre, double cim);
int		burning_ship_iter(double cx, double cy);

/* utils */
void		put_pixel(t_img *img, int x, int y, unsigned int color);
void		perr(const char *msg);
int			clean_exit(t_fractol *f, int err);
void		safe_quit(t_fractol *f);
void		print_usage_julia(void);
void		print_help(void);
int			parse_double(const char *s, double *out);
int			ft_strcmp(const char *a, const char *b);

#endif
