/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:25:30 by hyungjup          #+#    #+#             */
/*   Updated: 2023/03/27 20:54:24 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_check_type(t_fractol *f, int ac, char **av)
{
	f->type = 0;
	if (ac >= 2)
	{
		if (ft_strcmp(av[1], "Mandelbrot") == 0)
			f->type = 1;
	}
	if (f->type == 0)
		ft_error("Error");
	return (f->set);
}

int	ft_mlx_init(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		return (0);
	f->win = mlx_new_window(f->mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	if (!f->win)
		return (0);
}

int	main(int ac, char **av)
{
	t_fractol	f;

	if (ft_check_type(&f, ac, av))
	{
		if (!ft_mlx_init(&f))
			ft_error("MLX Error");
	}
}
