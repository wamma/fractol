/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:25:30 by hyungjup          #+#    #+#             */
/*   Updated: 2023/01/31 18:38:32 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mlx_win_init(t_fractol *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	f->img = mlx_new_image(f->mlx, WIN_WIDTH, WIN_HEIGHT);
	f->addr = mlx_get_data_addr(f->img, f->bpp, \
		f->line_len, f->endian);
	f->mask = 0x00F0F0F0;
	f->color = 0x000000FF;
}

void	fractol_init(t_fractol *f, char **av)
{
	if (ft_strncmp(av[1], "mandelbrot", 10) == 0)
		mandelbrot_init(f);
	else if (ft_strncmp(av[1], "julia", 5) == 0)
		f->type = 1;
	else
	{
		ft_putendl_fd("Please enter valid arguments \"mandelbrot\", \"julia\"", 2);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_fractol	*f;

	if (ac == 2)
	{
		if ((fractol_init(av, &f) == 0))
			return (0);
		mlx_win_init(f);
		fractol_init(f, av);
		mlx_loop(f->mlx);
	}
	else
		ft_putendl_fd("Please enter valid arguments \"mandelbrot\", \"julia\"", 2);
}
