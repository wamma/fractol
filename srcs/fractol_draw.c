/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:30:05 by hyungjup          #+#    #+#             */
/*   Updated: 2023/03/28 20:51:13 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->ptr + \
	(y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	coloring_pixel(t_fractol *f, t_complex center, int x, int y)
{
	int	ret;

	if (f->type == 1)
	{
		ret = ft_mandelbrot(center);
		if (ret != ITER_MAX)
			my_mlx_pixel_put(&(f->img), x, y, \
			(255 - ret / 10) * 0x10000 + 10 * ret * 0x100 + 20 * (ret / 20));
		if (ret == ITER_MAX)
			my_mlx_pixel_put(&f->img, x, y, 0);
	}
}

void	draw(t_fractol *f)
{
	int			x;
	int			y;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			f->center.x = f->center.x + (double)x / \
			f->pixel - f->width_length.x / 2;
			f->center.y = f->center.y + (double)y / \
			f->pixel - f->width_length.y / 2;
			coloring_pixel(f, f->center, x, y);
			y++;
		}
		x++;
	}
}
