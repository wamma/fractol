/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:14:28 by hyungjup          #+#    #+#             */
/*   Updated: 2023/02/03 15:46:34 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mandelbrot(t_complex c)
{
	t_complex	z;
	double		tmp;
	int			i;

	z.x = c.x;
	z.y = c.y;
	i = 0;
	while (i < ITER_MAX && (z.x * z.x) + (z.y * z.y) < 4)
	{
		tmp = (z.x * z.x - z.y * z.y) + c.x;
		z.y = (2 * z.x * z.y) + c.y;
		z.x = tmp;
		i++;
	}
	return (i);
}
