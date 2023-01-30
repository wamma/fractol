/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:45:02 by hyungjup          #+#    #+#             */
/*   Updated: 2023/01/26 13:39:47 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_init(t_fractol *f)
{
	f->it_max = 50;
}

int	julia_mouse_move(int x, int y, t_fractol *f)
{
	if (f->fract == 1 && f->julia_mouse == 1)
	{
		f->c_i = x * 2;
		f->c_r = y * 2 - 800;
		fractol_calculate(f);
	}
	return (0);
}
