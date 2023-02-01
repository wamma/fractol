/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:12:02 by hyungjup          #+#    #+#             */
/*   Updated: 2023/02/01 16:44:06 by hyungjup         ###   ########.fr       */
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

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_image
{
	void	*ptr;
	int		*buff;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	t_image		*img;
	int			set;
	int			type;
	int			color;
	int			iter_max;
	double		zoom;
	t_complex	center;
	double		x_max;
	double		x_min;
	double		y_max;
	double		y_min;
	int			iter;
	t_complex	julia;
}	t_fractol;

/*main.c*/
void	image_init(t_fractol *f);
/*mandelbrot.c*/
int		ft_mandelbrot(t_fractol *f, t_complex center);
/*fractol_draw.c*/
void	draw(t_fractol *f);
int		ft_error(char *err);

#endif