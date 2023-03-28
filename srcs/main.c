/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:25:30 by hyungjup          #+#    #+#             */
/*   Updated: 2023/03/28 20:48:27 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_check_type(int ac, char **av)
{
	if ((ac != 2 && ac != 4) || (ac == 2 && \
	!ft_strncmp(av[1], "Mandelbrot", 10)) || \
	(ac == 4 && !ft_strncmp(av[1], "Julia", 5)))
		ft_error("Argument Error");
	if (ft_strncmp(av[1], "Mandelbrot", 10))
		return (1);
	else if (ft_strncmp(av[1], "Julia", 10))
		return (2);
}

static int	fractol_init(t_fractol *f, t_image *img, char **av)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	img->ptr = mlx_new_image(f->mlx, WIN_WIDTH, WIN_HEIGHT);
	img->data_ptr = mlx_get_data_addr(img->ptr, &img->bits_per_pixel, \
	&img->line_length, &img->endian);
	if (!f->mlx || !f->win || !img->ptr || !img->data_ptr)
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
	if (!fractol_init(&f, &f.img, av) || !f.type)
		return (0);
	draw(&f);
	return (0);
}
