/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:02:19 by hyungjup          #+#    #+#             */
/*   Updated: 2023/01/18 18:06:34 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fract_init(t_fractol *f)
{
	if (f->fract == 0)
		mandelbrot_init(f);
	else if (f->fract == 1)
		julia_init(f);
	fract_calculate(f);
}

void	mlx_win_init(t_fractol *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	f->img = mlx_new_image(f->mlx, WIN_WIDTH, WIN_HEIGHT);
	f->img_ptr = mlx_get_data_addr(f->img_ptr, &f->bpp,
			&f->size_len, &f->endian);
}

int	fract_compare(char **av, t_fractol *f)
{
	if (ft_strncmp(av[1], "mandelbrot", 10) == 0)
		f->fract = 0;
	else if (ft_strncmp(av[1], "julia", 5) == 0)
		f->fract = 1;
	else
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_fractol	*f;

	f = (t_fractol *)malloc(sizeof(t_fractol));
	if (!f)
		return (NULL);
	if (ac == 2)
	{
		mlx_win_init(f);
		if (fract_compare(av, f) == 0)
			return (NULL);
		fract_init(f);
		mlx_hook(f->win, 6,)
	}
}
