/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:12:02 by hyungjup          #+#    #+#             */
/*   Updated: 2023/03/27 20:50:10 by hyungjup         ###   ########.fr       */
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
	char	*data_ptr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	int			type;
	int			pixel;
	t_image		img;
	t_complex	center;
	t_complex	w_l;
	t_complex	julia;
}	t_fractol;

/*fractol_type.c*/
int		ft_mandelbrot(t_complex c);
/*fractol_draw.c*/
void	draw(t_fractol *f);
int		ft_error(char *err);

#endif