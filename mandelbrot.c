/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:14:28 by hyungjup          #+#    #+#             */
/*   Updated: 2023/01/27 14:40:51 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_init(t_fractol *f)
{
	f->x1 = -3.3;
	f->y1 = -1.6;
	f->zoom = 300;
	f->color = 265;
}

void	mandelbrot_cal(t_fractol *f)
{
	f->c_real = f->x / f->zoom + f->x1;
	f->c_imag = f->y / f->zoom + f->y1;
	f->zn_real = 0;
	f->zn_imag = 0;
	f->it = 0;
	while (f->it < ITER_MAX && f->zn_real * \
	f->zn_real + f->zn_imag * f->zn_imag < 4)
	{
		f->tmp = f->zn_real;
		f->zn_real = f->zn_real * f->zn_real - \
		f->zn_imag * f->zn_imag + f->c_real;
		f->zn_imag = 2 * f->zn_real * f->zn_imag + f->c_imag;
		f->it++;
	}
	if (f->it == ITER_MAX)
		ft_pixel_to_image(f, f->x, f->y, 0x000000);
	else
		ft_pixel_to_image(f, f->x, f->y, (f->color * f->it));
}

void	*mandelbrot(void *tab)
{
	t_fractol	*f;

	f = (t_fractol *)tab;
	f->x = 0;
	while (f->x < WIN_WIDTH)
	{
		while (f->y < f->y_max)
		{
			mandelbrot_cal(f);
			f->y++;
		}
		f->x++;
	}
	return (f);
}
