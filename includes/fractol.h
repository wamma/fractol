/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:12:02 by hyungjup          #+#    #+#             */
/*   Updated: 2023/03/31 20:46:40 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>

# define WIN_WIDTH			800
# define WIN_HEIGHT			800
# define ZOOM_RATE			1.2
# define ITER_MAX			250

# define KEY_ESC			53
# define MOUSE_LEFT_BUTTON	1
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_image
{
	void	*img_ptr;
	char	*data_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	int			type;
	double		pixel;
	t_image		img;
	t_complex	center;
	t_complex	julia;
	t_complex	width_length;
	t_complex	mouse;
}	t_fractol;

int		ft_error(char *err);
void	my_mlx_pixel_put(t_image *img, int x, int y, int color);
void	coloring_pixel(t_fractol *f, t_complex center, int x, int y);
void	draw(t_fractol *f);
int		ft_mandelbrot(t_complex center);
int		ft_julia(t_complex center, t_complex *julia);
int		ft_check_equal(const char *s1, const char *s2);
int		ft_strlen(char *str);
int		mouse_wheel(int keycode, int x, int y, t_fractol *f);
int		press_esc(int keycode);
void	ft_key_move(t_fractol *f, int keycode);
double	ft_atof(char *str);

#endif