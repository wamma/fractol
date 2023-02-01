/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:14:28 by hyungjup          #+#    #+#             */
/*   Updated: 2023/02/01 16:43:54 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mandelbrot(t_fractol *f, t_complex center)
{
	t_complex	z;
	double		tmp;

	z.x = center.x;
	z.y = center.y;
	f->iter = 0;
	while (f->iter < ITER_MAX && (z.x * z.x) + (z.y * z.y) < 4)
	{
		tmp = z.x * z.x - z.y * z.y + center.x;
		z.y = 2 * z.x * z.y + center.y;
		z.x = tmp;
		f->iter++;
	}
	return (f->iter);
}
