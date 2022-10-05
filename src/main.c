/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:28:04 by ksadiku           #+#    #+#             */
/*   Updated: 2022/09/13 10:51:14 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error(char *message)
{
	ft_putendl(message);
	exit(1);
}

void	init_img(t_data *d)
{
	d->img.image = mlx_new_image(d->arg.mlx, WIDTH, HEIGHT);
	if (!d->img.image)
		error("Creating new image failed!");
	d->img.addr = mlx_get_data_addr(d->img.image, &d->img.bpp,
			&d->img.sizeline, &d->img.endian);
	if (!d->img.addr)
		error("Getting the Image address failed!");
}

static void	mlx_hooks(t_data *data)
{
	mlx_hook(data->arg.win, 4, 0, mouse_hook, data);
	mlx_hook(data->arg.win, 2, 0, hot_key, data);
	mlx_hook(data->arg.win, 6, (1L << 4), mouse_move, data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		error("Usage: ./fractol [Mandelbrot] [Julia] [Burningship]");
	data.arg.mlx = mlx_init();
	if (data.arg.mlx == NULL)
		error("There was an error with mlx pointer. Try again.");
	data.arg.win = mlx_new_window(data.arg.mlx, WIDTH, HEIGHT, argv[1]);
	if (data.arg.win == NULL)
		error("There was an error creating a window. Try again.");
	init_img(&data);
	data.menu = 1;
	data.thread = 0;
	check_fractol(&data, argv[1]);
	mlx_hooks(&data);
	mlx_loop(data.arg.mlx);
	return (0);
}
