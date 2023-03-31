/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:30:05 by hyungjup          #+#    #+#             */
/*   Updated: 2023/03/31 16:50:48 by hyungjup         ###   ########.fr       */
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
	int	red;
	int	green;
	int	blue;
	int	color;

	if (f->type == 1)
		ret = ft_mandelbrot(p);
	else if (f->type == 2)
		ret = ft_julia(p, &f->julia);
	if (ret != ITER_MAX)
	{
		red = (ret * 10) % 255;
		green = (ret * 30) % 255;
		blue = (ret * 50) % 255;
		color = (red * 0x10000) + (green * 0x100) + blue;
	}
	else
		color = 0;
	my_mlx_pixel_put(&f->img, x, y, color);
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
