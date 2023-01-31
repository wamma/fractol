/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:12:02 by hyungjup          #+#    #+#             */
/*   Updated: 2023/01/31 17:06:29 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

# define WIN_WIDTH		800
# define WIN_HEIGHT		800
# define ZOOM_RATE		1.2

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		type;
	int		color;
	int		mask;
	int		x;
	int		y;
	int		iter;
	int		iter_max;
	double	zoom;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	x_set;
	double	y_set;
}	t_fractol;
/*mandelbrot.c*/
void	mandelbrot_init(t_fractol *f);
/*julia.c*/
int		julia_mouse_move(int x, int y, t_fractol *f);
/*fractol_utils.c*/

#endif