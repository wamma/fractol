/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:30:05 by hyungjup          #+#    #+#             */
/*   Updated: 2023/02/06 15:01:36 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	color++;
	dst = img->ptr + \
	(y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = 0xFFFFFFFF;
}

void	coloring_pixel(t_fractol *f, t_complex c, int x, int y)
{
	int	ret;

	if (f->type == 1)
	{
		ret = ft_mandelbrot(c);
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
	t_complex	c;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			c.x = f->center.x + (double)x / f->pixel - f->w_l.x / 2;
			c.y = f->center.y + (double)y / f->pixel - f->w_l.y / 2;
			coloring_pixel(f, c, x, y);
			y++;
		}
		x++;
	}
}
