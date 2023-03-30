/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:30:05 by hyungjup          #+#    #+#             */
/*   Updated: 2023/03/30 17:07:10 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data_ptr + \
	(y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	coloring_pixel(t_fractol *f, t_complex p, int x, int y)
{
	int	ret;

	if (f->type == 1)
	{
		ret = ft_mandelbrot(p);
		if (ret != ITER_MAX)
			my_mlx_pixel_put(&(f->img), x, y, \
			(255 - ret / 10) * 0x10000 + 10 * ret * 0x100 + 20 * (ret / 20));
		else if (ret == ITER_MAX)
			my_mlx_pixel_put(&f->img, x, y, 0);
	}
	// else if (f->type == 2)
	// {
	// 	ret = ft_
	// }
}

void	draw(t_fractol *f)
{
	int			x;
	int			y;
	t_complex	p;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			p.x = f->center.x + (double)x / \
			f->pixel - f->width_length.x / 2;
			p.y = f->center.y + (double)y / \
			f->pixel - f->width_length.y / 2;
			coloring_pixel(f, p, x, y);
			y++;
		}
		x++;
	}
}
