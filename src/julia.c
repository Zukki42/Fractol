/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:29:51 by bavirgil          #+#    #+#             */
/*   Updated: 2025/10/11 04:11:07 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_iter(double zx, double zy, double cre, double cim)
{
	const int	max_it = 128;
	double		zx2;
	double		zy2;
	int			i;

	i = 0;
	while (i < max_it)
	{
		zx2 = zx * zx;
		zy2 = zy * zy;
		if (zx2 + zy2 > 4.0)
			break ;
		zy = 2.0 * zx * zy + cim;
		zx = zx2 - zy2 + cre;
		i++;
	}
	return (i);
}

