/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:25:30 by hyungjup          #+#    #+#             */
/*   Updated: 2023/02/01 16:32:04 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_init(t_fractol *f)
{
	f->zoom = 0.05;
	f->color = 0x228B22;
	if (f->type == 1)
	{
		f->x_max = 1.5;
		f->x_min = -2.5 ;
		f->y_max = 2.0 ;
		f->y_min = -2.0 ;
	}
	else
	{
		f->x_max = 2.0;
		f->x_min = -2.0 ;
		f->y_max = 2.0 ;
		f->y_min = -2.0 ;
	}
}

int	mlx_win_init(t_fractol *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	f->img = (t_image *)malloc(sizeof(t_image));
	if (!f->img)
		return (0);
	fractol_init(f);
	//mlx_key_hook(f->win, ft_key_hook, f);
	return (1);
}

int	fractol_set_type(t_fractol *f, char **av)
{
	if (ft_strncmp(av[1], "mandelbrot", 11) == 0)
		f->type = 1;
	else if (ft_strncmp(av[1], "julia", 6) == 0)
		f->type = 2;
	else if (ft_strncmp(av[1], "burningship", 12) == 0)
		f->type = 3;
	else
	{
		ft_putendl_fd("Please enter valid arguments \"mandelbrot\", \"julia\", \
		 \"burningship\"", 2);
		return (0);
	}
	return (1);
}

void	image_init(t_fractol *f)
{
	f->img->ptr = mlx_new_image(f->mlx, WIN_WIDTH, WIN_HEIGHT);
	f->img->buff = (int *)mlx_get_data_addr(f->img->ptr, \
	&f->img->bpp, &f->img->line_len, &f->img->endian);
}

int	main(int ac, char **av)
{
	t_fractol	f;

	if (ac == 2)
	{
		if ((fractol_set_type(&f, av)))
		{
			if (!mlx_win_init(&f))
				ft_error("SOMETHING WHRONG WITH MLX INIT");
			image_init(&f);
			draw(&f);
			mlx_loop(f.mlx);
		}
	}
	else
		ft_putendl_fd("Please enter valid arguments \"mandelbrot\", \"julia\"", 2);
}
