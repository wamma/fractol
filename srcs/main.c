/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:25:30 by hyungjup          #+#    #+#             */
/*   Updated: 2023/03/30 17:12:22 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	press_esc(int keycode, t_fractol *f)
{
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int	mouse_wheel(int keycode, int x, int y, t_fractol *f)
{
	if (keycode == MOUSE_SCROLL_UP || keycode == MOUSE_SCROLL_DOWN)
	{
		f->mouse.x = 
	}
}

int	ft_check_type(int ac, char **av)
{
	if ((ac != 2 && ac != 4) || (ac == 2 && \
	!ft_check_equal(av[1], "Mandelbrot")))
		ft_error("please write \"Mandelbrot\" or \"Julia\"");
	if (ft_check_equal(av[1], "Mandelbrot"))
		return (1);
	else if (ft_check_equal(av[1], "Julia"))
		return (2);
	else
		return (3);
}

int	fractol_init(t_fractol *f, t_image *img)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	img->img_ptr = mlx_new_image(f->mlx, WIN_WIDTH, WIN_HEIGHT);
	img->data_ptr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel, \
	&img->line_length, &img->endian);
	if (!f->mlx || !f->win || !img->img_ptr || !img->data_ptr)
	{
		ft_error("Mlx Init Error");
		return (0);
	}
	f->center.x = 0;
	f->center.y = 0;
	f->pixel = WIN_WIDTH / 4;
	f->width_length.x = WIN_WIDTH / f->pixel;
	f->width_length.y = WIN_HEIGHT / f->pixel;
	return (1);
}

int	main(int ac, char **av)
{
	t_fractol	f;

	f.type = ft_check_type(ac, av);
	if (!fractol_init(&f, &f.img) || !f.type)
		return (0);
	draw(&f);
	mlx_put_image_to_window(f.mlx, f.win, f.img.img_ptr, 0, 0);
	mlx_key_hook(f.win, press_esc, 0);
	mlx_hook(f.win, MOUSE_SCROLL_UP, MOUSE_LEFT_BUTTON, mouse_wheel, 0);
	mlx_loop(f.mlx);
	return (0);
}
