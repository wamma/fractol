/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:30:05 by hyungjup          #+#    #+#             */
/*   Updated: 2023/01/30 16:06:43 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data_ptr + \
	(y * img->size_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

// void	put_colorpixel(t_fractol *f, t_double_xy dot, int i, int j)
// {
// 	int	value;

// 	if (f->fract_flag == 1)
// 	{
// 		value = mandelbrot(dot);
// 		if (value != ITER_MAX)
			
// 	}
// }

void	draw_frac(t_fractol *f)
{
	int			i;
	int			j;
	t_double_xy	dot;

	i = 0;
	while (i < WIN_WIDTH)
	{
		j = 0;
		while (j < WIN_HEIGHT)
		{
			dot.x = f->center.x + (double)i / f->pixel - f->width_len.x / 2;
			dot.y = f->center.y + (double)j / f->pixel - f->width_len.y / 2;
			put_colorpixel(f, dot, i, j);
			j++;
		}
		i++;
	}
}

int	press_esc(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}
