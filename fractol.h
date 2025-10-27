/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:47:14 by bavirgil          #+#    #+#             */
/*   Updated: 2025/10/24 14:25:51 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "ft_printf.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	t_img		img;

	int			fractal_type;
	double		zoom;
	double		offset_x;
	double		offset_y;

	double		julia_re;
	double		julia_im;
}				t_fractol;

int				render(t_fractol *f);
void			install_hooks(t_fractol *f);

int				key_press(int keycode, t_fractol *f);
int				mouse_hook(int button, int x, int y, t_fractol *f);
int				close_btn(t_fractol *f);

unsigned int	color_smooth(int it, int max_it, double zx, double zy);

t_complex		c_add(t_complex a, t_complex b);
t_complex		c_sq(t_complex z);
double			c_abs2(t_complex z);

int				mandelbrot_iter(double cx, double cy);
int				julia_iter(double zx, double zy, double cre, double cim);
int				burning_ship_iter(double cx, double cy);

void			put_pixel(t_img *img, int x, int y, unsigned int color);
void			perr(const char *msg);
int				clean_exit(t_fractol *f, int err);
void			safe_quit(t_fractol *f);
void			print_usage_julia(void);
void			print_help(void);
int				parse_double(const char *s, double *out);
int				ft_strcmp(const char *a, const char *b);

#endif
