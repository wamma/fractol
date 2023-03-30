/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:14:28 by hyungjup          #+#    #+#             */
/*   Updated: 2023/03/30 17:02:54 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_mandelbrot(t_complex center)
{
	t_complex	z;
	double		tmp;
	int			i;

	z.x = center.x;
	z.y = center.y;
	i = 0;
	while ((z.x * z.x) + (z.y * z.y) <= 4 && i < ITER_MAX)
	{
		tmp = (z.x * z.x - z.y * z.y) + center.x;
		z.y = (2 * z.x * z.y) + center.y;
		z.x = tmp;
		i++;
	}
	return (i);
}

// int	ft_julia(t_complex center)
// {
// 	t_complex	z;
// 	double		tmp;
// 	int			i;
// }
