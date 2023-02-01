/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:30:05 by hyungjup          #+#    #+#             */
/*   Updated: 2023/02/01 16:46:10 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fractol *f, int x, int y, int color)
{
	char	*dst;

	dst = f->img->ptr + \
	(y * f->img->line_len + x * (f->img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	coloring_pixel(t_fractol *f, int x, int y)
{
	int	pixel;
	int	color;

	color = 0;
	if (f->iter != ITER_MAX)
		color = 1;
	pixel = (y * WIN_WIDTH + x);
	f->img->buff[pixel] = ((f->iter * f->color) + 0x228B22) * color;
}

void	draw(t_fractol *f)
{
	int	x;
	int	y;
	int	val;

	x = 0;
	image_init(f);
	while (x < WIN_WIDTH)
	{
		y = 0;
		f->center.x = f->x_min + x * ((f->x_max - f->x_min) / WIN_WIDTH);
		while (y < WIN_HEIGHT)
		{
			f->center.y = f->y_min + y * ((f->y_max - f->y_min) / WIN_HEIGHT);
			if (f->type == 1)
			{
				val = ft_mandelbrot(f, f->center);
				if (val != ITER_MAX)
					my_mlx_pixel_put(f, x, y, \
					20 * (val / 16) * 0x10000 + 16 * val * 0x100 + (255 - val / 16));
			}
			// else if (f->type == 2)
			// 	ft_julia(f->center, f);
			y++;
			coloring_pixel(f, x, y);
		}
		x++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img->ptr, 0, 0);
	// mlx_destroy_image(f->mlx, f->img->ptr);
}
