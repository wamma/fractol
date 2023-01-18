/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:12:02 by hyungjup          #+#    #+#             */
/*   Updated: 2023/01/18 17:44:25 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17
# define X_EVENT_MOUSE_PRESS	4
# define X_EVENT_MOUSE_MOTION	6
# define WIN_WIDTH				800
# define WIN_HEIGHT				600
# define KEY_ESC				53
# define ITER_MAX				100

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*img_ptr;
	int		color;
	int		endian;
	int		size_len;
	int		bpp;
	int		fract;
	int		julia_mouse;
	int		x;
	int		y;
	int		y_max;
	int		it;
	int		it_max;
	int		show_text;
	int		zoom;
	int		x1;
	int		y1;
	int		c_r;
	int		c_i;
	int		z_r;
	int		z_i;
	int		tmp;
}	t_fractol;

/*mandelbrot.c*/
void	mandelbrot_init(t_fractol *f);

#endif