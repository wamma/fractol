/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:12:02 by hyungjup          #+#    #+#             */
/*   Updated: 2023/01/30 14:24:23 by hyungjup         ###   ########.fr       */
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
# define ITER_MAX		255

typedef struct s_double_xy
{
	double	x;
	double	y;
}	t_double_xy;

typedef struct s_img
{
	void	*img_ptr;
	char	*data_ptr;
	int		bpp;
	int		size_len;
	int		endian;
}	t_img;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	t_img		img;
	int			fract_flag;
	double		pixel;
	t_double_xy	width_len;
	t_double_xy	center;
	t_double_xy	mouse;
}	t_fractol;

/*mandelbrot.c*/
void	mandelbrot_init(t_fractol *f);
/*julia.c*/
int		julia_mouse_move(int x, int y, t_fractol *f);
/*fractol_utils.c*/
void	put_colorpixel(t_fractol *f, t_double_xy dot, int i, int j);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_frac(t_fractol *f);
int		press_esc(int keycode);

#endif