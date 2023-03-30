/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:57:10 by hyungjup          #+#    #+#             */
/*   Updated: 2023/03/30 16:57:12 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_key_move(t_fractol *f, int keycode)
{
	if (keycode == KEY_LEFT)
	{
		f->x_min = f->x_min + f->zoom;
		f->x_max = f->x_max + f->zoom;
		draw(f);
	}
	else if (keycode == KEY_RIGHT)
	{
		f->x_min = f->x_min - f->zoom;
		f->x_max = f->x_max - f->zoom;
		draw(f);
	}
	else if (keycode == KEY_UP)
	{
		f->y_min = f->y_min + f->zoom;
		f->y_max = f->y_max + f->zoom;
		draw(f);
	}
	else if (keycode == KEY_DOWN)
	{
		f->y_min = f->y_min - f->zoom;
		f->y_max = f->y_max - f->zoom;
		draw(f);
	}
}

int	ft_key_hook(t_fractol *f, int keycode)
{
	if (keycode == KEY_ESC)
	{
		free(f->img);
		exit(0);
	}
	else if (keycode == KEY_ENTER)
	{
		f->color += 123456;
		ft_draw(f);
	}
	else
		ft_key_move(f, keycode);
	return (1);
}
