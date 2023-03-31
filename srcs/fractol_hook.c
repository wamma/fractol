/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:57:10 by hyungjup          #+#    #+#             */
/*   Updated: 2023/03/31 20:46:25 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	press_esc(int keycode)
{
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int	mouse_wheel(int keycode, int x, int y, t_fractol *f)
{
	if (keycode == MOUSE_SCROLL_UP || keycode == MOUSE_SCROLL_DOWN)
	{
		f->mouse.x = (double)x / f->pixel - f->width_length.x / 2;
		f->mouse.y = (double)y / f->pixel - f->width_length.y / 2;
		if (keycode == MOUSE_SCROLL_UP)
		{
			f->center.x += f->mouse.x * (1 - 1 / ZOOM_RATE);
			f->center.y += f->mouse.y * (1 - 1 / ZOOM_RATE);
			f->pixel /= ZOOM_RATE;
			f->width_length.x *= ZOOM_RATE;
			f->width_length.y *= ZOOM_RATE;
		}
		else
		{
			f->center.x -= -f->mouse.x * (ZOOM_RATE - 1);
			f->center.y -= -f->mouse.y * (ZOOM_RATE - 1);
			f->pixel *= ZOOM_RATE;
			f->width_length.x /= ZOOM_RATE;
			f->width_length.y /= ZOOM_RATE;
		}
	}
	draw(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img.img_ptr, 0, 0);
	return (0);
}
