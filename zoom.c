/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:54:48 by hyungjup          #+#    #+#             */
/*   Updated: 2023/01/26 13:57:27 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_fractol *f, double x, double y, double zoom)
{
	double	xx;
	double	yy;

	xx = ((x / WIN_WIDTH) * (f->end_x - f->start_x)) + f->start_x;
	yy = ((y / WIN_HIGHT) * (f->end_y - f->start_y)) + f->start_y;
	f->start_x = xx + ((f->start_x - xx) * zoom);
	f->start_y = yy + ((f->start_y - yy) * zoom);
	f->end_y = yy + ((f->end_y - yy) * zoom);
	f->end_x = xx + ((f->end_x - xx) * zoom);
	if (f->max <= 120)
		f->max += 2;
}
