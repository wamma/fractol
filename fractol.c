/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:25:30 by hyungjup          #+#    #+#             */
/*   Updated: 2023/01/30 16:06:47 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_win_init(t_fractol *f, t_img *img)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	img->img_ptr = mlx_new_image(f->mlx, WIN_WIDTH, WIN_HEIGHT);
	img->data_ptr = mlx_get_data_addr(img->img_ptr, &img->bpp, \
		&img->size_len, &img->endian);
	f->center.x = 0;
	f->center.y = 0;
	f->pixel = WIN_WIDTH / 4;
	f->width_len.x = WIN_WIDTH / f->pixel;
	f->width_len.y = WIN_HEIGHT / f->pixel;
}

int	fractol_compare(char **av, t_fractol *f)
{
	if (ft_strncmp(av[1], "mandelbrot", 10) == 0)
		f->fract_flag = 0;
	else if (ft_strncmp(av[1], "julia", 5) == 0)
		f->fract_flag = 1;
	else
	{
		ft_putendl_fd("Please enter valid arguments \"mandelbrot\", \"julia\"", 2);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_fractol	f;

	if (ac == 2)
	{
		if ((fractol_compare(av, &f) == 0))
			return (0);
		mlx_win_init(&f, &f.img);
		draw_frac(&f);
		mlx_put_image_to_window(f.mlx, f.win, f.img.img_ptr, 0, 0);
		mlx_key_hook(f.win, press_esc, 0);
		// mlx_hook(f.win, );
		mlx_loop(f.mlx);
	}
	else
		ft_putendl_fd("Please enter valid arguments \"mandelbrot\", \"julia\"", 2);
}
