/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:14:28 by hyungjup          #+#    #+#             */
/*   Updated: 2023/01/31 18:55:21 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_init(t_fractol *f)
{
	f->type = 0;
	f->zoom = 300;
	f->iter_max = 255;
	f->x_set = -3.1;
	f->y_set = 2.5;
}

void	pixel_draw(t_fractol *f, int color)
{
	char	*dst;

	dst = f->addr + (f->y * f->line_len + f->x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}

void	mandelbrot_calculate(t_fractol *f)
{
	double	z_tmp;

	f->c_r = f->x / f->zoom + f->x_set;
	f->c_i = f->y / f->zoom + f->y_set;
	f->z_r = 0;
	f->z_i = 0;
	f->iter = 0;
	while (f->iter < f->iter_max && f->z_r * f->z_r + f->z_i * f->z_i < 4)
	{
		z_tmp = f->z_r;
		f->z_r = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
		f->z_i = 2 * f->z_i * z_tmp + f->c_i;
		f->iter++;
	}
	if (f->iter == f->iter_max)
		pixel_draw(f, 0x000000);
	else
		pixel_draw(f, (f->color * f->iter));
}

void	mandelbrot(t_fractol *f)
{

}
